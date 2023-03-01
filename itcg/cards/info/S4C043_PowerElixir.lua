ZTCG_CARD
{

    "NAME" "Power Elixir"
    "IMAGE" "S4C043_PowerElixir.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Potion"
    "COST" "870"

    TYPE_EQP
    {
        "LEVEL" "90"
        "TEXT" "When your turn ends, you may destroy Power Elixir. If you do, get +HP equal to your level and draw cards until you have 5 cards in hand."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Drink Potion -- You get +HP equal to your level."
    }

    function destroyCard(player, card, tableStr, isEqp)
        if isBossCARD(card) then return end

        local ret = false
        local slotid = getSlotIdFromCARD(player, card)
        if slotid > 0 then
            destroySelf(player,tableStr .. (isEqp and (slotid - 7) or slotid))
            ret = true
        end

        return ret
    end

    function onEndTurn(player)
        local hand = getPlayerDeck(player, "DECK_HAND")
        local card_list, qty = getListFromDeck(hand)
        local c = 5 - qty
        if c < 0 then c = 0 end

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        local src = getSourceCARD()
        local hp_val = level
        local draw_val = c

        if(not makePrompt(player,true,"Use " .. getNameFromCARD(src) .. "?","%d HP restoration, draw %d cards.",hp_val,draw_val,"OK","Cancel")) then return end

        refreshHP(player,chr,level)

        for i = 1, c, 1 do
            drawCard(player)
        end

        destroyCard(player, src, "SLOT_PLAYEREQP", true)
    end

    function onLevelActionTrigger(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        refreshHP(player,chr,level)
    end

}
