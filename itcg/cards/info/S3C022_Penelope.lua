ZTCG_CARD
{

    "NAME" "Penelope"
    "IMAGE" "S3C022_Penelope.png"
    "TYPE" "CHAR"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Character - Fire/Poison Mage"
    "COST" "800"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" ""
            "ATTRB" ""
            "TEXT" ""
        }
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card."
        }
        LVL_ACTION
        {
            "LEVEL" "60"
            "ATTRB" "2"
            "TEXT" "Quest -- Draw a card."
        }
        "HP" "180"
    }

    function onActivateCharacterAction1(player)
    end

    function onActivateCharacterAction2(player)
        drawCard(player)
    end

    function onActivateCharacterAction3(player)
        drawCard(player)
    end

}
