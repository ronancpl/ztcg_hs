ZTCG_CARD
{
    LVL_ACTION
    {
        "LEVEL" "999"
        "ATTRB" "2"
        "TEXT" "Draw a card."
    }

    "NAME" "tact"
    "IMAGE" "base_card.png"
    "TYPE" "ACTION"
    "ELEMENT" "WATER"
    "RARITY" "7"
    "INFO" "Water - Tactic - Recovery"
    "COST" "500"

    TYPE_ACT
    {
        "LEVEL" "70"
        "TEXT" "Save your character."
    }

    function onPlay(x)
        action(x)
    end

    function onDrawCard(x,y)
        action2(x,y)
    end

}
