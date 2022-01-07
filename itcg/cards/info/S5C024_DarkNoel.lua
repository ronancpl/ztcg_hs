ZTCG_CARD
{

    "NAME" "Dark Noel"
    "IMAGE" "S5C024_DarkNoel.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Armor"
    "COST" "640"

    TYPE_EQP
    {
        "LEVEL" "35"
        "TEXT" "Shield 10 -- Whenever your character would take damage, prevent 10 of that damage."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Think Fast / Equip 50 -- Play a tactic or item of level 50 or less."
    }

    function undoBuffs(player)
        local src = getSourceCARD()
        local slot = getSlotIdFromCARD(player, src)
        if slot < 0 then return end

        removeAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,0,0,10,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_CHAR", "ELEM_ANY", "ZTCG_NIL")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        local slot = getSlotIdFromCARD(player, src)
        if slot < 0 then return end

        applyAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,0,0,10,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_CHAR", "ELEM_ANY", "ZTCG_NIL")
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 50"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 50)
    end

}
