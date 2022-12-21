ZTCG_CARD
{

    "NAME" "Fire Arrow"
    "IMAGE" "S2C024_FireArrow.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "520"

    TYPE_ACT
    {
        "LEVEL" "60"
        "TEXT" "Do 50 damage to a character or monster. Draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Spawn / Think Fast 50 -- Play a monster or tactic of level 50 or less. "
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        attack(player, src, 50, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")

        drawCard(player)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 50"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 50)
    end

}
