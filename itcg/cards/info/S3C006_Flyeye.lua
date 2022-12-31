ZTCG_CARD
{

    "NAME" "Flyeye"
    "IMAGE" "S3C006_Flyeye.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Flying Beast"
    "COST" "850"

    TYPE_MOB
    {
        "LEVEL" "41"
        "ATTCK" "40"
        "HP" "30"
        "TEXT" "Stupefy -- When you play Flyeye, your opponent can't play tactics next turn."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "3"
        "TEXT" "Deadly Shot -- Do 30 damage to a character or monster."
    }

    function onThinkMob(player)
        turnAction(not player,false)
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 30, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
