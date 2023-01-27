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

    function tsbAction(p,player)
        local src = getSourceCARD()

        local def_card = getCardPointer(1)
        if getSlotIdFromCARD(p,def_card) < 0 and getCurrentLevelFromCARD(p,def_card) <= 10 and hasSharedFlagsCARD(def_card, "FLAG_TYPE", "TYPE_ANYMOB") then
            local srcCard = makeTargetFromCARD(src)

            local deckGrav = getPlayerDeck(player, "DECK_GRAV")
            local cardList = takeTargetCardFromDeck(player,srcCard,deckGrav)

            local deckHand = getPlayerDeck(player, "DECK_HAND")
            cardList = moveCardsFromListToDeck(player,cardList, deckHand,"TAKE_NEXT","PUT_BOTTOM",1)

            destroyList(cardList)
            destroyList(srcCard)
        end
    end

    function onExecuteAttackViewGraveyard(player)
        tsbAction(not player,player)
    end

    function onReceiveAttackViewGraveyard(player)
        tsbAction(player,player)
    end

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
                destroyList(spawn_list)
                break
            end

            local menuCard = menuCards(player,spawn_list,"Select a card to play.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                local cardList = takeTargetCardFromDeck(player,menuCard,deckHand)
                cardList = moveCardsFromListToDeck(player,cardList,deckHand,"TAKE_CARDID","PUT_BOTTOM",menuCard)

                local card = getCARD(menuCard)
                if hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_ANYMOB") then
                    ret = summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_EQP") then
                    ret = equip(player,"PLAY_SCOUTEQUIP", "ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_ACT") then
                    ret = action(player,card, "ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_FLD") then
                    ret = locate(player,"PLAY_FIRSTCARDFIELD", "ELEM_ANY")
                end

                local cardLevel = getCurrentLevelFromCARD(card)
                editCardRegister(src, cardid, 0, level - cardLevel, 0, nil)

                destroyList(cardList)
                destroyList(spawn_list)
            else
                destroyList(spawn_list)
                break
            end
        end
    end

}
