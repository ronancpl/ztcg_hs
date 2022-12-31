ZTCG_CARD
{

    "NAME" "Crystal Boar"
    "IMAGE" "S4C047_CrystalBoar.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Ice Boar"
    "COST" "720"

    TYPE_MOB
    {
        "LEVEL" "40"
        "ATTCK" "30"
        "HP" "30"
        "TEXT" "Stupefy -- When you play Crystal Boar, your opponent can't play tactics next turn."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "2"
        "TEXT" "Spawn 40 -- Play a monster of level 40 or less."
    }

    function onThinkMob(player)
        turnAction(not player,false)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 40"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",40)
    end

}
