ZTCG_CARD
{

    "NAME" "Mad Grizzly"
    "IMAGE" "S5C069_MadGrizzly.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Bear"
    "COST" "650"

    TYPE_MOB
    {
        "LEVEL" "56"
        "ATTCK" "40"
        "HP" "50"
        "TEXT" "Bowman Proof -- Bowman cards don't damage Mad Grizzly."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Scout -- Reveal the top card of your deck. If it's a monster card, put it into your hand. Otherwise put it back."
    }

    function preventTargetMob(player)
        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_ELEM", "ELEM_BOWMAN")) then
            return 1
        else
            return 0
        end
    end

    function onLevelActionTrigger(player)
        scoutMob(player,"SCOUT_NORMAL","ELEM_ANY")
    end

}
