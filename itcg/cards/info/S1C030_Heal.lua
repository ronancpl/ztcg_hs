ZTCG_CARD
{

    "NAME" "Heal"
    "IMAGE" "S1C030_Heal.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "510"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "You get +80 HP. You can't go over your starting HP with Heal."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Equip 30 -- Play an item of level 30 or less. "
    }

    function onThinkAction(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,card,80)
    end

    function onActivateCharacterAction(player)
        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY",30)
    end

}
