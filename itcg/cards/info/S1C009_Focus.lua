ZTCG_CARD
{

    "NAME" "Focus"
    "IMAGE" "S1C009_Focus.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Skill"
    "COST" "520"

    TYPE_ACT
    {
        "LEVEL" "20"
        "TEXT" "Get +50 damage you do with the next character action or monster attack this turn."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Think Fast 40 -- Play a tactic of level 40 or less. "
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        editCardRegister(src, cid, 0, 10, 0, nil)

        insertCardNextAction(player)  -- card pointer : next attack
    end

    function onCalcNextAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_TYPE", "TYPE_CHAR | TYPE_ANYMOB") and getCardRegister(src, cid, 0) == 10) then
            local dmg = getGameValue(0)
            updateGameValue(0, dmg + 50)

            return 1    -- notices bonus from next tactic
        end
    end

    function onExecuteNextAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if(getCardRegister(src, cid, 0) == 10) then
            editCardRegister(src, cid, 0, 0, 0, nil)
            return 1    -- finishes bonus from next tactic
        end
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast 40"
        action(player,"ZTCG_NIL","ELEM_ANY",40)
    end

}
