ZTCG_CARD
{

    "NAME" "Iron Boar"
    "IMAGE" "S2C050_IronBoar.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Boar"
    "COST" "780"

    TYPE_MOB
    {
        "LEVEL" "45"
        "ATTCK" "30"
        "HP" "50"
        "TEXT" "Leader 20 -- Each of your other Boars gets +20 attack and +20 HP."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "1"
        "TEXT" "Boar Buff -- One Boar that attacks this turn gets +30 attack until the end of the turn. "
    }

    function undoBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Boar")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        local src = getSourceCARD()
        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_OTHER",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Boar")
    end

    function onCalcAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(0)
        if(isInfoCARD(atkr, "Boar") and hasSharedFlagsCARD(atkr, "FLAG_TYPE", "TYPE_ANYMOB | TYPE_ACT") and getCardRegister(src, cid, 0) == 10) then
            local dmg = getGameValue(0)
            local bonus = getCardRegister(src, cid, 1)
            updateGameValue(0, dmg + bonus)

            return 1    -- notices bonus from next attack
        end
    end

    function onExecuteAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(0)
        if(isInfoCARD(atkr, "Boar") and getCardRegister(src, cid, 0) == 10) then
            editCardRegister(src, cid, 0, 0, 0, nil)
            newBuff(atkr,src,30,0,0,1)

            return 1    -- finishes bonus from next attack
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 10, 0, nil)
        editCardRegister(src, cid, 1, 30, 0, nil)

        insertCardTurnAction(player)  -- card pointer : next attack
    end

}
