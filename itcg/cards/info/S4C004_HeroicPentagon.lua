ZTCG_CARD
{

    "NAME" "Heroic Pentagon"
    "IMAGE" "S4C004_HeroicPentagon.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Jewelry"
    "COST" "680"

    TYPE_EQP
    {
        "LEVEL" "40"
        "TEXT" "When you play Heroic Pentagon, draw a card. Whenever you would take 50 or more damage all at once, you may destroy Heroic Pentagon and prevent that damage."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Tricky Shot -- Do 20 damage to a character or monster."
    }

    function onBlockResultDamage(player)
        if getGameValue(0) >= 50 then
            if(not makePrompt(player,"Use Heroic Pentagon?","Block damage of 50 or more.","ZTCG_NIL","ZTCG_NIL","OK","Cancel")) then return end

            updateGameValue(0, 0)

            local src = getSourceCARD()
            local slotid = getSlotIdFromCARD(player, src)
            destroySelf(player,"SLOT_PLAYEREQP" .. slotid)
        end
    end

    function onThinkEquipment(player)
        drawCard(player)
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
