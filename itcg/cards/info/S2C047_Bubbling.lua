ZTCG_CARD
{

    "NAME" "Bubbling"
    "IMAGE" "S2C047_Bubbling.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Goo"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "12"
        "ATTCK" "10"
        "HP" "30"
        "TEXT" "Ooze -- Whenever Bubbling is damaged prevent all other damage to it this turn."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Spawn 60 -- Play a monster of level 60 or less. "
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        editCardRegister(src,cardid,0,0,0,nil)
    end

    function onReceiveNormalAttack(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        editCardRegister(src,cardid,0,1,0,nil)
    end

    function preventTargetMob(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        if getCardRegister(src,cardid,0) ~= 0 then
            return 1
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 60"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",60)
    end

}
