ZTCG_CARD
{

    "NAME" "Pink Teddy"
    "IMAGE" "S1C066_PinkTeddy.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Toy Bear"
    "COST" "550"

    TYPE_MOB
    {
        "LEVEL" "32"
        "ATTCK" "30"
        "HP" "30"
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Loot -- If your opponent has 3 or more cards in hand, he or she chooses one and discards it. "
    }

    function onLevelActionTrigger(player)
        local hand = getPlayerDeck(not player, "DECK_HAND")
        local cards, qty = getListFromDeck(hand)

        if qty >= 3 then
            discardCard(not player)
        end
    end

}
