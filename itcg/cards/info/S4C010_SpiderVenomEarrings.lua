ZTCG_CARD
{

    "NAME" "Spider Venom Earrings"
    "IMAGE" "S4C010_SpiderVenomEarrings.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Jewelry"
    "COST" "560"

    TYPE_EQP
    {
        "LEVEL" "15"
        "TEXT" "When your turn ends, do 10 damage to each monster you damaged this turn. Then do 10 damage to each character you damaged this turn."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Equip 50 -- Play an item of level 50 or less."
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src,cid,0,0,0,nil)
    end

    function onExecuteAttackAndSurvived(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local n = getCardRegister(src,cid,0) + 1

        local card = getTargetCARD()
        local slotid = getSlotIdFromCARD(not player, card)

        local same = false
        for i = 1,n - 1,1 do
            local sid = getCardRegister(src,cid,i)
            if slotid == sid then
                same = true
                break
            end
        end

        if not same then
            editCardRegister(src,cid,n,slotid,0,nil)
            editCardRegister(src,cid,0,n,0,nil)
        end
    end

    function onEndTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local n = getCardRegister(src,cid,0)
        for i = 1, n, 1 do
            local slotid = getCardRegister(src,cid,i)

            local slotStr
            if slotid == 0 then
                slotStr = "SLOT_ADVSRYCHAR"
            else
                slotStr = "SLOT_ADVSRYMOB" .. tostring(slotid)
            end

            attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_EQP", slotStr, "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

    function onActivateCharacterAction(player)
        local str = "Equip 50"
        equip(player, "PLAY_NORMALEQUIP","ELEM_ANY",50)
    end

}
