ZTCG_CARD
{

    "NAME" "Brown Teddy"
    "IMAGE" "S3C017_BrownTeddy.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Toy Bear"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "30"
        "ATTCK" "20"
        "HP" "30"
        "TEXT" "Wind the Key -- Whenever you play a tactic, Brown Teddy gets +20 attack until end of turn."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "2"
        "TEXT" "Spawn 120 -- Play a monster of level 120 or less."
    }

    function onPlayAction(player)
        local src = getSourceCARD()
        newBuff(src,src,20,0,0,1)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 120"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",120)
    end


}
