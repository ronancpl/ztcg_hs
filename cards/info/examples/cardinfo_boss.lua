ZTCG_CARD
{
    "NAME" "noob"
    "IMAGE" "base_card.png"
    "TYPE" "BOSS"
    "ELEMENT" "FIRE"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "random things"
    "COST" "777"

    TYPE_BOS
    {
        LVL_ACTION
        {
            "LEVEL" "100"
            "ATTRB" "2"
            "TEXT" "Ultra Blast Attack - Reduces opponents HP to zero."
        }

        "LEVEL" "10"
        "ATTCK" "100"
        "HP" "20"

        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "1"
            "TEXT" "Noob Attack - Do 10 damage."
        }
    }

    function onPlay(x)
        action(x)
    end

    function onDrawCard(x,y)
        action2(x,y)
    end

}
