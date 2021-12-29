ZTCG_CARD
{

    "NAME" "MT-09"
    "IMAGE" "S2C027_MT9.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Mechanical Alien"
    "COST" "570"

    TYPE_MOB
    {
        "LEVEL" "54"
        "ATTCK" "30"
        "HP" "30"
        "TEXT" "Genius -- When you play MT-09, draw a card. Leader 10 -- Each of your other Alien and Mechanical monsters gets +10 attack and +10 HP."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "3"
        "TEXT" "Blast -- Do 40 damage to a character. "
    }

    function onThinkMob(player)
        drawCard(player)
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        local src = getSourceCARD()
        removeAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,10,10,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Alien")
        removeAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,10,10,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Mechanical")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        local src = getSourceCARD()
        applyAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,10,10,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Alien")
        applyAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,10,10,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Mechanical")
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 40, "ATKRES_DONT_HIT_MOBS", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
