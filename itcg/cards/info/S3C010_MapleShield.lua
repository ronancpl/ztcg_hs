ZTCG_CARD
{

    "NAME" "Maple Shield"
    "IMAGE" "S3C010_MapleShield.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Shield"
    "COST" "680"

    TYPE_EQP
    {
        "LEVEL" "20"
        "TEXT" "Each of your monsters gets +10 HP."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Spawn 50 -- Play a monster of level 50 or less."
    }

    function undoBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        local src = getSourceCARD()
        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,0,10,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        local src = getSourceCARD()
        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_ANY",src,0,10,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 50"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",50)
    end

}
