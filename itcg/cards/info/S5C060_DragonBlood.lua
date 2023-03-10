ZTCG_CARD
{

    "NAME" "Dragon Blood"
    "IMAGE" "S5C060_DragonBlood.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Skill"
    "COST" "740"

    TYPE_ACT
    {
        "LEVEL" "70"
        "TEXT" "For each Warrior card under your character, each of your monsters that attacks this turn gets +10 attack until the end of turn."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Buff -- Monsters that attack this turn each get +10 attack until the end of turn."
    }

    function onThinkAction(player)
        insertCardTurnAction(player)

        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local n = getPlayerAttributes(player,"ELEM_WARRIOR")

        editCardRegister(src, cid, 0, 10, 0, nil)
        editCardRegister(src, cid, 1, n, 0, nil)
        incrementBuffEffect(player,src)
    end

    function onPrepareStartTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        editCardRegister(src, cid, 0, 0, 0, nil)
        editCardRegister(src, cid, 1, 0, 0, nil)
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, matchRequirements(player, 50, 2, "Warrior") and 10 or 0, 0, nil)
        editCardRegister(src, cid, 1, 1, 0, nil)
        incrementBuffEffect(player,src)
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        if(getCardRegister(src, cid, 0) ~= 10) then return end

        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,10 * getCardRegister(src, cid, 1),0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        if(getCardRegister(src, cid, 0) ~= 10) then return end

        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_ANY",src,10 * getCardRegister(src, cid, 1),0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end

}
