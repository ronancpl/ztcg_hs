ZTCG_CARD
{
    LVL_ACTION
        {
            "LEVEL" "ZTCG_MAXVALUE"
            "TEXT" "Critical Blow - Do 50 damage."
        }

    TYPE_FLD
    {
        "TEXT" "SIGHTSEE"
    }

    "NAME" "Mountain Range"
    "IMAGE" "base_card.png"
    "TYPE" "FIELD"
    "ELEMENT" "WIND"
    "RARITY" "RARITY_COMMON"
    "INFO" "Mountain"
    "COST" "300"

    function onPlay(x)
        action(x)
    end

    function onDrawCard(x,y)
        action2(x,y)
    end

}
