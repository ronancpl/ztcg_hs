ZTCG_CARD
{

    "NAME" "Alishar"
    "IMAGE" "S2C016_Alishar.png"
    "TYPE" "BOSS"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Boss"
    "COST" "780"

    TYPE_BOS
    {
        "HP" "120"
        "ATTCK" "30"
        "LEVEL" "56"
        LVL_ACTION
        {
            "LEVEL" "70"
            "ATTRB" "1"
            "TEXT" "Time Tornado -- Each player shuffles his or her discard pile and hand into his or her deck. Then each player draws 5 cards."
        }
    }

    function resetDeck(player)
        local deckDeck = getPlayerDeck(player, "DECK_DECK")

        local deckGrav = getPlayerDeck(player, "DECK_GRAV")
        moveCards(player,deckGrav,deckDeck,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")

        local deckHand = getPlayerDeck(player, "DECK_HAND")
        moveCards(player,deckHand,deckDeck,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")

        shuffleDeck(deckDeck)
    end

    function drawFiveCards(player)
        for i = 1, 5, 1 do
            drawCard(player)
        end
    end

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(not matchRequirements(player, 70, 2, "ELEM_MAGE")) then return end
        if(not makePrompt(player,true,"Use Time Tornado?","Each player re-shuffles deck and draw 5 cards.","ZTCG_NIL","ZTCG_NIL","OK","Cancel")) then return end

        resetDeck(player)
        drawFiveCards(player)

        resetDeck(not player)
        drawFiveCards(not player)
    end

}
