ZTCG_CARD
{

    "NAME" "Angry Hector"
    "IMAGE" "S5C001_AngryHector.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Wolf"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "55"
        "ATTCK" "50"
        "HP" "50"
        "TEXT" "Raise Hackles -- When you play Angry Hector, clash with your opponent. If you win, monsters that attack this turn each get +30 attack until end of turn. (To clash, each player reveals the top card of their deck, then puts it on top or bottom. Whoever revealed the highest-level card wins.)"
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "3"
        "TEXT" "Spawn 100 -- Play a monster of level 100 or less."
    }

    function undoBuffs(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        if getSlotIdFromCARD(player,src) < 0 or getCardRegister(src,cardid,0) == 0 then return end

        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,30,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        if getSlotIdFromCARD(player,src) < 0 or getCardRegister(src,cardid,0) == 0 then return end

        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_ANY",src,30,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end

    function onPrepareStartTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        editCardRegister(src,cardid,0,0,0,nil)
    end

    function onThinkMob(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        if playClash(player) then
            editCardRegister(src,cardid,0,1,0,nil)

            applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_ANY",src,30,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 100"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",100)
    end

}
