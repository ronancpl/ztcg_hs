ZTCG_CARD
{

    "NAME" "Robot"
    "IMAGE" "S3C024_Robot.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Pet Robot"
    "COST" "850"

    TYPE_EQP
    {
        "LEVEL" "20"
        "TEXT" "Hungry -- When your turn starts, put the top card of your deck face down under this Pet. (A Pet can have up to 3 cards under it.) Power Surge - When Robot has 3 cards under it, reveal them. You may play 1 tactic revealed this way and put the others on the bottom of your deck in any order. "
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Quest -- Draw a card."
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
            local hand = getPlayerDeck(player, "DECK_HAND")
            local card_list = removeCardsUnder(src)

            local pet_spawns = makeFilteredList(player,card_list,0,0,30,"TYPE_ACT","ELEM_ANY","ZTCG_NIL")
            while not isEmptyList(pet_spawns) do
                local pet_spawn = menuCards(player,cards,"Select a tactic to play.","CARDLIST_HIDE")
                if pet_spawn == 0 then
                    break
                end

                card_list = takeTargetCardFromList(pet_spawn,card_list)
                pet_spawns = takeTargetCardFromListToDeck(hand,pet_spawns,pet_spawn,"DECK_BOTTOM")

                action(player,getCARD(pet_spawn),"ELEM_ANY","ZTCG_DONTCARE")
            end

            pet_spawns = moveCardsFromListToDeck(pet_spawns,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            card_list = moveCardsFromListToDeck(card_list,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

            destroyList(pet_spawns)
            destroyList(card_list)
        end

        destroyList(cards)
    end

}
