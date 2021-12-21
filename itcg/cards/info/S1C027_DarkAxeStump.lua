ZTCG_CARD
{

    "NAME" "Dark Axe Stump"
    "IMAGE" "S1C027_DarkAxeStump.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Dark Flora"
    "COST" "450"

    TYPE_MOB
    {
        "LEVEL" "22"
        "ATTCK" "10"
        "HP" "40"
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" " Spawn 40 -- Play a monster of level 40 or less. "
    }

    function onActivateCharacterAction(player)
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",40)
    end

}
