ZTCG_CARD
{

    "NAME" "Side Quest"
    "IMAGE" "S1C043_SideQuest.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Strategy"
    "COST" "530"

    TYPE_ACT
    {
        "LEVEL" "40"
        "TEXT" "Draw 2 Cards."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Think Fast 40 -- Play a tactic of level 40 or less. "
    }

    function onThinkAction(player)
        drawCard(player)
        drawCard(player)
    end

    function onActivateCharacterAction(player)
        action(player,"ZTCG_NIL","ELEM_ANY",40)
    end

}
