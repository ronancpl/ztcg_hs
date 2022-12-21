ZTCG_CARD
{

    "NAME" "Mistmoon"
    "IMAGE" "S1C064_Mistmoon.png"
    "TYPE" "CHAR"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Assassin"
    "COST" "850"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "1"
            "TEXT" "Stab -- Do 10 damage to a character or monster."
        }
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card. "
        }
        LVL_ACTION
        {
            "LEVEL" "40"
            "ATTRB" "2"
            "TEXT" "Sneak 40 -- Play a card of level 40 or less. "
        }
        "HP" "200"
    }

    function onActivateCharacterAction1(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction2(player)
        drawCard(player)
    end

    function onActivateCharacterAction3(player)
        local str = "Sneak 40"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", 40)
    end

}
