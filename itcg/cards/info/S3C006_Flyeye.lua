ZTCG_CARD
{

    "NAME" "Flyeye"
    "IMAGE" "S3C006_Flyeye.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Flying Beast"
    "COST" "850"

    TYPE_MOB
    {
        "LEVEL" "41"
        "ATTCK" "40"
        "HP" "30"
        "TEXT" "Stupefy -- When you play Flyeye, your opponent can't play tactics next turn."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "3"
        "TEXT" "Deadly Shot -- Do 30 damage to a character or monster."
    }

    function onOpponentPlayActionCancel(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if getCardRegister(src, cid, 0) ~= 0 then
            return 1
        else
            return 0
        end
    end

    function onStartTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 0, 0, nil)
    end

    function onThinkMob(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 5, 0, nil)
    end

    function onActivateCharacterAction(player)
        local atkr = getSourceCARD()
        attack(player, atkr, 30, "ATKRES_NIL", "ATKSRC_MOB", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}