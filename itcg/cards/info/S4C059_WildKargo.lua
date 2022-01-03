ZTCG_CARD
{

    "NAME" "Wild Kargo"
    "IMAGE" "S4C059_WildKargo.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Beast"
    "COST" "820"

    TYPE_MOB
    {
        "LEVEL" "62"
        "ATTCK" "60"
        "HP" "70"
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 30 -- Play a monster or item of level 30 or less."
    }

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 30"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 30)
    end

}
