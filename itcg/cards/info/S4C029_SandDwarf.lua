ZTCG_CARD
{

    "NAME" "Sand Dwarf"
    "IMAGE" "S4C029_SandDwarf.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Sand Dwarf"
    "COST" "710"

    TYPE_MOB
    {
        "LEVEL" "32"
        "ATTCK" "30"
        "HP" "40"
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Spawn / Think Fast 50 -- Play a monster or tactic of level 50 or less."
    }

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 50"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 50)
    end

}
