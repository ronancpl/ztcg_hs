ZTCG_CARD
{

    "NAME" "Officer Skeleton"
    "IMAGE" "S1C081_OfficerSkeleton.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Undead Soldier"
    "COST" "550"

    TYPE_MOB
    {
        "LEVEL" "63"
        "ATTCK" "50"
        "HP" "60"
        "TEXT" "Bone Rattle -- Whenever one of your monsters destroys a monster, do 20 damage to your opponent's character."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Buff -- Monsters that attack this turn each get +10 attack until the end of the turn. "
    }

    function onAttackOpponentMobDestroyed(player)
        if hasFlag("ZTCG_ATKSRC","ATKSRC_MOB") then
            local src = getSourceCARD()
            attack(player, src, 20, "ATKRES_DONT_HIT_MOBS", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

    function onStartTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        editCardRegister(src, cid, 0, 0, 0, nil)
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, matchRequirements(player, 50, 2, "Warrior") and 10 or 0, 0, nil)
        incrementBuffEffect(player,src)
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        if(getCardRegister(src, cid, 0) ~= 10) then return end

        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,10,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        if(getCardRegister(src, cid, 0) ~= 10) then return end

        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_ANY",src,10,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end
}
