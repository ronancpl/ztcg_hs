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
        local atksrcStr
        if getSlotIdFromCARD(player,src) > 0 then
            atksrcStr = "ATKSRC_EQP"
        else
            src = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            atksrcStr = "ATKSRC_CHA"
        end

        attack(player, src, dmg, "ATKRES_DONT_HIT_MOBS", atksrcStr, "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onLevelActionTrigger(player)
        insertCardTurnAction(player)
    end

}
