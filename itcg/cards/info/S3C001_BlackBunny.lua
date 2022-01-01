ZTCG_CARD
{

    "NAME" "Black Bunny"
    "IMAGE" "S3C001_BlackBunny.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Pet Rabbit"
    "COST" "650"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "Hungry -- When your turn starts, put the top card of your deck face down under this Pet. (A Pet can have up to 3 cards under it.) Populate -- When Black Bunny has 3 cards under it, reveal them. You may play any Bowman monsters of level 30 or less revealed this way. Otherwise, put them on the bottom of your deck in any order."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "1"
        "TEXT" "Easy Shot -- Do 10 damage to a character or monster."
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

            local pet_spawns = makeFilteredList(player,card_list,0,0,30,"TYPE_MOB","ELEM_BOWMAN","ZTCG_NIL")
            while not isEmptyList(pet_spawns) do
                local pet_spawn = menuCards(player,pet_spawns,"Select a card to spawn.","CARDLIST_HIDE")
                if pet_spawn == 0 then
                    break
                end

                card_list = takeTargetCardFromList(pet_spawn,card_list)
                pet_spawns = takeTargetCardFromListToDeck(hand,pet_spawns,pet_spawn,"DECK_BOTTOM")
                summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
            end

            pet_spawns = moveCardsFromListToDeck(pet_spawns,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            card_list = moveCardsFromListToDeck(card_list,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

            destroyList(pet_spawns)
            destroyList(card_list)
        end
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
