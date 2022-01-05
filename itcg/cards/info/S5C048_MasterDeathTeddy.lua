ZTCG_CARD
{

    "NAME" "Master Death Teddy"
    "IMAGE" "S5C048_MasterDeathTeddy.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Undead Toy Bear"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "89"
        "ATTCK" "80"
        "HP" "90"
        "TEXT" "Frighten -- When you play Master Death Teddy, you may destroy a non-Boss monster."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Ghostly Journey -- If your opponent has no cards in hand, draw a card."
    }

    function onThinkMob(player)
        destroyMonster(player)
    end

    function onActivateCharacterAction(player)
        local hand = getPlayerDeck(not player, "DECK_HAND")
        local card_list, qty = getListFromDeck(hand)

        if qty == 0 then
            drawCard(player)
        end
    end

}
