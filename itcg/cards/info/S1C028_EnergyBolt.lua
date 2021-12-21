ZTCG_CARD
{

    "NAME" "Energy Bolt"
    "IMAGE" "S1C028_EnergyBolt.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "770"

    TYPE_ACT
    {
        "LEVEL" "40"
        "TEXT" "Do 80 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn / Think Fast 70 -- Play a monster or tactic of level 70 or less. "
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        attack(player, src, 80, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 70"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 70)
    end

}
