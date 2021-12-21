ZTCG_CARD
{

    "NAME" "Item Trade"
    "IMAGE" "S1C079_ItemTrade.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "770"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "Destroy an Item"
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Drink Potion -- You get +HP equal to your level. "
    }

    function onThinkAction(player)
        destroyEquipment(player)
    end

    function onLevelActionTrigger(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        refreshHP(player,chr,level)
    end

}
