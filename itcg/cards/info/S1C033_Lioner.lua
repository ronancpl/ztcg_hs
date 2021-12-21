ZTCG_CARD
{

    "NAME" "Lioner"
    "IMAGE" "S1C033_Lioner.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Kitty"
    "COST" "710"

    TYPE_MOB
    {
        "LEVEL" "53"
        "ATTCK" "50"
        "HP" "50"
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Spawn / Think Fast 90 -- Play a monster or tactic of level 90 or less. "
    }

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 90"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 90)
    end

}
