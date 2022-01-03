ZTCG_CARD
{

    "NAME" "Wonky"
    "IMAGE" "S4C013_Wonky.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Fairy NPC"
    "COST" "730"

    TYPE_MOB
    {
        "LEVEL" "40"
        "ATTCK" "20"
        "HP" "40"
        "TEXT" "NPC Quest -- Your opponent has no monsters when your turn ends. Reward -- Return a monster of level 30 or less from your discard pile to your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "3"
        "TEXT" "Multi Spawn 30 -- Play any number of monsters with combined levels of 30 or less."
    }

    function onEndTurn(player)
        if getMobsOnTable(player,"ONLY_ADVSRY") == 0 then
            recoverCard(player, "DECK_HAND", "RECOVER_MOB", "LESSER", 30)
        end
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        editCardRegister(src, cardid, 0, 30, 0, nil)

        local deckHand = getPlayerDeck(player, "DECK_HAND")

        while true do
            local level = getCardRegister(src, cardid, 0)

            local card_list = getListFromDeck(deckHand)
            local spawn_list, not_empty = makeFilteredList(player,card_list,0,0,level,"TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
            if not not_empty then
                break
            end

            local card = menuCards(player,spawn_list,"Select a mob to spawn.","CARDLIST_PEEK")
            if card ~= 0 then
                local cardList = takeTargetCardFromDeck(card,deckHand)
                cardList = moveCardsFromListToDeck(cardList,deckHand,"TAKE_CARDID","PUT_BOTTOM",card)
                summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")

                local mobLevel = getBaseLevelFromCARD(getCARD(card))
                editCardRegister(src, cardid, 0, level - mobLevel, 0, nil)

                destroyList(spawn_list)
            else
                destroyList(spawn_list)
                break
            end
        end
    end

}
