ZTCG_CARD
{

    "NAME" "Ruin"
    "IMAGE" "S3C059_Ruin.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Strategy"
    "COST" "680"

    TYPE_ACT
    {
        "LEVEL" "50"
        "TEXT" "Destroy up to 2 items."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "1"
        "TEXT" "Think Fast 40 -- Play a tactic of level 40 or less."
    }

    function onThinkAction(player)
        destroyEquipment(player)
        destroyEquipment(player)
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast 40"
        action(player,"ZTCG_NIL","ELEM_ANY",40)
    end

}
