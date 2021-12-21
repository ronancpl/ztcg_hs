ZTCG_CARD
{

    "NAME" "Sherman"
    "IMAGE" "S1C089_Sherman.png"
    "TYPE" "CHAR"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Character - Swordsman"
    "COST" "700"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "1"
            "TEXT" "Bash -- Do 10 damage to a character or monster."
        }
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card. "
        }
        LVL_ACTION
        {
            "LEVEL" "30"
            "ATTRB" "2"
            "TEXT" "Spawn X -- Spawn a monster of your level or less. "
        }
        "HP" "240"
    }

    function onActivateCharacterAction1(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onActivateCharacterAction2(player)
        drawCard(player)
    end

    function onActivateCharacterAction3(player)
        local str = "Spawn X"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",level)
    end

}
