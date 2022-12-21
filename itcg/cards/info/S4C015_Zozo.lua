ZTCG_CARD
{

    "NAME" "Zozo"
    "IMAGE" "S4C015_Zozo.png"
    "TYPE" "CHAR"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Ranger"
    "COST" "900"

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
            "TEXT" "Weapon Expert -- Do 10 damage to a character or monster. If you have a Weapon, do 30 damage instead."
        }
        LVL_ACTION
        {
            "LEVEL" "40"
            "ATTRB" "2"
            "TEXT" "Spawn / Equip 40 -- Play a monster or item of level 40 or less."
        }
        "HP" "210"
    }

    function onActivateCharacterAction1(player)
        drawCard(player)
    end

    function onActivateCharacterAction2(player)
        local list, not_empty = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP","ELEM_ANY","Weapon")
        destroyList(list)

        local src = getSourceCARD()
        attack(player, src, not_empty and 30 or 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction3(player)
        local str = "Spawn / Equip 40"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 40)
    end

}
