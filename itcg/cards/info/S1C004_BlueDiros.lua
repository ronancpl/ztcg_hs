ZTCG_CARD
{

    "NAME" "Blue Diros"
    "IMAGE" "S1C004_BlueDiros.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Armor"
    "COST" "450"

    TYPE_EQP
    {
        "LEVEL" "20"
        "TEXT" "The first monster that attacks you each turn gets -10 attack until end of turn."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "2"
        "TEXT" "Equip 30 -- Play an item of level 30 or less. "
    }

    function onEquipBlockDamage(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            if(getCardRegister(src, cid, 0) ~= 777) then
                return 10
            end
        end
    end

    function onInterceptAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            if getCardRegister(src, cid, 0) ~= 777 then
                editCardRegister(src, cid, 0, 777, 0, nil)

                local atkr = getCardPointer(0)
                incrementBuffEffect(player,src)
                newBuff(atkr,src,-10,0,0,1)
            end
        end
    end

    function onStartTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        editCardRegister(src, cid, 0, 0, 0, nil)
    end

    function onActivateCharacterAction(player)
        equip(player, "PLAY_NORMALEQUIP","ELEM_ANY",30)
    end

}
