ZTCG_CARD
{

    "NAME" "Octopus"
    "IMAGE" "S1C040_Octopus.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Alien"
    "COST" "510"

    TYPE_MOB
    {
        "LEVEL" "12"
        "ATTCK" "10"
        "HP" "10"
        "TEXT" "Genius -- When you play Octopus, draw a card."
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
