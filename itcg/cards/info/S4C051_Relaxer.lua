ZTCG_CARD
{

    "NAME" "Relaxer"
    "IMAGE" "S4C051_Relaxer.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Chair"
    "COST" "700"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "When your turn ends, if you didn't play any tactic or item cards this turn other than this card, get +20 HP."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Refresh -- You get +10 HP."
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        editCardRegister(src,cardid,0,0,0,nil)
    end

    function afterThinkEquipment(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        editCardRegister(src,cardid,0,0,0,nil)
    end

    function onPlayAction(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        editCardRegister(src,cardid,0,1,0,nil)
    end

    function onPlayEquipment(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        editCardRegister(src,cardid,0,1,0,nil)
    end

    function onEndTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local res = getCardRegister(src,cardid,0)
        if res == 0 then
            local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            refreshHP(player,card,20)
        end
    end

    function onActivateCharacterAction(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,card,10)
    end

}
