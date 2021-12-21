ZTCG_CARD
{

    "NAME" "Red Snail"
    "IMAGE" "S1C069_RedSnail.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Pest"
    "COST" "480"

    TYPE_MOB
    {
        "LEVEL" "4"
        "ATTCK" "10"
        "HP" "20"
        "TEXT" "Tough -- Character actions don't damage Red Snail."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Spawn 90 -- Play a monster of level 90 or less. "
    }

    function preventTargetMob(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            return 1
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 90"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",90)
    end


}
