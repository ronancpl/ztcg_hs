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

    function onEndTurn(player)
        if(not makePrompt(player,"Use Power Elixir?","Get +HP equal to your level and draw cards.","ZTCG_NIL","ZTCG_NIL","OK","Cancel")) then return end

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        refreshHP(player,chr,level)

        local hand = getPlayerDeck(player, "DECK_HAND")
        local card_list, qty = getListFromDeck(hand)

        local c = 5 - qty
        for i = 1, c, 1 do
            drawCard(player)
        end
    end

    function onLevelActionTrigger(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        refreshHP(player,chr,level)
    end

}
