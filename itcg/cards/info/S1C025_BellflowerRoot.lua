ZTCG_CARD
{

    "NAME" "Bellflower Root"
    "IMAGE" "S1C025_BellflowerRoot.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Flora"
    "COST" "580"

    TYPE_MOB
    {
        "LEVEL" "53"
        "ATTCK" "40"
        "HP" "60"
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Think Fast / Equip 50 -- Play a tactic or equip of level 50 or less. "
    }

    function onActivateCharacterAction(player)
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 50)
    end

}
