ZTCG_CARD
{

    "NAME" "Brown Kitty"
    "IMAGE" "S3C033_BrownKitty.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Pet Kitty"
    "COST" "800"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "Hungry -- When your turn starts, put the top card of your deck face down under this Pet. (A Pet can have up to 3 cards under it.) Cat's Meow -- When Brown Kitty has 3 cards under it, look at them. Put 1 card into your hand and the others on the bottom of your deck in any order."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "3"
        "TEXT" "Crafty -- Play a Thief card of your level or less."
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
                putCardUnder(src,card)
            end

            destroyList(card_list)
        end

        local c = countCardsUnder(player,src)
        if c >= 3 then
            local pet_spawns = removeCardsUnder(src)

            local pet_spawn = menuCards(player,pet_spawns,"Select a card to draw.","CARDLIST_HIDE")
            if pet_spawn ~= 0 then
                local hand = getPlayerDeck(player, "DECK_HAND")
                pet_spawns = takeTargetCardFromListToDeck(player,hand,pet_spawns,pet_spawn,"DECK_BOTTOM")
            end

            pickCardOrder(player,pet_spawns)
            pet_spawns = moveCardsFromListToDeck(player,pet_spawns,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

            destroyList(pet_spawns)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Crafty"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_THIEF", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", level)
    end

}
