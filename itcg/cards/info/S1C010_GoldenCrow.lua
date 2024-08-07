ZTCG_CARD
{

    "NAME" "Golden Crow"
    "IMAGE" "S1C010_GoldenCrow.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Weapon"
    "COST" "780"

    TYPE_EQP
    {
        "LEVEL" "60"
        "TEXT" "Double the damage of one of your character actions each turn."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "No Mercy -- Do 10 damage to a character or monster. If that damage destroys a monster do this action again. "
    }

    function onEquipRefreshCharges(player)
        return 1                                                      -- number of charges available in one turn
    end

    function onEquipBuffWithCharge(player)      -- damage value doubled
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            return getGameValue(3)
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")

        local res = true
        while res do
            attack(player, chr, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")

            if not lastAttackKilled(player) then
                res = false
            end
        end
    end

}
