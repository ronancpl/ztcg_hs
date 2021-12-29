ZTCG_CARD
{

    "NAME" "Sneaky Twink"
    "IMAGE" "S2C041_SneakyTwink.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Strategy"
    "COST" "560"

    TYPE_ACT
    {
        "LEVEL" "20"
        "TEXT" "Get +20 to your level until end of turn."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Spawn / Think Fast 40 -- Play a monster or tactic of level 40 or less. "
    }

    function onThinkAction(player)
        incrementPlayerLevel(player, 20)
        insertCardTurnAction(player)
    end

    function onEndTurn(player)
        incrementPlayerLevel(player, -20)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 40"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 40)
    end

}
