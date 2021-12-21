ZTCG_CARD
{

    "NAME" "Magic Claw"
    "IMAGE" "S1C035_MagicClaw.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "560"

    TYPE_ACT
    {
        "LEVEL" "20"
        "TEXT" "Do 20 damage to a character or monster. Then do 20 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "1"
        "TEXT" "Think Fast 30 -- Play a tactic of level 30 or less. "
    }

    function onThinkAction(player)
        local src = getSourceCARD()

        attack(player, src, 20, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        attack(player, src, 20, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast 30"
        action(player,"ZTCG_NIL","ELEM_ANY",30)
    end


}
