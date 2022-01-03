ZTCG_CARD
{

    "NAME" "Wooden Mask"
    "IMAGE" "S4C060_WoodenMask.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Beast"
    "COST" "720"

    TYPE_MOB
    {
        "LEVEL" "23"
        "ATTCK" "20"
        "HP" "30"
        "TEXT" "Masked Power -- Whenever Wooden Mask attacks, you get +20 HP."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Scout -- Reveal the top card of your deck. If it's a monster card, put it into your hand. Otherwise, put it back."
    }

    function onExecuteNormalAttack(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,card,20)
    end

    function onLevelActionTrigger(player)
        scoutMob(player,"SCOUT_NORMAL","ELEM_ANY")
    end

}
