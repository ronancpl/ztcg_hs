ZTCG_CARD
{

    "NAME" "Greater Spell Booster"
    "IMAGE" "S5C027_GreaterSpellBooster.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "710"

    TYPE_ACT
    {
        "LEVEL" "50"
        "TEXT" "Draw 3 cards. Then put a card from your hand face down on top of your deck."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Stir the Cauldron -- Look at the top card of your deck. You may put it on the bottom of your deck."
    }

    function onThinkAction(player)
        for i = 1, 3, 1 do
            drawCard(player)
        end

        local hand = getPlayerDeck(player, "DECK_HAND")
        local card_list = getListFromDeck(hand)

        local list = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY","ZTCG_NIL")
        if not isEmptyList(list) then
            while true do
                local card = menuCards(player,list,"Select a card to put on the top of the deck.","CARDLIST_PEEK")
                if card ~= 0 then
                    local deck = getPlayerDeck(player, "DECK_DECK")
                    moveCards(player,hand,deck,"TAKE_CARDID","PUT_TOP",card)

                    break
                end
            end
        end

        destroyList(list)
    end

    function onActivateCharacterAction(player)
        local card = peekNextCard(player)
        if card ~= 0 then
            local deck_list = getPlayerDeck(player, "DECK_DECK")
            local list_cards = takeCardsFromDeck(player,deck_list, 1)

            if(makePrompt(player,"Draw " .. getNameFromCARD(card) .. "?","Or insert it on the bottom of the deck?","ZTCG_NIL","ZTCG_NIL","Top","Bottom")) then
                list_cards = moveCardsFromListToDeck(player,list_cards,deck_list,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
            else
                list_cards = moveCardsFromListToDeck(player,list_cards,deck_list,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            end

            destroyList(list_cards)
        end
    end


}
