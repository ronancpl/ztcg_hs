ZTCG_CARD
{

    "NAME" "Soul Arrow"
    "IMAGE" "S1C022_SoulArrow.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "600"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "Do 40 damage to a character or a monster. Draw a card. Then discard a card from your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "1"
        "TEXT" "Easy Shot -- Do 10 damage to a character or monster. "
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        attack(player, src, 40, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")

        drawCard(player)
        discardCard(player)
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
