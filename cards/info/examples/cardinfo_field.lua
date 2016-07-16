ZTCG_CARD
{
    LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "1"
            "TEXT" "Noob Attack - Do 10 damage."
        }

    TYPE_FLD
    {
        "TEXT" "SIGHTSEE"
    }

    "NAME" "Mountain Range"
    "IMAGE" "base_card.png"
    "TYPE" "FIELD"
    "ELEMENT" "WIND"
    "RARITY" "7"
    "INFO" "Mountain"
    "COST" "300"

    function onPlay(x)
        action(x)
    end

    function onDrawCard(x,y)
        action2(x,y)
    end

}
