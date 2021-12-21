ZTCG_CARD
{

    "NAME" "Peach Monkey"
    "IMAGE" "S1C041_PeachMonkey.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Monkey"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "62"
        "ATTCK" "60"
        "HP" "60"
        "TEXT" "Greedy -- When you play Peach Monkey, you may destroy an item."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "2"
        "TEXT" "Spawn 120 -- Play a monster of level 120 or less. "
    }

    function onThinkMob(player)
        destroyEquipment(player)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 120"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",120)
    end

}
