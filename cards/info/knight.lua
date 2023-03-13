ZTCG_CARD
{
    "NAME" "Knight"
    "IMAGE" "knight.png"
    "INFO" "Light - Character"  -- Lua-like line comments can be used at these card descriptor files.
    "TYPE" "CHAR"
    "ELEMENT" "LIGHT"
    "RARITY" "RARITY_UNIQUE"
    "COST" "777"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "0"
            "TEXT" "Mission - Draw a card."
        }

        LVL_ACTION
        {
            "LEVEL" "30"
            "ATTRB" "2"
            "TEXT" "Slash - Do 20 damage to a character or monster."
        }

        LVL_ACTION
        {
            "LEVEL" "60"
            "ATTRB" "3"
            "TEXT" "Graal Blessings - Grant all LIGHT mobs with +10 ATK and +10 HP."
        }

        "HP" "240"
    }

    function onActivateCharacterAction1(player)
        -- every character should have a draw card effect as a basic skill.
        drawCard(player)
    end

    function onActivateCharacterAction2(player)
        local attacker = getSourceCARD()    -- this card
        attack(player, attacker, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction3(player)
        -- aura effect: "applyBuffs" , "undoBuffs"

        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 10, 0, nil)
        incrementBuffEffect(player,src)
    end

    function undoBuffs(player)
        -- aura only takes effect if character is LEVEL 60+ and has 3+ LIGHT-type cards under it.

        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        if(getCardRegister(src, cid, 0) ~= 10 or not matchRequirements(player, 60, 3, "ELEM_LIGHT")) then return end

        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,10,10,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_LIGHT", "ZTCG_NIL")
    end

    function applyBuffs(player)
        -- aura only takes effect if character is LEVEL 60+ and has 3+ LIGHT-type cards under it.

        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        if(getCardRegister(src, cid, 0) ~= 10 or not matchRequirements(player, 60, 3, "ELEM_LIGHT")) then return end

        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_ANY",src,10,10,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_LIGHT", "ZTCG_NIL")
    end

}
