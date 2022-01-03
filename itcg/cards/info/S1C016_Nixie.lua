ZTCG_CARD
{

    "NAME" "Nixie"
    "IMAGE" "S1C016_Nixie.png"
    "TYPE" "CHAR"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Character - Archer"
    "COST" "700"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "1"
            "TEXT" "Easy Shot -- Do 10 damage to a character or monster"
        }
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card "
        }
        LVL_ACTION
        {
            "LEVEL" "50"
            "ATTRB" "2"
            "TEXT" "Tricky Shot -- Do 20 damage to a character or monster. "
        }
        "HP" "200"
    }

    function onActivateCharacterAction1(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onActivateCharacterAction2(player)
        drawCard(player)
    end

    function onActivateCharacterAction3(player)
        local src = getSourceCARD()
        attack(player, src, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
