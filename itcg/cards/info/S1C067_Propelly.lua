ZTCG_CARD
{

    "NAME" "Propelly"
    "IMAGE" "S1C067_Propelly.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Flying Toy"
    "COST" "570"

    TYPE_MOB
    {
        "LEVEL" "37"
        "ATTCK" "50"
        "HP" "20"
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
