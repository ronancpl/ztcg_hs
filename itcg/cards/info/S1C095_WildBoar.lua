ZTCG_CARD
{

    "NAME" "Wild Boar"
    "IMAGE" "S1C095_WildBoar.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Boar"
    "COST" "540"

    TYPE_MOB
    {
        "LEVEL" "25"
        "ATTCK" "30"
        "HP" "30"
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Think Fast / Equip 30 -- Play a tactic or item of level 30 or less. "
    }

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 30"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 30)
    end

}
