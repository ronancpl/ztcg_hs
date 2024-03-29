ZTCG_CARD
{

    "NAME" "Holy Arrow"
    "IMAGE" "S4C023_HolyArrow.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "600"

    TYPE_ACT
    {
        "LEVEL" "10"
        "TEXT" "Do 30 damage to a character or monster. If that monster is Undead, destroy it."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "1"
        "TEXT" "Think Fast 90 -- Play a tactic of level 90 or less."
    }

    function onCalcNextAttack(player)
        return 1    -- notices bonus from next tactic
    end

    function onExecuteNextAttack(player)
        local def_card = getCardPointer(1)
        if isInfoCARD(def_card, "Undead") then
            local slotid = getSlotIdFromCARD(not player, def_card)
            if slotid > 0 then
                destroyCard(player,"SLOT_ADVSRYMOB" .. slotid)
            end
        end

        return 1    -- finishes bonus from next tactic
    end

    function onThinkAction(player)
        insertCardNextAction(player)  -- card pointer : next attack

        local src = getSourceCARD()
        attack(player,src,30,"ATKRES_NIL", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast 90"
        action(player,"ZTCG_NIL","ELEM_ANY",90)
    end

}
