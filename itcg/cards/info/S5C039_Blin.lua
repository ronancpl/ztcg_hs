ZTCG_CARD
{

    "NAME" "Blin"
    "IMAGE" "S5C039_Blin.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Fire Spook"
    "COST" "680"

    TYPE_MOB
    {
        "LEVEL" "60"
        "ATTCK" "50"
        "HP" "40"
        "TEXT" "Transmorph 60 -- When Blin is destroyed, you may play a monster of level 60 or less from your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "1"
        "TEXT" "Spawn 60 -- Play a monster of level 60 or less."
    }

    function onMobSentToDiscardPile(player)
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",60)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 60"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",60)
    end

}
