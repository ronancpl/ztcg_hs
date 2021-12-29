ZTCG_CARD
{

    "NAME" "Luster Pixie"
    "IMAGE" "S2C010_LusterPixie.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Flying Spook"
    "COST" "650"

    TYPE_MOB
    {
        "LEVEL" "52"
        "ATTCK" "50"
        "HP" "50"
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Revive -- Return a monster of level 30 or less from your discard pile to your hand. "
    }

    function onLevelActionTrigger(player)
        recoverCard(player, "DECK_HAND", "RECOVER_MOB", "LESSER", 30)
    end

}
