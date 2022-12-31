ZTCG_CARD
{

    "NAME" "Pet Elephant"
    "IMAGE" "S5C015_PetElephant.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Pet"
    "COST" "700"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "Hungry -- When your turn starts, put the top card of your deck face down under this Pet. (A Pet can have up to 3 cards under it.) Never Forgets -- When Pet elephant has 3 cards under it, reveal them. Level up with one of those cards, then put the others on the bottom of your deck in any order."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Remember -- If your opponent has more cards in hand than you, draw a card."
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player, src) < 0 then return end

        local deck = getPlayerDeck(player, "DECK_DECK")

        local c = countCardsUnder(player,src)
        if c < 3 then
            local card_list = takeCardsFromDeck(player,deck, 1)
            local card = makeTargetFromCARD(getCARD(card_list))

            if card ~= 0 then
                card_list = takeTargetCardFromList(card,card_list)
                card = putCardUnder(src,card)
            end

            destroyList(card)
            destroyList(card_list)
        end

        local c = countCardsUnder(player,src)
        if c >= 3 then
            local pet_spawns = removeCardsUnder(src)

            local pet_spawn = menuCards(player,pet_spawns,"Select a card to level up with.","CARDLIST_PEEK")
            if pet_spawn ~= 0 then
                local hand = getPlayerDeck(player, "DECK_HAND")
                pet_spawns = takeTargetCardFromListToDeck(player,hand,pet_spawns,pet_spawn,"DECK_BOTTOM")

                levelUpScout(player,false)
            end

            pickCardOrder(player,pet_spawns)
            pet_spawns = moveCardsFromListToDeck(player,pet_spawns,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

            destroyList(pet_spawns)
        end
    end

    function onLevelActionTrigger(player)
        local hand1 = getPlayerDeck(player,"DECK_HAND")
        local card_list1, qty1 = getListFromDeck(hand1)

        local hand2 = getPlayerDeck(not player,"DECK_HAND")
        local card_list2, qty2 = getListFromDeck(hand2)

        if qty1 < qty2 then
            drawCard(player)
        end
    end

}
