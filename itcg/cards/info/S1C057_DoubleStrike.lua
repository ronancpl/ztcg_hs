ZTCG_CARD
{

    "NAME" "Double Strike"
    "IMAGE" "S1C057_DoubleStrike.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Skill"
    "COST" "610"

    TYPE_ACT
    {
        "LEVEL" "20"
        "TEXT" "Destroy a monster"
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Slash -- Do 20 damage to a character or monster. "
    }

    function onThinkAction(player)
        destroyMonster(player)
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
