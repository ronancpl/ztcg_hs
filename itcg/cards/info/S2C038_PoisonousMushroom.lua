ZTCG_CARD
{

    "NAME" "Poisonous Mushroom"
    "IMAGE" "S2C038_PoisonousMushroom.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Food"
    "COST" "500"

    TYPE_EQP
    {
        "LEVEL" "30"
        "TEXT" "The next time your opponent plays a monster, destroy that monster and this item."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Spawn / Equip 30 -- Play a monster or item of level 30 or less. "
    }

    function destroyCardSlot(player, card, tableStr, isEqp)
        if isBossCARD(card) then return end

        local ret = false
        local slotid = getSlotIdFromCARD(player, card)
        if slotid > 0 then
            destroyCard(player,tableStr .. (isEqp and (slotid - 7) or slotid))
            ret = true
        end

        return ret
    end

    function onOpponentPlayMob(player)
        local target = getTargetCARD()
        local src = getSourceCARD()

        if target ~= 0 then
            if destroyCardSlot(not player, target, "SLOT_PLAYERMOB", false) then
                destroyCardSlot(player, src, "SLOT_PLAYEREQP", true)
            end
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 30"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 30)
    end

}
