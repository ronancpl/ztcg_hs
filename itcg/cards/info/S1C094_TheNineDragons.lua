ZTCG_CARD
{

    "NAME" "The Nine Dragons"
    "IMAGE" "S1C094_TheNineDragons.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Weapon"
    "COST" "790"

    TYPE_EQP
    {
        "LEVEL" "50"
        "TEXT" "Each of your monsters gets +20 attack."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Equip 30 -- Play an item of level 30 or less. "
    }

    function onEquipBuff(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            return 20   -- any move from mobs apply equip bonus
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY",30)
    end

}
