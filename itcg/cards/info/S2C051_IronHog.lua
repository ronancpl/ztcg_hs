ZTCG_CARD
{

    "NAME" "Iron Hog"
    "IMAGE" "S2C051_IronHog.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Boar"
    "COST" "600"

    TYPE_MOB
    {
        "LEVEL" "42"
        "ATTCK" "20"
        "HP" "60"
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Warrior Prowess -- Play a Warrior card of your level or less. "
    }

    function onLevelActionTrigger(player)
        local str = "Warrior Prowess"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_WARRIOR", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", level)
    end

}
