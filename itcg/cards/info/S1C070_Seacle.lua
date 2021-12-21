ZTCG_CARD
{

    "NAME" "Seacle"
    "IMAGE" "S1C070_Seacle.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Water Beast"
    "COST" "450"

    TYPE_MOB
    {
        "LEVEL" "23"
        "ATTCK" "20"
        "HP" "20"
        "TEXT" "Slippery -- When Seacle is destroyed, flip a coin. If you win, return it to play."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Spawn / Think Fast 30 -- Play a monster or tactic of level 30 or less. "
    }

    function onReceiveAttackAndDestroyed()
        if throwCoin(player) then
            local src = getSourceCARD()
            recoverDestroyedCard(player,src)
            summon(player, "PLAY_SCOUTSUMMON","ELEM_ANY","ZTCG_MAXVALUE")
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 30"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 30)
    end

}
