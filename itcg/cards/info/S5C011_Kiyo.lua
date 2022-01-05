ZTCG_CARD
{

    "NAME" "Kiyo"
    "IMAGE" "S5C011_Kiyo.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Flying Bird"
    "COST" "620"

    TYPE_MOB
    {
        "LEVEL" "30"
        "ATTCK" "20"
        "HP" "40"
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "1"
        "TEXT" "Spawn 40 -- Play a monster of level 40 or less."
    }

    function onActivateCharacterAction(player)
        local str = "Spawn 40"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",40)
    end

}
