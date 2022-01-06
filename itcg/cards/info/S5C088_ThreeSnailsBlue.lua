ZTCG_CARD
{

    "NAME" "Three Snails : Blue"
    "IMAGE" "S5C088_ThreeSnailsBlue.png"
    "TYPE" "ACTION"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "550"

    TYPE_ACT
    {
        "LEVEL" "1"
        "TEXT" "Do 20 damage to a character or monster. Whenever a monster of level 10 or less is destroyed, if this card is in your discard pile, you may return it to your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "0"
        "TEXT" "Multi Sneak 20 -- Play any number of cards with combined levels of 20 or less."
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        attack(player, src, 20, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        editCardRegister(src, cardid, 0, 20, 0, nil)

        local deckHand = getPlayerDeck(player, "DECK_HAND")

        while true do
            local level = getCardRegister(src, cardid, 0)

            local card_list = getListFromDeck(deckHand)
            local spawn_list, not_empty = makeFilteredList(player,card_list,0,0,level,"TYPE_ANY","ELEM_ANY","ZTCG_NIL")
            if not not_empty then
                break
            end

            local menuCard = menuCards(player,spawn_list,"Select a card to play.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                local cardList = takeTargetCardFromDeck(card,deckHand)
                cardList = moveCardsFromListToDeck(cardList,deckHand,"TAKE_CARDID","PUT_BOTTOM",card)

                local card = getCARD(menuCard)
                if hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_MOB | TYPE_JRB | TYPE_BOS") then
                    ret = summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_EQP") then
                    ret = equip(player,"PLAY_SCOUTEQUIP", "ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_ACT") then
                    ret = action(player,card, "ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_FLD") then
                    ret = locate(player,"PLAY_FIRSTCARDFIELD", "ELEM_ANY")
                end

                local cardLevel = getBaseLevelFromCARD(getCARD(card))
                editCardRegister(src, cardid, 0, level - cardLevel, 0, nil)

                destroyList(spawn_list)
            else
                destroyList(spawn_list)
                break
            end
        end
    end

}