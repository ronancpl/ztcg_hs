ZTCG_CARD
{

    "NAME" "Ice Sentinel"
    "IMAGE" "S5C065_IceSentinel.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Mechanical Ice Guardian"
    "COST" "670"

    TYPE_MOB
    {
        "LEVEL" "30"
        "ATTCK" "20"
        "HP" "20"
        "TEXT" "Stupefy -- When you play Ice Sentinel, your opponent can't play tactics next turn."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn 80 -- Play a monster of level 80 or less."
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
        local str = "Spawn 80"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",80)
    end

}
