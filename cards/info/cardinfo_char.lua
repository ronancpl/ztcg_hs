ZTCG_CARD
{
    "NAME" "Avatar"
    "IMAGE" "base_card.png"
    "TYPE" "CHAR"
    "ELEMENT" "DARK"
    "RARITY" "7"
    "INFO" "random things"
    "COST" "777"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "0"
            "TEXT" "Mission - Draw Card"
        }

        LVL_ACTION
        {
            "LEVEL" "100"
            "ATTRB" "3"
            "TEXT" "OP Attack - Do 100 damage."
        }

        LVL_ACTION
        {
            "LEVEL" "50"
            "ATTRB" "1"
            "TEXT" "Attack - Do 10 damage to all."
        }

        "HP" "20"
    }

    function onPlay(x)
        action(x)
    end

    function onDrawCard(x,y)
        action2(x,y)
    end

}
