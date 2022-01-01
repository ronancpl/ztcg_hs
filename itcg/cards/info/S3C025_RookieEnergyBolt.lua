ZTCG_CARD
{

    "NAME" "Rookie Energy Bolt"
    "IMAGE" "S3C025_RookieEnergyBolt.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "700"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "Do 70 damage to a character or monster. "
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "3"
        "TEXT" "Think Fast X -- Play a tactic of your level or less."
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        attack(player, src, 70, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        action(player,"ZTCG_NIL","ELEM_ANY",level)
    end

}
