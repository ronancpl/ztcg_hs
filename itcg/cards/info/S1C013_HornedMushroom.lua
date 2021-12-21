ZTCG_CARD
{

    "NAME" "Horned Mushroom"
    "IMAGE" "S1C013_HornedMushroom.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Mushroom"
    "COST" "430"

    TYPE_MOB
    {
        "LEVEL" "22"
        "ATTCK" "20"
        "HP" "40"
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 30 -- Play a monster or item of level 30 or less. "
    }

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 30"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 30)
    end


}
