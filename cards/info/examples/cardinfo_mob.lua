ZTCG_CARD
{
    "NAME" "creep"
    "IMAGE" "base_card.png"
    "TYPE" "MOB"
    "ELEMENT" "EARTH"
    "RARITY" "7"
    "INFO" "BATTLEFIELD"
    "COST" "200"

    TYPE_MOB
    {

        "LEVEL" "10"
        "ATTCK" "10"
        "HP" "20"

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
