ZTCG_CARD
{

    "NAME" "Bone Fish"
    "IMAGE" "S4C031_BoneFish.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Undead Fish"
    "COST" "720"

    TYPE_MOB
    {
        "LEVEL" "92"
        "ATTCK" "120"
        "HP" "120"
        "TEXT" "Confused -- Bone Fish can't attack on the turn you play it."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Dazed -- On your opponent's next turn, all of his or her monsters are Confused."
    }

    function onThinkMob(player)
        local src = getSourceCARD()
        applyStun(player,src,1)
    end

    function onLevelActionTrigger(player)
        applyGlobalStun(player)
    end

}
