ZTCG_CARD
{

    "NAME" "Lorang"
    "IMAGE" "S1C063_Lorang.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Water Crab"
    "COST" "580"

    TYPE_MOB
    {
        "LEVEL" "37"
        "ATTCK" "40"
        "HP" "10"
        "TEXT" "Tough -- Character actions don't damage Lorang."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Spawn 50 -- Play a monster of level 50 or less. "
    }

    function preventTargetMob(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            return 1
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 50"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",50)
    end


}
