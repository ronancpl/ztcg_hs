ZTCG_CARD
{

    "NAME" "Sentinel"
    "IMAGE" "S1C087_Sentinel.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Mechanical Guardian"
    "COST" "470"

    TYPE_MOB
    {
        "LEVEL" "30"
        "ATTCK" "20"
        "HP" "30"
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
