ZTCG_CARD
{

    "NAME" "Diamond Arrows"
    "IMAGE" "S5C005_DiamondArrows.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Weapon"
    "COST" "680"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "When you finish doing your character actions each turn, do 10 damage to a character or monster. If you destroy one of your opponent's monsters this way, level up with Diamond Arrows."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Quick Shot -- Do 20 damage to a character or monster"
    }

    function afterCharacterActions(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_EQP", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")

        if lastAttackKilled(player) then
            local slotid = getSlotIdFromCARD(player, src)
            local list = takeCardFromTable(player, "SLOT_PLAYEREQP" .. tostring(slotid))

            local hand = getPlayerDeck(player, "DECK_HAND")
            list = takeTargetCardFromListToDeck(hand,list,list,"DECK_BOTTOM")
            levelUpScout(player)

            destroyList(list)
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, src, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
