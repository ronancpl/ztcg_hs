ZTCG_CARD
{

    "NAME" "Mithril Wristband"
    "IMAGE" "S4C041_MithrilWristband.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Jewelry"
    "COST" "730"

    TYPE_EQP
    {
        "LEVEL" "20"
        "TEXT" "Whenever your opponent plays a tactic, get +30 HP."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Stab -- Do 10 damage to a character or monster."
    }

    function onOpponentPlayAction(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,card,30)
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
