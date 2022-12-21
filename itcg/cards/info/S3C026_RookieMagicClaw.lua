ZTCG_CARD
{

    "NAME" "Rookie Magic Claw"
    "IMAGE" "S3C026_RookieMagicClaw.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "500"

    TYPE_ACT
    {
        "LEVEL" "10"
        "TEXT" "Do 10 damage to a character or monster. Then do another 10 damage to a character or monster. Draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "10"
        "ATTRB" "1"
        "TEXT" "Zap -- Do 10 damage to a character."
    }

    function onThinkAction(player)
        local src = getSourceCARD()

        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")

        drawCard(player)
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 10, "ATKRES_DONT_HIT_MOBS", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
