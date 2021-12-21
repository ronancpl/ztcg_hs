ZTCG_CARD
{

    "NAME" "Ribbon Pig"
    "IMAGE" "S1C086_RibbonPig.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Boar"
    "COST" "420"

    TYPE_MOB
    {
        "LEVEL" "10"
        "ATTCK" "20"
        "HP" "20"
    }

    LVL_ACTION
    {
        "LEVEL" "10"
        "ATTRB" "1"
        "TEXT" "Spawn 20 -- Play a monster of level 20 or less. "
    }

    function onActivateCharacterAction(player)
        local str = "Spawn 20"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",20)
    end

}
