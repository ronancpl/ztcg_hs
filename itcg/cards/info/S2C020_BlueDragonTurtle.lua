ZTCG_CARD
{

    "NAME" "Blue Dragon Turtle"
    "IMAGE" "S2C020_BlueDragonTurtle.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Ice Dragon Turtle"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "90"
        "ATTCK" "80"
        "HP" "100"
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "1"
        "TEXT" "Spawn 90 -- Play a monster of level 90 or less. "
    }

    function onActivateCharacterAction(player)
        local str = "Spawn 90"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",90)
    end

}
