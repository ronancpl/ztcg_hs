ZTCG_CARD
{

    "NAME" "Stormwind"
    "IMAGE" "S1C044_Stormwind.png"
    "TYPE" "CHAR"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Ice / Lightning Mage"
    "COST" "850"

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
            "ATTRB" "2"
            "TEXT" "Think Fast X -- Play a tactic of your level or less. "
        }
        LVL_ACTION
        {
            "LEVEL" "70"
            "ATTRB" "3"
            "TEXT" "Thunder Spear -- Do 40 damage to a character. "
        }
        "HP" "180"
    }

    function onActivateCharacterAction1(player)
        drawCard(player);
    end

    function onActivateCharacterAction2(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        action(player,"ZTCG_NIL","ELEM_ANY",level)
    end

    function onActivateCharacterAction3(player)
        local src = getSourceCARD()
        attack(player, src, 40, "ATKRES_DONT_HIT_MOBS", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
