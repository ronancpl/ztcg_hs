ZTCG_CARD
{

    "NAME" "Swipe"
    "IMAGE" "S1C072_Swipe.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Strategy"
    "COST" "520"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "Your opponent discards a card at random from his or her hand."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Spy -- Draw a card. Then discard a card. "
    }

    function onThinkAction(player)
        discardCardRandom(not player)
    end

    function onLevelActionTrigger(player)
        drawCard(player)
        discardCard(player)
    end

}
