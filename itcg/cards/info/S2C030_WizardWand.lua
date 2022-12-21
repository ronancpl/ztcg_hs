ZTCG_CARD
{

    "NAME" "Wizard Wand"
    "IMAGE" "S2C030_WizardWand.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Wand"
    "COST" "600"

    TYPE_EQP
    {
        "LEVEL" "40"
        "TEXT" "When your turn ends, you may flip a coin. If you win, draw a card, and you may flip the coin again. If you lose, discard all the cards from your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "2"
        "TEXT" "Think Fast 40 -- Play a tactic of level 40 or less. "
    }

    function onEndTurn(player)
        local deck_hand = getPlayerDeck(player, "DECK_HAND")
        local deck_grav = getPlayerDeck(player, "DECK_GRAV")
        local deck_deck = getPlayerDeck(player, "DECK_DECK")

        while true do
            local card_list, qty = getListFromDeck(deck_deck)
            if qty <= 0 then
                break
            end

            if not makePrompt(player,true,"Use Wizard Wand to draw a card?","You will have to throw a coin. If you lose, discard all cards from hand.","ZTCG_NIL","ZTCG_NIL","OK","Cancel") then
                break
            end

            if not throwCoin(player) then
                moveCards(player,deck_hand,deck_grav,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
                break
            end

            drawCard(player)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast 40"
        action(player,"ZTCG_NIL","ELEM_ANY",40)
    end

}
