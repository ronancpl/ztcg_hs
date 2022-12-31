ZTCG_CARD
{

    "NAME" "Respawn"
    "IMAGE" "S5C033_Respawn.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "670"

    TYPE_ACT
    {
        "LEVEL" "50"
        "TEXT" "Choose a monster. Its player puts it on the bottom of his or her deck. Then that player reveals the cards from the top of his or her deck until a monster card is revealed. He or she plays that monster, then puts the other cards revealed this way on the bottom of his or her deck in any order."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Think Fast 110 -- Play a tactic of level 110 or less."
    }

    function onThinkAction(player)
        local list, not_empty = makeFilteredTableList(player,"ANY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")

        local menuCard = menuCards(player,list,"Select a card to withdraw from the table.","CARDLIST_PEEK")
        if menuCard ~= 0 then
            local p
            local slotid = getSlotIdFromCARD(not player, getCARD(menuCard))
            if slotid < 0 then
                slotid = getSlotIdFromCARD(player, getCARD(menuCard))
                p = player
            else
                p = not player
            end

            local deck = getPlayerDeck(p, "DECK_DECK")
            local hand = getPlayerDeck(p, "DECK_HAND")

            local list2, hasCard
            list2, hasCard = takeCardFromTable(p, "SLOT_PLAYERMOB" .. tostring(slotid))

            list2 = moveCardsFromListToDeck(p,list2,deck,"TAKE_NEXT","PUT_BOTTOM", 1)
            destroyList(list2)

            local card
            local list3 = takeCardsFromDeck(p,deck, 1)
            if not hasSharedFlagsCARD(getCARD(list3), "FLAG_TYPE", "TYPE_ANYMOB") then
                while true do
                    card = takeCardsFromDeck(p,deck, 1)
                    list3 = appendLists(list3,card)

                    if hasSharedFlagsCARD(getCARD(card), "FLAG_TYPE", "TYPE_ANYMOB") then
                        break
                    else
                        destroyList(card)

                        local card_list, qty = getListFromDeck(deck)    -- shouldn't happen since 1 mob is present on deck
                        if qty == 0 then
                            break
                        end
                    end
                end
            else
                card = makeTargetFromCARD(getCARD(list3))
            end

            list3 = takeTargetCardFromListToDeck(p,hand,list3,card,"DECK_BOTTOM")
            summon(p,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")

            pickCardOrder(p, list3)
            list3 = moveCardsFromListToDeck(p,list3,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

            destroyList(card)
            destroyList(list3)
        end

        destroyList(list)
    end

    function onActivateCharacterAction(player)
        action(player,"ZTCG_NIL","ELEM_ANY",110)
    end

}
