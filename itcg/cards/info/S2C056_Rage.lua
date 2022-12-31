ZTCG_CARD
{

    "NAME" "Rage"
    "IMAGE" "S2C056_Rage.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Skill"
    "COST" "740"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "For each Warrior card under your character, one of your monsters that attacks this turn gets +10 attack until end of turn."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Astonish -- Name a card. Reveal the top card of your deck. If you named that card, level up with it. "
    }

    function onCalcAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_TYPE", "TYPE_ANYMOB") and getCardRegister(src, cid, 0) > 0) then
            local dmg = getGameValue(0)
            local bonus = getCardRegister(src, cid, 1)
            updateGameValue(0, dmg + bonus)

            return 1    -- notices bonus from next action
        else
            return 0
        end
    end

    function onExecuteAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local count = getCardRegister(src, cid, 0)
        if(count > 0) then
            editCardRegister(src, cid, 0, count - 1, 0, nil)

            return 1    -- finishes bonus from next action
        else
            return 0
        end
    end

    function onThinkAction(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local count = getPlayerAttributes(player,"ELEM_WARRIOR")
        editCardRegister(src, cid, 0, count, 0, nil)
        editCardRegister(src, cid, 1, 10, 0, nil)

        insertCardTurnAction(player)  -- card pointer : next attack
    end

    function onLevelActionTrigger(player)
        if amaze(player) then
            local d = drawCard(player)
            if d then
                levelUpScout(player,false)
            end
        end
    end

}
