ZTCG_CARD
{

    "NAME" "Red Apprentice Hat"
    "IMAGE" "S1C042_RedApprenticeHat.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Armor"
    "COST" "530"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "When you play Red Apprentice Hat, draw a card. Whenever you level up, get +10 HP."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Equip 40 -- Play an item of level 40 or less. "
    }

    function onThinkEquipment(player)
        drawCard(player)
    end

    function onLevelUp(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,card,10)
    end

    function onActivateCharacterAction(player)
        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY",40)
    end

}
