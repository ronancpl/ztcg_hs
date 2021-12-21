ZTCG_CARD
{

    "NAME" "Zeta Gray"
    "IMAGE" "S1C047_ZetaGray.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Alien"
    "COST" "490"

    TYPE_MOB
    {
        "LEVEL" "42"
        "ATTCK" "20"
        "HP" "20"
        "TEXT" "Genius -- When you play Zeta Gray, draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Quest -- Draw a card. "
    }

    function onThinkMob(player)
        drawCard(player)
    end

    function onLevelActionTrigger(player)
        drawCard(player)
    end

}
