ZTCG_CARD
{

    "NAME" "Mia"
    "IMAGE" "S4C008_Mia.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Human NPC"
    "COST" "560"

    TYPE_MOB
    {
        "LEVEL" "5"
        "ATTCK" "10"
        "HP" "20"
        "TEXT" "NPC Quest -- Mia or another of your monsters attacks. Reward -- You get +10 HP."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "2"
        "TEXT" "Spawn 30 -- Play a monster of level 30 or less."
    }

    function onAttackOpponentMobDestroyed(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            refreshHP(player,card,10)
        end
    end

    function onExecuteAttackAndSurvived(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            refreshHP(player,card,10)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 30"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",30)
    end

}
