ZTCG_CARD
{

    "NAME" "Sr. Bellflower Root"
    "IMAGE" "S3C029_SrBellflowerRoot.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Flora"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "54"
        "ATTCK" "50"
        "HP" "50"
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "1"
        "TEXT" "Spawn 60 -- Play a monster of level 60 or less."
    }

    function onActivateCharacterAction(player)
        local str = "Spawn 60"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",60)
    end

}
