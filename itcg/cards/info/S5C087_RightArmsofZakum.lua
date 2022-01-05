ZTCG_CARD
{

    "NAME" "Right Arms of Zakum"
    "IMAGE" "S5C087_RightArmsofZakum.png"
    "TYPE" "MOB"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Zakum Arms"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "80"
        "ATTCK" "80"
        "HP" "50"
        "TEXT" "Zeitgeist 20 -- Each of your other Zakum monsters gets +20 attack."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "0"
        "TEXT" "Zpawn -- Play a monster of level 60 or less, or play a Zakum card of level 90 or less."
    }

    function undoBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        removeAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,20,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Zakum")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        applyAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,20,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Zakum")
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 60"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",60)
    end

}
