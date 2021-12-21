ZTCG_CARD
{

    "NAME" "Krappy"
    "IMAGE" "S1C060_Krappy.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Water Fish"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "24"
        "ATTCK" "60"
        "HP" "30"
        "TEXT" "Confused -- Krappy can't attack on the turn you play it."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Stab -- Do 10 damage to a character or monster. "
    }

    function onThinkMob(player)
        local src = getSourceCARD()
        applyStun(player,src,1)
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end


}
