ZTCG_CARD
{

    "NAME" "Buy and Sell"
    "IMAGE" "S4C017_BuyandSell.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Strategy"
    "COST" "730"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "Choose a player. That player shuffles his or her hand into his or her deck, then draws the same number of cards plus one."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 70 -- Play a monster or item of level '70 or less."
    }

    function onThinkAction(player)
        local p
        if makePrompt(player,"Do Buy and Sell on which player?","ZTCG_NIL","ZTCG_NIL","ZTCG_NIL","Me","Opponent") then
            p = player
        else
            p = not player
        end

        local deckHand = getPlayerDeck(p, "DECK_HAND")
        local deckDeck = getPlayerDeck(p, "DECK_DECK")

        local card_list, qty = getListFromDeck(deckHand)
        local n = qty

        moveCards(deckHand,deckDeck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
        shuffleDeck(deckDeck)

        for i = 1, n + 1, 1 do
            drawCard(p)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 70"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 70)
    end

}
