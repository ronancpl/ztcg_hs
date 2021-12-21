ZTCG_CARD
{

    "NAME" "Hector"
    "IMAGE" "S1C012_Hector.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Wolf"
    "COST" "610"

    TYPE_MOB
    {
        "LEVEL" "55"
        "ATTCK" "50"
        "HP" "50"
        "TEXT" "Pack Hunt -- Monsters that attack on the turn you play Hector each get +10 attack until end of turn (including Hector)."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn 70 -- Play a monster of level 70 or less. "
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 1, 0, nil)
    end

    function onCalcAttackCard(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            local src = getSourceCARD()
            local cid = getCardIdFromCARD(src)

            if getCardRegister(src, cid, 0) == 0 then   -- only on that one turn
                local dmg = getGameValue(0)
                updateGameValue(0, dmg + 10)
            end
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 70"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",70)
    end


}
