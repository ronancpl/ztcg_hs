ZTCG_CARD
{

    "NAME" "Cold Beam"
    "IMAGE" "S3C018_ColdBeam.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Skill"
    "COST" "760"

    TYPE_ACT
    {
        "LEVEL" "35"
        "TEXT" "Your opponent's monsters each get -30 attack until your next turn starts."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "2"
        "TEXT" "Spawn / Think Fast 30 -- Play a monster or tactic of level 30 or less."
    }

    function onOpponentCalcAttackCard(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            local dmg = getGameValue(0) - 30
            updateGameValue(0,dmg)
        end
    end

    function onThinkAction(player)
        insertCardTurnAction(player)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 30"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 30)
    end

}
