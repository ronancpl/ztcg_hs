ZTCG_CARD
{

    "NAME" "Block Golem"
    "IMAGE" "S1C074_BlockGolem.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Guardian"
    "COST" "490"

    TYPE_MOB
    {
        "LEVEL" "42"
        "ATTCK" "40"
        "HP" "40"
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Scout -- Reveal the top card of your deck. If it's a monster card, put it into your hand. Otherwise put it back. "
    }

    function onLevelActionTrigger(player)
        scoutMob(player,"SCOUT_NORMAL","ELEM_ANY")
    end

}
