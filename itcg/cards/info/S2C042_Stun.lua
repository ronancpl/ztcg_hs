ZTCG_CARD
{

    "NAME" "Stun"
    "IMAGE" "S2C042_Stun.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Strategy"
    "COST" "600"

    TYPE_ACT
    {
        "LEVEL" "60"
        "TEXT" "For each Thief card under your character, your opponent chooses and discards a card from his or her hand."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Loot -- If your opponent has 3 or more cards in hand, he or she chooses one and discards it. "
    }

    function onThinkAction(player)
        local attr = getPlayerAttributes(player, "ELEM_THIEF")
        for i = 1, attr, 1 do
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
