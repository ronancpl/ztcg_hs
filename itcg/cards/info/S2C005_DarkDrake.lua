ZTCG_CARD
{

    "NAME" "Dark Drake"
    "IMAGE" "S2C005_DarkDrake.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Dark Flying Dragon"
    "COST" "770"

    TYPE_MOB
    {
        "LEVEL" "68"
        "ATTCK" "50"
        "HP" "50"
        "TEXT" "Leader 20 -- Each of your other Flying, Dragon, and Dark Monsters gets +20 attack and +20 HP. Shadow Sky -- Each of your Flying monsters gets Stealthy."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn / Think Fast 70 -- Play a monster or tactic of level 70 or less. "
    }

    function preventIntercomeTargetMob(player)
        local target = getTargetCARD()
        if isInfoCARD(target, "Flying") then
            if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
                return 1
            else
                return 0
            end
        end

        return 0
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Flying")
        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Dragon")
        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Dark")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_OTHER",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Flying")
        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_OTHER",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Dragon")
        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_OTHER",src,20,20,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Dark")
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 70"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 70)
    end

}
