ZTCG_CARD
{

    "NAME" "Crow"
    "IMAGE" "S3C005_Crow.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Flying Bird"
    "COST" "570"

    TYPE_MOB
    {
        "LEVEL" "25"
        "ATTCK" "10"
        "HP" "20"
        "TEXT" "Peck -- Whenever your opponent levels up, do 20 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Spawn / Equip 40 -- Play a monster or item of level 40 or less."
    }

    function onOpponentLevelUp(player)
        local src = getSourceCARD()
        attack(player, src, 20, "ATKRES_NIL", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 40"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 40)
    end

}
