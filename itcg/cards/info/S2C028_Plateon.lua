ZTCG_CARD
{

    "NAME" "Plateon"
    "IMAGE" "S2C028_Plateon.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Mechanical Alien"
    "COST" "510"

    TYPE_MOB
    {
        "LEVEL" "44"
        "ATTCK" "30"
        "HP" "10"
        "TEXT" "Genius -- When you play Plateon, draw a card."
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
