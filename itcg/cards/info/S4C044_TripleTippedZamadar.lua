ZTCG_CARD
{

    "NAME" "Triple-Tipped Zamadar"
    "IMAGE" "S4C044_TripleTippedZamadar.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Weapon"
    "COST" "710"

    TYPE_EQP
    {
        "LEVEL" "17"
        "TEXT" "One of your monsters gets +10 attack each turn. If you have another Weapon, that monster gets +20 attack instead."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "1"
        "TEXT" "Spawn 40 -- Play a monster of level 40 or less."
    }

    function onCalcAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_TYPE", "TYPE_MOB") and getCardRegister(src, cid, 0) == 10) then
            local dmg = getGameValue(0)

            local list = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP","ELEM_ANY","Weapon")
            local bonus = getListLength(list) > 2 and 20 or 10
            destroyList(list)

            updateGameValue(0, dmg + bonus)
            return 1    -- notices bonus from next tactic
        end
    end

    function onExecuteAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_TYPE", "TYPE_MOB") and getCardRegister(src, cid, 0) == 10) then
            editCardRegister(src, cid, 0, 0, 0, nil)

            return 1    -- finishes bonus from next tactic
        end
    end

    function onThinkEquipment(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 10, 0, nil)

        insertCardNextAction(player)  -- card pointer : next attack
    end

    function onStartTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 10, 0, nil)

        insertCardNextAction(player)  -- card pointer : next attack
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 40"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",40)
    end

}
