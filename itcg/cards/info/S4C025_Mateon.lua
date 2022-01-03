ZTCG_CARD
{

    "NAME" "Mateon"
    "IMAGE" "S4C025_Mateon.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Mechanical Alien"
    "COST" "630"

    TYPE_MOB
    {
        "LEVEL" "41"
        "ATTCK" "10"
        "HP" "40"
        "TEXT" "Genius -- When you play Mateon, draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Quest -- Draw a card."
    }

    function onThinkMob(player)
        drawCard(player)
    end

    function onLevelActionTrigger(player)
        drawCard(player)
    end

}
