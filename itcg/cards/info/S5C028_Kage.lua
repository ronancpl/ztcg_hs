ZTCG_CARD
{

    "NAME" "Kage"
    "IMAGE" "S5C028_Kage.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Zakum Weapon"
    "COST" "800"

    TYPE_EQP
    {
        "LEVEL" "85"
        "TEXT" "For each card in your hand, each of your monsters gets +10 attack."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "I Don't Know -- If you have no cards in hand, draw a card."
    }

    function onEquipBuff(player)
        local deck = getPlayerDeck(player, "DECK_HAND")
        local list, qty = getListFromDeck(deck)

        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            return 10 * qty
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local deckHand = getPlayerDeck(player, "DECK_HAND")
        local card_list, qty = getListFromDeck(deckHand)

        if qty == 0 then
            drawCard(player)
        end
    end

}
