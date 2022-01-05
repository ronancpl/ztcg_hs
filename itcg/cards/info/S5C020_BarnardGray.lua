ZTCG_CARD
{

    "NAME" "Barnard Gray"
    "IMAGE" "S5C020_BarnardGray.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Alien"
    "COST" "630"

    TYPE_MOB
    {
        "LEVEL" "40"
        "ATTCK" "30"
        "HP" "30"
        "TEXT" "Thief Proof -- Thief cards don't damage Barnard Gray."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Quest -- Draw a card."
    }

    function preventTargetMob(player)
        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_ELEM", "ELEM_THIEF")) then
            return 1
        else
            return 0
        end
    end

    function onLevelActionTrigger(player)
        drawCard(player)
    end

}
