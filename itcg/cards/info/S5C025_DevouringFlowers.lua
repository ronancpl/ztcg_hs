ZTCG_CARD
{

    "NAME" "Devouring Flowers"
    "IMAGE" "S5C025_DevouringFlowers.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Flora Upgrade"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "22"
        "ATTCK" "30"
        "HP" "90"
        "TEXT" "Flora Upgrade -- Put on one of your Flora monsters. Plant Seeds -- Whenever Devouring Flowers attacks, you may return a Flora card from your discard pile to your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Floral Hunt 3 -- Reveal the top 3 cards of your deck. Put any Floras revealed this way into your hand and the others on the bottom of your deck in any order."
    }

    function onExecuteAttack(player)
        local grav = getPlayerDeck(player, "DECK_GRAV")
        local card_list = getListFromDeck(grav)

        local mob_list, qty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","Flora")
        if qty > 0 then
            local card = menuCards(player,mob_list,"Select a monster to draw.","CARDLIST_PEEK")
            if card ~= 0 then
                local hand = getPlayerDeck(player, "DECK_HAND")
                moveCards(grav,hand,"TAKE_CARDID","PUT_BOTTOM",card)
            end
        end

        destroyList(mob_list)
    end

    function onLevelActionTrigger(player)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local cards_taken = takeCardsFromDeck(deck,3)

        local mob_list = makeFilteredList(player,cards_taken,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","Flora")
        while getListLength(mob_list) > 0 do
            local card = menuCards(player,mob_list,"Select a monster to draw.","CARDLIST_PEEK")
            if card ~= 0 then
                local hand = getPlayerDeck(player, "DECK_HAND")
                cards_taken = moveCardsFromListToDeck(cards_taken,hand,"TAKE_CARDID","PUT_BOTTOM",card)

                mob_list = takeTargetCardFromList(card,mob_list)
            else
                break
            end
        end

        pickCardOrder(player,cards_taken)
        cards_taken = moveCardsFromListToDeck(cards_taken,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

        destroyList(mob_list)
        destroyList(cards_taken)
    end

}
