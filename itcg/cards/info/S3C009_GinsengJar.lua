ZTCG_CARD
{

    "NAME" "Ginseng Jar"
    "IMAGE" "S3C009_GinsengJar.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Flora Jar"
    "COST" "730"

    TYPE_MOB
    {
        "LEVEL" "48"
        "ATTCK" "40"
        "HP" "40"
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Tricky Shot -- Do 20 damage to a character or monster."
    }

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
