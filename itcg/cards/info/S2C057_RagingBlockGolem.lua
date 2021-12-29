ZTCG_CARD
{

    "NAME" "Raging Block Golem"
    "IMAGE" "S2C057_RagingBlockGolem.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Guardian"
    "COST" "580"

    TYPE_MOB
    {
        "LEVEL" "42"
        "ATTCK" "20"
        "HP" "40"
        "TEXT" "Fierce -- Raging Block Golem attacks twice each turn."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Scout -- Reveal the top card of your deck. If it's a monster card, put it into your hand. Otherwise put it back. "
    }

    function onThinkMob(player)
        local src = getSourceCARD()
        addExtraMobAttack(src,src,2)
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        addExtraMobAttack(src, src, 2)
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        removeExtraMobAttack(src, src)
    end

    function onLevelActionTrigger(player)
        scoutMob(player,"SCOUT_NORMAL","ELEM_ANY")
    end

}
