ZTCG_CARD
{

    "NAME" "Punco"
    "IMAGE" "S5C086_Punco.png"
    "TYPE" "MOB"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Zakum Guardian"
    "COST" "730"

    TYPE_MOB
    {
        "LEVEL" "67"
        "ATTCK" "60"
        "HP" "70"
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "0"
        "TEXT" "Spawn 40 -- Play a monster of level 40 or less."
    }

    function onActivateCharacterAction(player)
        local str = "Spawn 40"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",40)
    end

}
