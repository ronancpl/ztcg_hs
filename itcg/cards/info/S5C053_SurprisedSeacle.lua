ZTCG_CARD
{

    "NAME" "Surprised Seacle"
    "IMAGE" "S5C053_SurprisedSeacle.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Water Beast"
    "COST" "420"

    TYPE_MOB
    {
        "LEVEL" "23"
        "ATTCK" "30"
        "HP" "10"
        "TEXT" "Lucky Day -- When Surprised Seacle is destroyed, clash with your opponent. If you win, return it to play. (To clash, each player reveals the top card of their deck, then puts it on top or bottom. Whoever revealed the highest-level card wins.)"
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Spawn / Think Fast 30 -- Play a monster or tactic of level 30 or less."
    }

    function onReceiveAttackAndInterceptDestroyed(player)
        local src = getSourceCARD()

        if playClash(player) then
            local destroyed = updateGameValue(0,0)  -- not destroyed

            refreshHP(player,src,"ZTCG_MAXVALUE")
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 30"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 30)
    end

}
