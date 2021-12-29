ZTCG_CARD
{

    "NAME" "Ghost Stump"
    "IMAGE" "S2C025_GhostStump.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Undead Flora"
    "COST" ""

    TYPE_MOB
    {
        "LEVEL" "19"
        "ATTCK" "10"
        "HP" "40"
    }

    LVL_ACTION
    {
        "LEVEL" "90"
        "ATTRB" "2"
        "TEXT" "Spawn 140 -- Play a monster of level 140 or less. "
    }

    function onActivateCharacterAction(player)
        local str = "Spawn 140"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",140)
    end

}
