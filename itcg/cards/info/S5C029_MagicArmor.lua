ZTCG_CARD
{

    "NAME" "Magic Armor"
    "IMAGE" "S5C029_MagicArmor.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Skill"
    "COST" "600"

    TYPE_ACT
    {
        "LEVEL" "20"
        "TEXT" "Until your next turn starts, each of your monsters gets Shield 20 and each of your items gets Shield 10. (Each monster prevents 20 damage to your character instead of 10. Each item prevents 10 damage to your character instead of 0.)"
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Shock -- Do 20 damage to a character."
    }

    function onCalcDefenseCard(player)
        local mobs = getMobsOnTable(player,"ONLY_PLAYER")
        local eqps = getEquipsOnTable(player,"ONLY_PLAYER")

        local def_card = getCardPointer(1)
        if(hasSharedFlagsCARD(def_card, "FLAG_TYPE", "TYPE_CHAR")) then
            local dmgPrevent = getGameValue(0) + (10 * (mobs + eqps))
            updateGameValue(0, dmgPrevent)
        end
    end

    function onThinkAction(player)
        insertCardTurnAction(player)
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_DONT_HIT_MOBS", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
