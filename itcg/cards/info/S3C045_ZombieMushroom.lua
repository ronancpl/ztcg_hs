ZTCG_CARD
{

    "NAME" "Zombie Mushroom"
    "IMAGE" "S3C045_ZombieMushroom.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Undead Mushroom"
    "COST" "650"

    TYPE_MOB
    {
        "LEVEL" "24"
        "ATTCK" "40"
        "HP" "10"
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Spawn / Think Fast 40 -- Play a monster or tactic of level 40 or less."
    }

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 40"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 40)
    end

}
