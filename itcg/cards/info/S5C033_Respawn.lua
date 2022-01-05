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

    function onThinkMob(player)
        local list, not_empty = makeFilteredTableList(player,"ANY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")

        local menuCard = menuCards(player,list,"Select a card to withdraw from the table.","CARDLIST_PEEK")
        if menuCard ~= 0 then
            local p
            local slotid = getSlotIdFromCARD(not player, menuCard)
            if slotid < 0 then
                slotid = getSlotIdFromCARD(player, menuCard)
                p = player
            else
                p = not player
            end

            local deck = getPlayerDeck(p, "DECK_DECK")
            local hand = getPlayerDeck(p, "DECK_DECK")

            local list, hasCard
            list, hasCard = takeCardFromTable(p, "SLOT_PLAYERMOB" .. tostring(slotid))

            list = moveCardsFromListToDeck(list,deck,"TAKE_NEXT","PUT_BOTTOM", 1)
            destroyList(list)

            local card
            local list = takeCardsFromDeck(deck, 1)
            if(not hasSharedFlagsCARD(getCARD(list), "FLAG_TYPE", "TYPE_ANYMOB")) then
                while true do
                    local list2 = takeCardsFromDeck(deck, 1)
                    list = appendLists(list,list2)

                    if hasSharedFlagsCARD(getCARD(list2), "FLAG_TYPE", "TYPE_ANYMOB") then
                        card = list2
                        break
                    else
                        local card_list, qty = getListFromDeck(deck)    -- shouldn't happen since 1 mob is present on deck
                        if qty == 0 then
                            break
                        end
                    end
                end
            else
                card = list
            end

            list = takeTargetCardFromListToDeck(hand,list,card,"DECK_BOTTOM")
            summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")

            pickCardOrder(player, list)
            list = moveCardsFromListToDeck(list,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")


            destroyList(list)
        end
    end

    function onActivateCharacterAction(player)
        action(player,"ZTCG_NIL","ELEM_ANY",110)
    end

}
