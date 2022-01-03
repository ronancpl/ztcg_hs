ZTCG_CARD
{

    "NAME" "Chipmunk"
    "IMAGE" "S4C033_Chipmunk.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Pest"
    "COST" "680"

    TYPE_MOB
    {
        "LEVEL" "40"
        "ATTCK" "30"
        "HP" "30"
        "TEXT" "Loot -- If your opponent has 3 or more cards in hand, he or she chooses one and discards it."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Loot -- If your opponent has 3 or more cards in hand, he or she chooses one and discards it."
    }

    function onThinkMob(player)
        local hand = getPlayerDeck(not player, "DECK_HAND")
        local cards, qty = getListFromDeck(hand)

        if qty >= 3 then
            discardCard(not player)
        end
    end

    function onLevelActionTrigger(player)
        local hand = getPlayerDeck(not player, "DECK_HAND")
        local cards, qty = getListFromDeck(hand)

        if qty >= 3 then
            discardCard(not player)
        end
    end

}
