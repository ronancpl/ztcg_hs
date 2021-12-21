ZTCG_CARD
{

    "NAME" "Stirge"
    "IMAGE" "S1C023_Stirge.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Flying Bat"
    "COST" "450"

    TYPE_MOB
    {
        "LEVEL" "20"
        "ATTCK" "30"
        "HP" "20"
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "1"
        "TEXT" "Spawn / Equip 50 -- Play a monster or item of level 50 or less. "
    }

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 50"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 50)
    end

}
