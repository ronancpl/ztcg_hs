ZTCG_CARD
{

    "NAME" "War Bow"
    "IMAGE" "S4C012_WarBow.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Weapon"
    "COST" "630"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "Get +10 on damage you do with one of your character actions each turn."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "1"
        "TEXT" "Easy Shot -- Do 10 damage to a character or monster."
    }

    function onEquipRefreshCharges(player)
        return 1
    end

    function onEquipBuffWithCharge(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            return 10
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
