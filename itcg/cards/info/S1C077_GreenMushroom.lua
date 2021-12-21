ZTCG_CARD
{

    "NAME" "Green Mushroom"
    "IMAGE" "S1C077_GreenMushroom.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Mushroom"
    "COST" "570"

    TYPE_MOB
    {
        "LEVEL" "15"
        "ATTCK" "10"
        "HP" "40"
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 90 -- Play a monster or item of level 90 or less. "
    }

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 90"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 90)
    end

}
