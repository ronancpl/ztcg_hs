ZTCG_CARD
{

    "NAME" "Alishar's Death Magic"
    "IMAGE" "S2C017_AlisharsDeathMagic.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "680"

    TYPE_ACT
    {
        "LEVEL" "80"
        "TEXT" "Do 150 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Amaze -- Name a card. Reveal the top card of your deck. If you named that card, put it into your hand and do 40 damage to a character or monster. "
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        attack(player, src, 150, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onLevelActionTrigger(player)
        if amaze(player) then
            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            attack(player, chr, 40, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

}
