ZTCG_CARD
{

    "NAME" "Croco"
    "IMAGE" "S1C055_Croco.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Reptile"
    "COST" "680"

    TYPE_MOB
    {
        "LEVEL" "52"
        "ATTCK" "70"
        "HP" "40"
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "3"
        "TEXT" "Equip X -- Play an item of your level or less. "
    }

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY",level)
    end

}
