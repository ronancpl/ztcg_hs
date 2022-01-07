ZTCG_CARD
{

    "NAME" "Combo Shot"
    "IMAGE" "S5C004_ComboShot.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Strategy"
    "COST" "680"

    TYPE_ACT
    {
        "LEVEL" "10"
        "TEXT" "Do 30 damage to a character or monster and clash with your opponent. If you win, do another 30 damage to a character or monster. (To clash, each player reveals the top card of their deck, then puts it on top or bottom. Whoever reveawled the highest-level card wins.)"
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Clash Time -- Clash with your opponent. If you win, do 40 damage to a character or monster."
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        attack(player, src, 30, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")

        if playClash(player) then
            attack(player, src, 30, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end
    end

    function onLevelActionTrigger(player)
        if playClash(player) then
            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            attack(player, chr, 40, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end
    end

}
