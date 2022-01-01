ZTCG_CARD
{

    "NAME" "Kiri Viva"
    "IMAGE" "S3C053_KiriViva.png"
    "TYPE" "CHAR"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Character - Knight"
    "COST" "850"

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
            "ATTRB" "2"
            "TEXT" "Gear Up -- Play an Armor, Shield, or Weapon of your level or less. "
        }
        LVL_ACTION
        {
            "LEVEL" "40"
            "ATTRB" "1"
            "TEXT" "Spawn 50 -- Play a monster of level 50 or less."
        }
        "HP" "240"
    }

    function onActivateCharacterAction1(player)
        drawCard(player)
    end

    function onActivateCharacterAction2(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        equip(player, "PLAY_GEARUPEQUIP","ELEM_ANY",level)
    end

    function onActivateCharacterAction3(player)
        local str = "Spawn 50"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",50)
    end


}
