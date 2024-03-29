ZTCG_CARD
{

    "NAME" "Ergoth"
    "IMAGE" "S3C020_Ergoth.png"
    "TYPE" "BOSS"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Boss"
    "COST" "900"

    TYPE_BOS
    {
        "HP" "190"
        "ATTCK" "50"
        "LEVEL" "115"
        LVL_ACTION
        {
            "LEVEL" "70"
            "ATTRB" "3"
            "TEXT" "Deadly Wisdom -- Reveal the top 3 cards of your deck. If any of them are tactics, you may play them. Otherwise, put them on the bottom of your deck in any order."
        }
        LVL_ACTION
        {
            "LEVEL" "120"
            "ATTRB" "3"
            "TEXT" "Reaper's Knock -- Reduce your opponent's HP to 10. Your turn ends."
        }
    }

    function effect_dw(player)
        if(not matchRequirements(player, 70, 3, "ELEM_MAGE")) then return end

        local hand = getPlayerDeck(player, "DECK_HAND")
        local deck = getPlayerDeck(player, "DECK_DECK")
        local cards = takeCardsFromDeck(player,deck, 3)

        local actions = makeFilteredList(player,cards,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ACT","ELEM_ANY","ZTCG_NIL")
        while getListLength(actions) > 0 do
            local card = menuCards(player,actions,"Select a tactic to use.","CARDLIST_PEEK")
            if card ~= 0 then
                actions = takeTargetCardFromList(card,actions)
                cards = moveCardsFromListToDeck(player,cards,hand,"TAKE_CARDID","PUT_BOTTOM",card)
                action(player,getCARD(card),"ELEM_ANY","ZTCG_DONTCARE")
            else
                break
            end
        end

        pickCardOrder(player,cards)
        cards = moveCardsFromListToDeck(player,cards,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

        destroyList(actions)
        destroyList(cards)
    end

    function effect_rk(player)
        if(not matchRequirements(player, 120, 3, "ELEM_MAGE")) then return end

        if(not makePrompt(player,true,"Use Reaper's Knock?","Opponent's HP goes to 10. Your turn ends.","ZTCG_NIL","ZTCG_NIL","OK","Cancel")) then
            return
        end

        local card = getOnBoardCARD(player, "SLOT_ADVSRYCHAR")
        editCardHP(card,10)

        finishTurn(player)
    end

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end

        effect_dw(player)
        effect_rk(player)
    end

}
