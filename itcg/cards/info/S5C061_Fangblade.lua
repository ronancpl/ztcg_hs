ZTCG_CARD
{

    "NAME" "Fangblade"
    "IMAGE" "S5C061_Fangblade.png"
    "TYPE" "CHAR"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Dark Knight"
    "COST" "700"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card."
        }
        LVL_ACTION
        {
            "LEVEL" "30"
            "ATTRB" "1"
            "TEXT" "Crush -- Do 20 damage to a monster."
        }
        LVL_ACTION
        {
            "LEVEL" "40"
            "ATTRB" "2"
            "TEXT" "Spawn X -- Play a monster of your level or less."
        }
        "HP" "280"
    }

    function onActivateCharacterAction1(player)
        drawCard(player)
    end

    function onActivateCharacterAction2(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_DONT_HIT_CHAR", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onActivateCharacterAction3(player)
        local str = "Spawn X"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",level)
    end

}
