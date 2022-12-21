ZTCG_CARD
{

    "NAME" "Maple Staff"
    "IMAGE" "S1C036_MapleStaff.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Weapon"
    "COST" "750"

    TYPE_EQP
    {
        "LEVEL" "35"
        "TEXT" "Whenever you would draw a card, you may look at the top 2 cards of your deck instead. Put one into your hand and discard the other."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "2"
        "TEXT" "Think Fast 40 -- Play a tactic of level 40 or less. "
    }

    function onInterceptDrawCard(player)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local grav = getPlayerDeck(player, "DECK_GRAV")

        local cards = takeCardsFromDeck(player,deck, 2)
        local qty = getListLength(cards)
        if qty >= 2 then
            local card = menuCards(player,cards,"Select a card to draw.","CARDLIST_PEEK")
            if card ~= 0 then
                cards = moveCardsFromListToDeck(player,cards,deck,"TAKE_CARDID","PUT_TOP",card)
                cards = moveCardsFromListToDeck(player,cards,grav,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
            end
        else
            cards = moveCardsFromListToDeck(player,cards,deck,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
        end

        destroyList(cards)
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast 40"
        action(player,"ZTCG_NIL","ELEM_ANY",40)
    end

}
