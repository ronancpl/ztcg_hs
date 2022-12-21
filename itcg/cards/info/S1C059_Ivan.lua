ZTCG_CARD
{

    "NAME" "Ivan"
    "IMAGE" "S1C059_Ivan.png"
    "TYPE" "CHAR"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Character - Rogue"
    "COST" "700"

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
            "LEVEL" "10"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card. "
        }
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "1"
            "TEXT" "Equip X -- Play an item of your level or less. "
        }
        "HP" "220"
    }

    function onActivateCharacterAction1(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction2(player)
        drawCard(player)
    end

    function onActivateCharacterAction3(player)
        local str = "Equip X"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY",level)
    end

}
