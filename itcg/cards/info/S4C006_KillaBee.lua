ZTCG_CARD
{

    "NAME" "Killa Bee"
    "IMAGE" "S4C006_KillaBee.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Flying Pest"
    "COST" "680"

    TYPE_MOB
    {
        "LEVEL" "25"
        "ATTCK" "30"
        "HP" "30"
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "1"
        "TEXT" "Spawn / Equip 30 -- Play a monster or item of level 30 or less."
    }

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 30"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 30)
    end

}
