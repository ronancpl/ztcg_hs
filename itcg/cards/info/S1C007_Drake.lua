ZTCG_CARD
{

    "NAME" "Drake"
    "IMAGE" "S1C007_Drake.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Fire Dragon"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "50"
        "ATTCK" "30"
        "HP" "40"
        "TEXT" "Chomp -- When you play Drake, do 30 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "3"
        "TEXT" "Deadly Shot -- Do 30 damage to a character or monster. "
    }

    function onThinkMob(player)
        local atkr = getSourceCARD()
        attack(player, atkr, 30, "ATKRES_NIL", "ATKSRC_MOB", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 30, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
