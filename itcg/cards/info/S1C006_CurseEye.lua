ZTCG_CARD
{

    "NAME" "Curse Eye"
    "IMAGE" "S1C006_CurseEye.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Worm"
    "COST" "540"

    TYPE_MOB
    {
        "LEVEL" "35"
        "ATTCK" "30"
        "HP" "40"
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Spawn / Think Fast 40 -- Play a monster or tactic of level 40 or less. "
    }

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 40"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 40)
    end

}
