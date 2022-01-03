ZTCG_CARD
{

    "NAME" "Cody"
    "IMAGE" "S4C034_Cody.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Human NPC"
    "COST" "630"

    TYPE_MOB
    {
        "LEVEL" "10"
        "ATTCK" "20"
        "HP" "10"
        "TEXT" "NPC Quest -- Play at least one item on your turn. Reward -- On your opponent's next turn, all of your monsters are Tough."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "1"
        "TEXT" "Spawn 20 -- Play a monster of level 20 or less."
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        editCardRegister(src,cardid,0,0,0,nil)
    end

    function onPlayEquipment(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        editCardRegister(src,cardid,0,1,0,nil)
    end

    function preventTargetMob(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local ret = getCardRegister(src,cardid,0)
        if ret > 0 and hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            return 1
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 20"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",20)
    end

}
