ZTCG_CARD
{

    "NAME" "Nependeath"
    "IMAGE" "S3C013_Nependeath.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Flora"
    "COST" "720"

    TYPE_MOB
    {
        "LEVEL" "42"
        "ATTCK" "20"
        "HP" "80"
        "TEXT" "Rooted -- Nependeath can't attack characters."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Spawn 90 -- Play a monster of level 90 or less."
    }

    function preventSelfTargetCharacter(player)
        return 1
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 90"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",90)
    end

}
