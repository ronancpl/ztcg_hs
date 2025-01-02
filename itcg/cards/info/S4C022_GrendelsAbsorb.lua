ZTCG_CARD
{

    "NAME" "Grendel's Absorb"
    "IMAGE" "S4C022_GrendelsAbsorb.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "800"

    TYPE_ACT
    {
        "LEVEL" "80"
        "TEXT" "If you have fewer cards in hand than your opponent, draw cards until you have the same number of cards as your opponent. Then your opponent chooses and discards as many cards from his or her hand as you drew."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Grendel Team Up -- Draw a card. If you're level 60 or more, you may play Grendel the Really Old."
    }

    function onThinkAction(player)
        local deckHand = getPlayerDeck(player,"DECK_HAND")
        local list, qty = getListFromDeck(deckHand)

        local deckHand2 = getPlayerDeck(not player,"DECK_HAND")
        local list2, qty2 = getListFromDeck(deckHand2)

        if qty < qty2 then
            for i = qty,qty2-1,1 do
                drawCard(player)
            end

            for i = qty2,qty+1,-1 do
                discardCard(not player)
            end
        end
    end

    function onLevelActionTrigger(player)
        drawCard(player)

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        local deckHand = getPlayerDeck(player, "DECK_HAND")
        local card_list, qty = getListFromDeck(deckHand)

        local list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY","Grendel the Really Old")
        if level >= 60 and not_empty then
            local card = menuCards(player,list,"Select a mob to spawn.","CARDLIST_PEEK")
            if card ~= 0 then
                moveCards(player,deckHand,deckHand,"TAKE_CARDID","PUT_BOTTOM",card)
                summon(player,"PLAY_SCOUTSUMMON","ELEM_ANY","ZTCG_MAXVALUE")
            end
        end
        destroyList(list)
    end

}
