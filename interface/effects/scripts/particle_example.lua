ZTCG_SPRITE
{
    "SOURCE" "ZPsprites.jpg"
    "COUNT" "8"

    "LIFE" "10"
    "SCALE" "1"
    "DELAY" "0"



    "BLENDTYPE" "BLEND_SRC_MINUS_DEST" -- "BLEND_DEST_MINUS_SRC" "BLEND_ADD"

    TINT
    {
        "RED" "255"
        "GREEN" "255"
        "BLUE" "255"
        "ALPHA" "255"
    }

    MOVEMENT
    {
        "DX" "1"
        "DY" "1"

        "RAND_DX" "3"
        "RAND_DY" "50"
    }

    function onActivateCharacterAction(player)
        locate(player,"PLAY_NORMALFIELD","ELEM_ANY")
    end

    function onStartTurn(player)
        -- IF character CARD does not have the same element as the field, nothing happens
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        if(hasSharedFlagsCARD(card, "FLAG_ELEM", "ELEM_EARTH")) then
            local attr = getPlayerAttributes(player, "ELEM_EARTH")
            setFieldRegister(player, attr)
        end
    end

    function onOpponentStartTurn(player)    -- on onOpponent series, 'player' refers to the adversary
        local op_field = getOnBoardCARD(player, "SLOT_PLAYERFLD")

        -- opponent does not have a field, share this player field effects
        if(isNullCARD(op_field)) then
            local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            if(hasSharedFlagsCARD(card, "FLAG_ELEM", "ELEM_EARTH")) then
                local attr = getPlayerAttributes(player, "ELEM_EARTH")  -- opponent can share field perks if it doesnt own a field
                setFieldRegister(player, attr)
            end
        end
    end

    function onThinkField(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        if(hasSharedFlagsCARD(card, "FLAG_ELEM", "ELEM_EARTH")) then
            local attr = getPlayerAttributes(player, "ELEM_EARTH")
            setFieldRegister(player, attr)
        end

        local card2 = getOnBoardCARD(player, "SLOT_ADVSRYCHAR")
        if(hasSharedFlagsCARD(card2, "FLAG_ELEM", "ELEM_EARTH")) then
            local op_field = getOnBoardCARD(player, "SLOT_ADVSRYFLD")
            if(isNullCARD(op_field)) then
                local attrb = getPlayerAttributes(not player, "ELEM_EARTH")  -- opponent can share field perks if it doesnt own a field
                setFieldRegister(not player, attrb)
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
