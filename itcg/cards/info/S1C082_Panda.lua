ZTCG_CARD
{

    "NAME" "Panda"
    "IMAGE" "S1C082_Panda.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Bear"
    "COST" "550"

    TYPE_MOB
    {
        "LEVEL" "60"
        "ATTCK" "40"
        "HP" "60"
        "TEXT" "Mystic Power -- Whenever Panda attacks, you get +40 HP."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Revive -- Return a monster card of level 50 or more from your discard pile to your hand. "
    }

    function onExecuteNormalAttack(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,card,40)
    end

    function onLevelActionTrigger(player)
        recoverCard(player, "DECK_HAND", "RECOVER_MOB", "GREATER", 50)
    end

}
