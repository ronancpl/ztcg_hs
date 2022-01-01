ZTCG_CARD
{

    "NAME" "Halfmoon Zamadar"
    "IMAGE" "S3C038_HalfmoonZamadar.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Weapon"
    "COST" "700"

    TYPE_EQP
    {
        "LEVEL" "32"
        "TEXT" "Get +20 on damage you do with one of your character actions each turn."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "2"
        "TEXT" "Stab -- Do 10 damage to a character or monster."
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

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
