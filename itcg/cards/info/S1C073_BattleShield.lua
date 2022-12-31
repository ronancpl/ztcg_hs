ZTCG_CARD
{

    "NAME" "Battle Shield"
    "IMAGE" "S1C073_BattleShield.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Shield"
    "COST" "500"

    TYPE_EQP
    {
        "LEVEL" "35"
        "TEXT" "Each of your monsters gets +20 HP."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Think Fast / Equip 40 -- Play a tactic or equip of level 40 or less. "
    }

    function undoBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        local src = getSourceCARD()
        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,0,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        local src = getSourceCARD()
        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_ANY",src,0,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 40"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 40)
    end


}
