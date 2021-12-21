ZTCG_CARD
{

    "NAME" "Jr. Necki"
    "IMAGE" "S1C031_JrNecki.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Worm"
    "COST" "540"

    TYPE_MOB
    {
        "LEVEL" "21"
        "ATTCK" "30"
        "HP" "30"
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Spawn 30 -- Play a monster of level 30 or less. "
    }

    function onActivateCharacterAction(player)
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",30)
    end

}
