ZTCG_CARD
{

    "NAME" "Lazy Buffy"
    "IMAGE" "S2C033_LazyBuffy.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Undead Clown"
    "COST" "740"

    TYPE_MOB
    {
        "LEVEL" "66"
        "ATTCK" "50"
        "HP" "40"
        "TEXT" "cRaZy -- When you play Lazy Buffy, destroy a card under your opponent's character. Then he or she levels up with the top card of his or her deck."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Rant -- Choose an action on a card under your opponent's character. Your opponent can't use that action next turn. "
    }

    function onThinkMob(player)
        local cards, list_sz = makeListFromCharacterActions(not player, true)
        if list_sz > 0 then
            local card = menuCards(player,cards,"Select a card to remove from the opponent's character actions.","CARDLIST_PEEK")
            if card ~= 0 then
                destroyCharacterAction(player,getCARD(card),false)

                local deckDeck = getPlayerDeck(not player, "DECK_DECK")
                local card_list, qty = getListFromDeck(deckDeck)
                if qty > 0 then
                    drawCard(not player)
                    levelUpScout(not player,false)
                end
            end
        end

        destroyList(cards)
    end

    function onLevelActionTrigger(player)
        skipOpponentCharacterAction(player, true)
    end

}
