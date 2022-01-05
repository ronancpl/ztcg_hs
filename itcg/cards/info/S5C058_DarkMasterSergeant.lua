ZTCG_CARD
{

    "NAME" "Dark Master Sergeant"
    "IMAGE" "S5C058_DarkMasterSergeant.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Armor"
    "COST" "630"

    TYPE_EQP
    {
        "LEVEL" "25"
        "TEXT" "Each of your monsters gets Armored 10. (Whenever one of your monsters would be damaged, prevent 10 of that damage.)"
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 50 -- Play a monster or item of level 50 or less."
    }

    function undoBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        removeAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,0,0,10,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        applyAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,0,0,10,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 50"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 50)
    end

}
