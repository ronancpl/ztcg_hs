ZTCG_CARD
{

    "NAME" "Slime"
    "IMAGE" "S1C090_Slime.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Goo"
    "COST" "530"

    TYPE_MOB
    {
        "LEVEL" "6"
        "ATTCK" "10"
        "HP" "10"
        "TEXT" "Squish -- When you play Slime, you may destroy an item."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Refresh -- You get +10 HP. "
    }

    function onThinkMob(player)
        destroyEquipment(player)
    end

    function onActivateCharacterAction(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,card,10)
    end

}
