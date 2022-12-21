ZTCG_CARD
{

    "NAME" "Trapped Chest"
    "IMAGE" "S5C054_TrappedChest.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Chest"
    "COST" "530"

    TYPE_EQP
    {
        "LEVEL" "20"
        "TEXT" "When you play Trapped Chest, name a card. Your opponent can't play cards with that name."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Thief Prowess -- Play a Thief card of your level or less."
    }

    function afterCharacterActions(player)
        local card = getSourceCARD()
        if(makePrompt(player,true,"Use " .. getNameFromCARD(card) .. "?","Draw a card. Choose one to discard.","ZTCG_NIL","ZTCG_NIL","OK","Cancel")) then
            drawCard(player)
            discardCard(player)

            local slotid = getSlotIdFromCARD(player,card) - 7
            destroySelf(player,"SLOT_PLAYEREQP" .. slotid)
        end
    end

    function onLevelActionTrigger(player)
        local str = "Thief Prowess"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_THIEF", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", level)
    end

}
