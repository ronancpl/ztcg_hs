ZTCG_CARD
{

    "NAME" "Zavier"
    "IMAGE" "S5C090_Zavier.png"
    "TYPE" "CHAR"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Beginner"
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
            "ATTRB" "0"
            "TEXT" "Dabble 20 -- Play a card of level 20 or less. You don't need a card of that color under your character."
        }
        LVL_ACTION
        {
            "LEVEL" "30"
            "ATTRB" "0"
            "TEXT" "Fish Slap -- Do 10 damage to a character or monster."
        }
        "HP" "180"
    }

    function onActivateCharacterAction1(player)
        drawCard(player)
    end

    function onActivateCharacterAction2(player)
        local str = "Dabble 20"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", 20)
    end

    function onActivateCharacterAction3(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
