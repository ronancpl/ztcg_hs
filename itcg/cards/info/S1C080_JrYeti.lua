ZTCG_CARD
{

    "NAME" "Jr. Yeti"
    "IMAGE" "S1C080_JrYeti.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Ice Beast"
    "COST" "480"

    TYPE_MOB
    {
        "LEVEL" "50"
        "ATTCK" "20"
        "HP" "50"
        "TEXT" "Fierce -- Jr. Yeti attacks twice each turn."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Crush -- Do 20 damage to a monster. "
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

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_DONT_HIT_CHAR", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
