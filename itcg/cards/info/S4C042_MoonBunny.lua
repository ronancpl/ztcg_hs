ZTCG_CARD
{

    "NAME" "Moon Bunny"
    "IMAGE" "S4C042_MoonBunny.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Rabbit"
    "COST" "680"

    TYPE_MOB
    {
        "LEVEL" "45"
        "ATTCK" "50"
        "HP" "20"
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Sneak 50 -- Play a card of level 50 or less."
    }

    function onActivateCharacterAction(player)
        local str = "Sneak 50"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", 50)
    end

}
