ZTCG_CARD
{

    "NAME" "Knowledge Is Power"
    "IMAGE" "S1C032_KnowledgeIsPower.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "560"

    TYPE_ACT
    {
        "LEVEL" "20"
        "TEXT" "Search your deck for a tactic card, reveal it, and put it in your hand. Then shuffle your deck."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "3"
        "TEXT" "Think Fast X -- Play a tactic of your level or less. "
    }

    function onThinkAction(player)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local card_list, qty = getListFromDeck(deck)

        if qty > 0 then
            local cards = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ACT","ELEM_ANY","ZTCG_NIL")

            local card = menuCards(player,cards,"Select a tactic to draw.","CARDLIST_PEEK")
            if card ~= 0 then
                local hand = getPlayerDeck(player, "DECK_HAND")
                moveCards(player,deck,hand,"TAKE_CARDID","PUT_BOTTOM",card)

                revealCard(not player,"Opponent has drawn card...",getCARD(card))
                shuffleDeck(player,"DECK_DECK")
            end

            destroyList(cards)
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        action(player,"ZTCG_NIL","ELEM_ANY",level)
    end

}
