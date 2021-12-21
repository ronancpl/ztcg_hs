ZTCG_CARD
{

    "NAME" "Grizzly"
    "IMAGE" "S1C078_Grizzly.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Bear"
    "COST" "600"

    TYPE_MOB
    {
        "LEVEL" "56"
        "ATTCK" "50"
        "HP" "60"
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "3"
        "TEXT" "Spawn X -- Play a monster of your level or less. "
    }

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        local name = getNameFromCARD(chr)

        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",level)
    end

}
