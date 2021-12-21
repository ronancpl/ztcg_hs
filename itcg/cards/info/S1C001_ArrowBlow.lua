ZTCG_CARD
{

    "NAME" "Arrow Blow"
    "IMAGE" "S1C001_ArrowBlow.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "500"

    TYPE_ACT
    {
        "LEVEL" "10"
        "TEXT" "Do 30 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Spawn / Think Fast 40 -- Play a Monster or tactic of level 40 or less. "
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        attack(player, src, 30, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 40"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 40)
    end

}
