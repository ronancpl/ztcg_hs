ZTCG_CARD
{
    "NAME" "Knight"
    "IMAGE" "knight.png"
    "INFO" "Light - Character"  -- Lua-like line comments can be used at these card descriptor files.
    "TYPE" "CHAR"
    "ELEMENT" "LIGHT"
    "RARITY" "1"
    "COST" "777"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "0"
            "TEXT" "Mission - Draw Card"
        }

        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "0"
            "TEXT" "Slash - Do 20 damage to a character or monster."
        }

        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "0"
            "TEXT" "Graal Blessings - Grant all LIGHT mobs with +10 ATK and +20 HP."
        }

        "HP" "240"
    }

    function onActivateCharacterAction1(player)
        -- every character should have a draw card effect.
        drawCard(player);
    end

    function onActivateCharacterAction2(player)
        destroySelf(player,"SLOT_ADVSRYMOB1")
    end

    function onActivateCharacterAction3(player)
        local atkr = getSourceCARD();

        if(throwCoin(player)) then
            attackGlobal("GLOBAL_HITMOBS", player, atkr, 999, "ATKSRC_NIL", "PREVENT_ATTACK", "COUNTER_ATTACK", "USE_FILTER", 0, 10, 20, "TYPE_MOB", "ELEM_EARTH | ELEM_WIND", 0)
        else
            attackGlobal("GLOBAL_HITCHAR", player, atkr, 999, "ATKSRC_NIL", "PREVENT_ATTACK", "COUNTER_ATTACK", "USE_FILTER", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_CHAR | TYPE_MOB", "ELEM_WATER | ELEM_EARTH", "ZTCG_NIL")
        end
    end

}
