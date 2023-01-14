ZTCG_CARD
{
    "NAME" "Heaven Knight"
    "IMAGE" "heaven_knight.png"
    "TYPE" "BOSS"
    "ELEMENT" "LIGHT"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Light - Boss - Knight"
    "COST" "1777"

    TYPE_BOS
    {
        "LEVEL" "77"
        "ATTCK" "40"
        "HP" "120"

        LVL_ACTION
        {
            "LEVEL" "70"
            "ATTRB" "2"
            "TEXT" "Divine Haste - For the fated duel against his rival and clones, Heaven Knight learned to exchange blows swiftly. Heaven Knight attacks 3 times per turn."
        }

        LVL_ACTION
        {
            "TEXT" "Bonfire - On the quest to thwart his chaotic counterpart from destroying the Light, the knight has mastered dimensional traveling. Any attack to your character or equip gets retargeted to the knight with dmg reflected."
            "LEVEL" "0"
            "ATTRB" "0"
        }
    }

    function onThinkMob(player)
        if(matchRequirements(player, 70, 2, "ELEM_LIGHT")) then
            local src = getSourceCARD()
            addExtraMobAttack(src, src, 3)  -- just played this card, apply attack bonus
        end
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        if(matchRequirements(player, 70, 2, "ELEM_LIGHT")) then
            addExtraMobAttack(src, src, 3)  -- game environment HAS BEEN CHANGED, apply attack bonus
        end
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        if(matchRequirements(player, 70, 2, "ELEM_LIGHT")) then
            removeExtraMobAttack(src, src)      -- THIS FUNCTION ALWAYS UNDOES WHAT 'APPLYBUFFS' DOES, ALWAYS!
        end
    end

    function onInterceptAttack(player)
        local def_card = getCardPointer(1)

        if(hasSharedFlagsCARD(def_card, "FLAG_TYPE", "TYPE_CHAR | TYPE_EQP")) then
            local src = getSourceCARD()
            local cid = getCardIdFromCARD(src)

            setCardPointer(1, src)
            editCardRegister(src, cid, 0, 777, 0, null)  -- prepare counter!
        end
    end

    function onReceiveAttackCard(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if(getCardRegister(src, cid, 0) == 777) then
            editCardRegister(src, cid, 0, 0, 0, null)

            local dmg = getGameValue(0)     -- damage received will be returned to the attacker as a direct attack

            local atkr = getCardPointer(0)
            local atkr_slot = getSlotIdFromCARD(not player, atkr)
            attack(player, src, dmg, "ATKRES_FIXED_SLOT_DAMAGE", "ATKSRC_NIL", "SLOT_ADVSRYMOB" .. tostring(atkr_slot), "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_COUNTER")
        end
    end
}
