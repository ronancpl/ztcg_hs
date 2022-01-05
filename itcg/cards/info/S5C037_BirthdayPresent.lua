ZTCG_CARD
{

    "NAME" "Birthday Present"
    "IMAGE" "S5C037_BirthdayPresent.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Strategy"
    "COST" "650"

    TYPE_ACT
    {
        "LEVEL" "40"
        "TEXT" "Search your deck for a card. Then shuffle your deck and put that card on top."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Loot -- If your opponent has 3 or more cards in hand, he or she chooses one and discards it."
    }

    function onThinkAction(player)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local card_list, qty = getListFromDeck(deck)
        local new_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY", "ELEM_ANY", "ZTCG_NIL")
        if not_empty then
            local card = menuCards(player,new_list,"Select a card to put on top of the deck.","CARDLIST_PEEK")
            if card ~= 0 then
                revealCard(not player,"Opponent has placed card...",getCARD(card))

                local list_card = takeTargetCardFromDeck(card,deck)
                shuffleDeck(deck)

                list_card = moveCardsFromListToDeck(list_card,deck,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
                destroyList(list_card)
            end
        end

        destroyList(new_list)
    end

    function onLevelActionTrigger(player)
        local hand = getPlayerDeck(not player, "DECK_HAND")
        local cards, qty = getListFromDeck(hand)

        if qty >= 3 then
            discardCard(not player)
        end
    end

}
