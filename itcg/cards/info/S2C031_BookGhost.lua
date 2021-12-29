ZTCG_CARD
{

    "NAME" "Book Ghost"
    "IMAGE" "S2C031_BookGhost.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Undead Spook"
    "COST" "620"

    TYPE_MOB
    {
        "LEVEL" "55"
        "ATTCK" "60"
        "HP" "40"
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Spawn / Think Fast 50 -- Play a monster or tactic of level 50 or less. "
    }

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 50"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 50)
    end


}
