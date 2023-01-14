ZTCG_CARD
{

    "NAME" "Meditation"
    "IMAGE" "S1C038_Meditation.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Skill"
    "COST" "580"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "Get +40 on damage you do with the next tactic or monster attack this turn. Draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "10"
        "ATTRB" "1"
        "TEXT" "Assist -- Get +10 on the next damage you do with a tactic or monster attack this turn. "
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 10, 0, nil)
        editCardRegister(src, cid, 1, 40, 0, nil)

        insertCardNextAction(player)  -- card pointer : next attack

        drawCard(player)
    end

    function onCalcNextAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_TYPE", "TYPE_ANYMOB | TYPE_ACT") and getCardRegister(src, cid, 0) == 10) then
            local dmg = getGameValue(0)
            local bonus = getCardRegister(src, cid, 1)
            updateGameValue(0, dmg + bonus)

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
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 10, 0, nil)
        editCardRegister(src, cid, 1, 10, 0, nil)

        insertCardNextAction(player)  -- card pointer : next attack
    end

}
