ZTCG_CARD
{

    "NAME" "Death Teddy"
    "IMAGE" "S4C037_DeathTeddy.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Undead Toy Bear"
    "COST" "750"

    TYPE_MOB
    {
        "LEVEL" "85"
        "ATTCK" "80"
        "HP" "80"
        "TEXT" "Leader 20 -- Each of your other Toy, Bear, and Undead monsters gets +20 attack and +20 HP. Tough -- Character actions don't damage Death Teddy."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "3"
        "TEXT" "Spawn 60 -- Play a monster of level 60 or less."
    }

    function preventTargetMob(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            return 1
        else
            return 0
        end
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Toy")
        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Bear")
        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Undead")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_OTHER",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Toy")
        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_OTHER",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Bear")
        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_OTHER",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Undead")
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 60"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",60)
    end

}
