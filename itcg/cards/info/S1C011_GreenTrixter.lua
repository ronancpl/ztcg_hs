ZTCG_CARD
{

    "NAME" "Green Trixter"
    "IMAGE" "S1C011_GreenTrixter.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Pest"
    "COST" "570"

    TYPE_MOB
    {
        "LEVEL" "28"
        "ATTCK" "20"
        "HP" "20"
        "TEXT" "Sting -- When you play Green Trixter, do 10 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "1"
        "TEXT" "Easy Shot -- Do 10 damage to a character or monster. "
    }

    function onThinkMob(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
