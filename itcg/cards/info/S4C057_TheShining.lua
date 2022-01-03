ZTCG_CARD
{

    "NAME" "The Shining"
    "IMAGE" "S4C057_TheShining.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Weapon"
    "COST" "840"

    TYPE_EQP
    {
        "LEVEL" "60"
        "TEXT" "Whenever one of your monsters is destroyed, do damage equal to its attack to a character."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Shining Cleave -- Until your next turn starts, whenever one of your monsters is destroyed, do damage equal to its attack to a character."
    }

    function onAttackMobDestroyed(player)
        local card = getTargetCARD()
        local dmg = getBaseAttackFromCARD(card)

        local src = getSourceCARD()
        attack(player, src, dmg, "ATKRES_DONT_HIT_MOBS", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onLevelActionTrigger(player)
        insertCardTurnAction(player)
    end

}
