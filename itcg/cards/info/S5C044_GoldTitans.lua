ZTCG_CARD
{

    "NAME" "Gold Titans"
    "IMAGE" "S5C044_GoldTitans.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Weapon"
    "COST" "730"

    TYPE_EQP
    {
        "LEVEL" "15"
        "TEXT" "Whenever your opponent draws a card, do 20 damage to his or her character."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Free-For-All -- Each player draws a card."
    }

    function onOpponentDrawCard(player)
        local src = getSourceCARD()
        attack(player, src, 20, "ATKRES_DONT_HIT_MOBS", "ATKSRC_EQP", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onLevelActionTrigger(player)
        drawCard(player)
        drawCard(not player)
    end

}
