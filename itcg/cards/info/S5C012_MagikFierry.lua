ZTCG_CARD
{

    "NAME" "Magik Fierry"
    "IMAGE" "S5C012_MagikFierry.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Flying Fierry"
    "COST" "650"

    TYPE_MOB
    {
        "LEVEL" "30"
        "ATTCK" "30"
        "HP" "20"
        "TEXT" "Magician Proof -- Magician cards don't damage Magik Fierry."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "1"
        "TEXT" "Spawn / Think Fast 50 -- Play a monster or tactic of level 50 or less."
    }

    function preventTargetMob(player)
        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_ELEM", "ELEM_MAGE")) then
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
