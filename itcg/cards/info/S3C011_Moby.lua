ZTCG_CARD
{

    "NAME" "Moby"
    "IMAGE" "S3C011_Moby.png"
    "TYPE" "CHAR"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Crossbowman"
    "COST" "800"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "1"
            "TEXT" "Easy Shot -- Do 10 damage to a character or monster."
        }
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card."
        }
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "2"
            "TEXT" "Spawn 30 -- Play a monster of level 30 or less."
        }
        "HP" "190"
    }

    function onActivateCharacterAction1(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction2(player)
        drawCard(player)
    end

    function onActivateCharacterAction3(player)
        local str = "Spawn 30"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",30)
    end


}
