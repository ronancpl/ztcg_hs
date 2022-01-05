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
            local cards = takeCardsFromDeck(deck, 1)
            local card = menuCards(player,cards,"Pick a card to place under the pet.","CARDLIST_HIDE")

            if card ~= 0 then
                cards = takeTargetCardFromList(card,cards)
                putCardUnder(src,card)
            end

            destroyList(cards)
        end

        local c = countCardsUnder(player,src)
        if c >= 3 then
            local pet_spawns = removeCardsUnder(src)

            local pet_spawn = menuCards(player,pet_spawns,"Select a card to level up with.","CARDLIST_HIDE")
            if pet_spawn ~= 0 then
                local hand = getPlayerDeck(player, "DECK_HAND")
                pet_spawns = takeTargetCardFromListToDeck(hand,pet_spawns,pet_spawn,"DECK_BOTTOM")

                levelUpScout(player)
            end

            pet_spawns = moveCardsFromListToDeck(pet_spawns,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

            destroyList(pet_spawns)
        end
    end

    function onLevelActionTrigger(player)
        local deck1 = getPlayerDeck(player,"DECK_DECK")
        local card_list1, qty1 = getListFromDeck(deck1)

        local deck2 = getPlayerDeck(not player,"DECK_DECK")
        local card_list2, qty2 = getListFromDeck(deck2)

        if qty1 < qty2 then
            drawCard(player)
        end
    end

}
