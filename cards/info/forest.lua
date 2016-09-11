ZTCG_CARD
{
    "NAME" "Forest"
    "IMAGE" "forest.png"
    "INFO" "Earth - Field - Forest"
    "TYPE" "FIELD"
    "ELEMENT" "EARTH"
    "RARITY" "3"
    "COST" "1000"

    TYPE_FLD
    {
        "BLOCK" "10"
        "TEXT" "Add +20 attack and +10 HP to each EARTH monster in game. If your character is a EARTH character, add +10 attack to each character actions, and block 10 damage for each opponent actions, effects limited up to as many EARTH cards you have under your character."
    }

    LVL_ACTION
    {
        "ATTRB" "3"
        "LEVEL" "50"
        "TEXT" "Locate - Play a field card."
    }

    function onActivateCharacterAction(player)
        locate(player, "PLAY_NORMALFIELD")
    end

    function onStartTurn(player)
        -- IF character CARD does not have the same element as the field, nothing happens
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        if(hasSharedFlagsCARD(card, "FLAG_ELEM", "ELEM_EARTH")) then
            local attr = getPlayerAttributes(player, "ELEM_EARTH")
            setFieldCounter(player, attr)
        end
    end

    function onOpponentStartTurn(player)    -- on onOpponent series, 'player' refers to the adversary
        local op_field = getOnBoardCARD(player, "SLOT_PLAYERFLD")

        -- opponent does not have a field, share this player field effects
        if(isNullCARD(op_field)) then
            local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            if(hasSharedFlagsCARD(card, "FLAG_ELEM", "ELEM_EARTH")) then
                local attr = getPlayerAttributes(player, "ELEM_EARTH")  -- opponent can share field perks if it doesnt own a field
                setFieldCounter(player, attr)
            end
        end
    end

    function onThinkField(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        if(hasSharedFlagsCARD(card, "FLAG_ELEM", "ELEM_EARTH")) then
            local attr = getPlayerAttributes(player, "ELEM_EARTH")
            setFieldCounter(player, attr)
        end

        local card2 = getOnBoardCARD(player, "SLOT_ADVSRYCHAR")
        if(hasSharedFlagsCARD(card2, "FLAG_ELEM", "ELEM_EARTH")) then
            local op_field = getOnBoardCARD(player, "SLOT_ADVSRYFLD")
            if(isNullCARD(op_field)) then
                local attrb = getPlayerAttributes(not player, "ELEM_EARTH")  -- opponent can share field perks if it doesnt own a field
                setFieldCounter(not player, attrb)
            end
        end
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        removeAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,20,10,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_EARTH", "ZTCG_NIL")
        removeAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,10,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_CHAR", "ELEM_EARTH", "ZTCG_NIL")

        -- apply buffs on adversary mobs too if they dont have a field card
        local adv_field = getOnBoardCARD(player, "SLOT_ADVSRYFLD")
        if(not isNullCARD(adv_field)) then return end

        removeAuraBonus(player, "GLOBALAURA_PASS_PLAYER",src,20,10,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_EARTH", "ZTCG_NIL")
        removeAuraBonus(player, "GLOBALAURA_PASS_PLAYER",src,10,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_CHAR", "ELEM_EARTH", "ZTCG_NIL")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        applyAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,20,10,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_EARTH", "ZTCG_NIL")
        applyAuraBonus(player, "GLOBALAURA_PASS_ADVSRY",src,10,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_CHAR", "ELEM_EARTH", "ZTCG_NIL")

        -- apply buffs on adversary mobs too if they dont have a field card
        local adv_field = getOnBoardCARD(player, "SLOT_ADVSRYFLD")
        if(not isNullCARD(adv_field)) then return end

        applyAuraBonus(player, "GLOBALAURA_PASS_PLAYER",src,20,10,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_EARTH", "ZTCG_NIL")
        applyAuraBonus(player, "GLOBALAURA_PASS_PLAYER",src,10,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_CHAR", "ELEM_EARTH", "ZTCG_NIL")
    end
}
