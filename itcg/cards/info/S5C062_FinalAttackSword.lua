ZTCG_CARD
{

    "NAME" "Final Attack : Sword"
    "IMAGE" "S5C062_FinalAttackSword.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "580"

    TYPE_ACT
    {
        "LEVEL" "35"
        "TEXT" "If you have a Weapon, one of your monsters that attacks this turn gets +60 attack until end of turn and you draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Crush -- Do 20 damage to a monster."
    }

    function onThinkAction(player)
        local list, not_empty = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP","ELEM_ANY","Weapon")
        destroyList(list)

        if not_empty then
            local src = getSourceCARD()
            local cid = getCardIdFromCARD(src)

            editCardRegister(src, cid, 0, 10, 0, nil)
            editCardRegister(src, cid, 1, 60, 0, nil)

            insertCardNextAction(player)  -- card pointer : next attack

            drawCard(player)
        end
    end

    function onCalcAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_TYPE", "TYPE_MOB | TYPE_ACT") and getCardRegister(src, cid, 0) == 10) then
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
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_DONT_HIT_CHAR", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
