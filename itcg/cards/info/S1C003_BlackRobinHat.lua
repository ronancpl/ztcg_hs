ZTCG_CARD
{

    "NAME" "Black Robin Hat"
    "IMAGE" "S1C003_BlackRobinHat.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Armor"
    "COST" "700"

    TYPE_EQP
    {
        "LEVEL" "20"
        "TEXT" "Each of your Flying monsters gets +10 attack."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Tricky Shot -- Do 20 damage to a character or monster. "
    }

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        local src = getSourceCARD()
        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,10,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Flying")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        local src = getSourceCARD()
        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_ANY",src,10,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Flying")
    end

}
