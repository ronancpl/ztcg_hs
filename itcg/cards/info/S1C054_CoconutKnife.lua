ZTCG_CARD
{

    "NAME" "Coconut Knife"
    "IMAGE" "S1C054_CoconutKnife.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Weapon"
    "COST" "530"

    TYPE_EQP
    {
        "LEVEL" "20"
        "TEXT" "Get +10 on damage you do with one of your character actions each turn."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Spy -- Draw a card. Then discard a card from your hand. "
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

    function onLevelActionTrigger(player)
        drawCard(player)
        discardCard(player)
    end

}
