ZTCG_CARD
{

    "NAME" "Ivan19712"
    "IMAGE" "S5C045_Ivan19712.png"
    "TYPE" "CHAR"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Hermit"
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
            "LEVEL" "30"
            "ATTRB" "1"
            "TEXT" "Equip X -- Play an item of your level or less."
        }
        LVL_ACTION
        {
            "LEVEL" "50"
            "ATTRB" "2"
            "TEXT" "Back Stab -- Do 10 damage to a character +20 for each Weapon you have."
        }
        "HP" "200"
    }

    function onActivateCharacterAction1(player)
        drawCard(player)
    end

    function onActivateCharacterAction2(player)
        local str = "Equip X"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY",level)
    end

    function onActivateCharacterAction3(player)
        local src = getSourceCARD()

        local weapons = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP", "ELEM_ANY", "Weapon")
        local n = getListLength(weapons)
        attack(player, src, 10 + 20 * (n), "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        destroyList(weapons)
    end

}
