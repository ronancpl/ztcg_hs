ZTCG_CARD
{

    "NAME" "Mahibang"
    "IMAGE" "S5C030_Mahibang.png"
    "TYPE" "CHAR"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Priest"
    "COST" "700"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card."
        }
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "1"
            "TEXT" "Wand Thwack -- Do 10 damage to a character or monster."
        }
        LVL_ACTION
        {
            "LEVEL" "80"
            "ATTRB" "3"
            "TEXT" "Think Fast Unlimited -- Play a tactic."
        }
        "HP" "190"
    }

    function onActivateCharacterAction1(player)
        drawCard(player)
    end

    function onActivateCharacterAction2(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onActivateCharacterAction3(player)
        local str = "Think Fast Unlimited"
        action(player,"ZTCG_NIL","ELEM_ANY","ZTCG_MAXVALUE")
    end

}
