ZTCG_CARD
{

    "NAME" "Emerald Earrings"
    "IMAGE" "S1C058_EmeraldEarrings.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Armor"
    "COST" "620"

    TYPE_EQP
    {
        "LEVEL" "30"
        "TEXT" "Whenever you play another item, reveal the top card of your deck. If it's an item card, put it into your hand. Otherwise put it back."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Sneak 70 -- Play a card level 70 or less. "
    }

    function onInterceptPlayEquipment(player)
        local deck = getPlayerDeck(player, "DECK_DECK")

        local card = peekNextCard(player)
        --revealCard(not player,"Next card...",card)

        if hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_EQP") then   -- only draw card if its an item
            local hand = getPlayerDeck(player, "DECK_HAND")
            moveCards(deck,hand,"TAKE_NEXT","PUT_BOTTOM",1)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Sneak 20"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", 20)
    end

}
