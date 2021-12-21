ZTCG_CARD
{

    "NAME" "Battle Bow"
    "IMAGE" "S1C002_BattleBow.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Weapon"
    "COST" "750"

    TYPE_EQP
    {
        "LEVEL" "25"
        "TEXT" "Get +20 on damage you do with one of your character actions each turn."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Critical Shot -- Flip a coin. If you win, do damage equal to your level to a character or monster. "
    }

    function onEquipRefreshCharges(player)
        return 1
    end

    function onEquipBuffWithCharge(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            return 20
        else
            return 0
        end
    end

    function onLevelActionTrigger(player)
        local res = throwCoin(player)
        if res then
            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            local level = getCurrentLevelFromCARD(player,chr)
            attack(player, chr, level, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

}
