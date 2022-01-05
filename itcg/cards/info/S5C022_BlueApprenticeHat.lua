ZTCG_CARD
{

    "NAME" "Blue Apprentice Hat"
    "IMAGE" "S5C022_BlueApprenticeHat.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Armor"
    "COST" "530"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "When you play Blue Apprentice Hat, draw a card. Whenever you level up, do 10 damage to a character."
    }

    LVL_ACTION
    {
        "LEVEL" "10"
        "ATTRB" "1"
        "TEXT" "Zap -- Do 10 damage to a character."
    }

    function onThinkEquipment(player)
        drawCard(player)
    end

    function onLevelUp(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_DONT_HIT_MOBS", "ATKSRC_EQP", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_DONT_HIT_MOBS", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end


}
