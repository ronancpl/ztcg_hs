ZTCG_CARD
{

    "NAME" "Aura"
    "IMAGE" "S5C075_Aura.png"
    "TYPE" "MOB"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Human Zakum NPC"
    "COST" "630"

    TYPE_MOB
    {
        "LEVEL" "50"
        "ATTCK" "30"
        "HP" "40"
        "TEXT" "NPC Quest -- Have 3 or more cards in hand and attack with Aura. Reward -- Your opponent chooses a card at random in your hand and reveals it. If it's a Boss, put it on the bottom of your deck and take another turn after this one."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "0"
        "TEXT" "Boss Spawn -- Play a Boss."
    }

    function onEndTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        if getCardRegister(src, cardid, 0) > 0 then
            editCardRegister(src, cardid, 0,0,0,nil)
            doubleTurn(player)
        end
    end

    function onExecuteAttack(player)
        local src = getSourceCARD()

        local hand = getPlayerDeck(player, "DECK_HAND")
        local list, qty = getListFromDeck(hand)
        if qty >= 3 then
            local card = menuCards(not player,list,"Select a card.","CARDLIST_HIDE")
            revealCard(not player,"Opponent has card...",getCARD(card))

            if isBossCARD(getCARD(card)) then
                card = takeTargetCardFromDeck(player,card,hand)

                local deck = getPlayerDeck(player, "DECK_DECK")
                card = moveCardsFromListToDeck(player,card,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
                destroyList(card)

                local cardid = getCardIdFromCARD(src)
                editCardRegister(src, cardid, 0, 1, 0, null)
            end
        end
    end

    function onActivateCharacterAction(player)
        if not isBossOnPlayerTable(player) then
            local src = getSourceCARD()

            local deckHand = getPlayerDeck(player, "DECK_HAND")
            local card_list = getListFromDeck(deckHand)

            local boss_list, not_empty = makeFilteredList(player,card_list,0,0,"ZTCG_MAXVALUE","TYPE_BOS", "ELEM_ANY", "ZTCG_NIL")
            if not_empty then
                local menuCard = menuCards(player,boss_list,"Select a boss to spawn.","CARDLIST_PEEK")
                if menuCard ~= 0 then
                    menuCard = takeTargetCardFromDeck(player,menuCard,deckHand)
                    menuCard = moveCardsFromListToDeck(player,menuCard,deckHand,"TAKE_CARDID","PUT_BOTTOM",menuCard)
                    summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")

                    destroyList(menuCard)
                end
            end

            destroyList(boss_list)
        end
    end

}
