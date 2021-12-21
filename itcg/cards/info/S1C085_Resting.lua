ZTCG_CARD
{

    "NAME" "Resting"
    "IMAGE" "S1C085_Resting.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Strategy"
    "COST" "570"

    TYPE_ACT
    {
        "LEVEL" "10"
        "TEXT" "You get +20 HP. Draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "1"
        "TEXT" "Spawn / Think Fast 90 -- Play a monster or tactic of level 90 or less. "
    }

    function onThinkAction(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,card,20)

        drawCard(player)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 90"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 90)
    end


}
