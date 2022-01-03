ZTCG_CARD
{

    "NAME" "Diamond Dagger"
    "IMAGE" "S4C038_DiamondDagger.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Weapon"
    "COST" "780"

    TYPE_EQP
    {
        "LEVEL" "50"
        "TEXT" "For each item you have, get +10 damage you do with one of your character actions each turn."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "1"
        "TEXT" "Equip 100 -- Play an item of level 100 or less."
    }

    function onEquipRefreshCharges(player)
        return getEquipsOnTable(player,"ONLY_PLAYER")
    end

    function onEquipBuffWithCharge(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            return 20
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY",100)
    end

}
