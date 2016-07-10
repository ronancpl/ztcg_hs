ZTCG_CARD
{
LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "1"
            "TEXT" "Slash - Do 10 damage."
        }

    "NAME" "SWORD"
    "IMAGE" "base_card.png"
    "TYPE" "EQUIP"
    "ELEMENT" "EARTH"
    "RARITY" "7"
    "INFO" "random things"
    "COST" "1"

    TYPE_EQP
    {
        "TEXT" "Gain +10 damage on next attack."
        "LEVEL" "10"


    }

    function onPlay(x)
        action(x)
    end

    function onDrawCard(x,y)
        action2(x,y)
    end

}
