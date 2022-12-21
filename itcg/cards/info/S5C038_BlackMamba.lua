ZTCG_CARD
{

    "NAME" "Black Mamba"
    "IMAGE" "S5C038_BlackMamba.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Zakum Weapon"
    "COST" "700"

    TYPE_EQP
    {
        "LEVEL" "80"
        "TEXT" "Double the attack value of each monster you have."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "2"
        "TEXT" "Elite Equip Unlimited -- Play an item card. If it's the highest-level item in play, draw a card."
    }

    function onEquipBuff(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            return getGameValue(0)  -- double damage value
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local slot1 = nextFreeEquipSlot(player)

        local str = "Equip Unlimited"
        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY","ZTCG_MAXVALUE")

        local slot2 = nextFreeEquipSlot(player)
        if slot1 ~= slot2 then
            local slot = -1
            local maxLevel = -1

            for i = 1, 7, 1 do
                local eqp = getOnBoardCARD(player,"SLOT_PLAYEREQP" .. tostring(i))
                if eqp ~= 0 then
                    local level = getCurrentLevelFromCARD(player, eqp)
                    if level > maxLevel then
                        slot = i
                        maxLevel = level
                    end
                end
            end

            if slot == slot1 then
                drawCard(player)
            end
        end
    end

}
