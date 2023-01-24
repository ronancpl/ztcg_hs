ZTCG_CARD
{

    "NAME" "Pull"
    "IMAGE" "S1C084_Pull.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Strategy"
    "COST" "570"

    TYPE_ACT
    {
        "LEVEL" "40"
        "TEXT" "Search your deck for a monster card, reveal it, and put it into your hand. Then shuffle your deck."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Scout -- Reveal the top card of your deck. If it's a monster card, put it into your hand. Otherwise put it back. "
    }

    function onThinkAction(player)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local hand = getPlayerDeck(player, "DECK_HAND")

        local card_list, qty = getListFromDeck(deck)
        local new_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
        if not_empty then
            local card = menuCards(player,new_list,"Select a card to bring along to hand.","CARDLIST_PEEK")
            if card ~= 0 then
                revealCard(not player,"Opponent has drawn card...",getCARD(card))

                local list_card = takeTargetCardFromDeck(player,card,deck)
                list_card = moveCardsFromListToDeck(player,list_card,hand,"TAKE_NEXT","PUT_BOTTOM",1)
                destroyList(list_card)

                shuffleDeck(player,"DECK_DECK")
            end
        end

        destroyList(new_list)
    end

    function onLevelActionTrigger(player)
        scoutMob(player,"SCOUT_NORMAL","ELEM_ANY")
    end

}
