ZTCG_CARD
{

    "NAME" "Flower Fish"
    "IMAGE" "S5C043_FlowerFish.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Water Fish"
    "COST" "650"

    TYPE_MOB
    {
        "LEVEL" "29"
        "ATTCK" "20"
        "HP" "30"
        "TEXT" "Warrior Proof -- Warrior cards don't damage Flower Fish."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Spawn / Think Fast 50 -- Play a monster or tactic of level 50 or less."
    }

    function preventTargetMob(player)
        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_ELEM", "ELEM_WARRIOR")) then
            return 1
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 50"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 50)
    end

}
