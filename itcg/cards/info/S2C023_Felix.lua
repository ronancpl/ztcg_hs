ZTCG_CARD
{

    "NAME" "Felix"
    "IMAGE" "S2C023_Felix.png"
    "TYPE" "CHAR"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Fire/Poison Mage"
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
            "ATTRB" "2"
            "TEXT" "Poison Mist -- Do 20 damage to a character. "
        }
        LVL_ACTION
        {
            "LEVEL" "40"
            "ATTRB" "3"
            "TEXT" "Spellshape -- Play a tactic of your level or less. If you do, draw a card. Then discard a card from your hand. "
        }
        "HP" "170"

    }

    function onActivateCharacterAction1(player)
        drawCard(player)
    end

    function onActivateCharacterAction2(player)
        local src = getSourceCARD()
        attack(player, src, 20, "ATKRES_DONT_HIT_MOBS", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction3(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        local ret = action(player,"ZTCG_NIL","ELEM_ANY",level)
        if ret then
            drawCard(player)
            discardCard(player)
        end
    end

}
