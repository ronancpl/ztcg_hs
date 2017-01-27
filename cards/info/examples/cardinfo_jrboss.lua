ZTCG_CARD
{
    "NAME" "great figure"
    "IMAGE" "base_card.png"
    "TYPE" "JRBOSS"
    "ELEMENT" "LIGHT"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Ternuria"
    "COST" "1000"

    TYPE_JRB
    {
        LVL_ACTION
        {
            "LEVEL" "80"
            "ATTRB" "3"
            "TEXT" "Sonic Boom - Reduces opponents HP to 1."
        }

        "LEVEL" "130"
        "ATTCK" "70"
        "HP" "120"
    }

    LVL_ACTION
    {
        "LEVEL" "10"
        "ATTRB" "1"
        "TEXT" "Noob Attack - Do 10 damage."
    }

    function onPlay(x)
        action(x)
    end

    function onDrawCard(x,y)
        action2(x,y)
    end

}
