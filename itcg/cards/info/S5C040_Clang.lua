ZTCG_CARD
{

    "NAME" "Clang"
    "IMAGE" "S5C040_Clang.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Water Crab"
    "COST" "680"

    TYPE_MOB
    {
        "LEVEL" "48"
        "ATTCK" "50"
        "HP" "30"
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "3"
        "TEXT" "Equip X -- Play an item of your level or less."
    }

    function onActivateCharacterAction(player)
        local str = "Equip X"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY",level)
    end

}
