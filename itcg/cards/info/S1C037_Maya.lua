ZTCG_CARD
{

    "NAME" "Maya"
    "IMAGE" "S1C037_Maya.png"
    "TYPE" "CHAR"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Character - Magician"
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
            "TEXT" "Fire Arrow -- Do 10 damage to a character or monster. "
        }
        LVL_ACTION
        {
            "LEVEL" "30"
            "ATTRB" "2"
            "TEXT" "Think Fast X -- Play a tactic of your level or less. "
        }
        "HP" "190"
    }

    function onActivateCharacterAction1(player)
        drawCard(player)
    end

    function onActivateCharacterAction2(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction3(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        action(player,"ZTCG_NIL","ELEM_ANY",level)
    end

}
