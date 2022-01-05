ZTCG_CARD
{

    "NAME" "Nella"
    "IMAGE" "S4C027_Nella.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Human NPC"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "10"
        "ATTCK" "10"
        "HP" "20"
        "TEXT" "NPC Quest -- You attack with Cloto or Lakelis. Reward -- Nella gets +20 attack this turn."
    }

    LVL_ACTION
    {
        "LEVEL" "10"
        "ATTRB" "1"
        "TEXT" "Buff a Friend -- One of your monsters that attacks this turn gets +10 attack until end of turn."
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        editCardRegister(src, cardid, 0, 0, 0, nil)
    end

    function onLaunchAttack(player)
        local atkr = getCardPointer(0)
        local atkrName = getNameFromCARD(atkr)
        if atkrName == "Cloto" or atkrName == "Lakelis" then
            local src = getSourceCARD()
            newBuff(src,src,20,0,0,1)
        end
    end

    function onCalcAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_TYPE", "TYPE_MOB | TYPE_JRB | TYPE_BOS") and getCardRegister(src, cid, 0) == 10) then
            local dmg = getGameValue(0)
            local bonus = getCardRegister(src, cid, 1)
            updateGameValue(0, dmg + bonus)

            return 1    -- notices bonus from next tactic
        end
    end

    function onExecuteAttack(player)
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
