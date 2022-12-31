ZTCG_CARD
{

    "NAME" "Braddock"
    "IMAGE" "S4C016_Braddock.png"
    "TYPE" "CHAR"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Ice/Lightning Mage"
    "COST" "900"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "1"
            "TEXT" "Peer -- Look at the top card of your deck. Put it back on the top or the bottom of your deck."
        }
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card."
        }
        LVL_ACTION
        {
            "LEVEL" "50"
            "ATTRB" "2"
            "TEXT" "Spawn / Think Fast 50 -- Play a monster or tactic of level 50 or less."
        }
        "HP" "190"
    }

    function onActivateCharacterAction1(player)
        local card = peekNextCard(player)
        if card ~= 0 then
            local deck_list = getPlayerDeck(player, "DECK_DECK")
            local list_cards = takeCardsFromDeck(player,deck_list, 1)

            if(makePrompt(player,false,"Draw " .. getNameFromCARD(card) .. "?","Or insert it on the bottom of the deck?","ZTCG_NIL","ZTCG_NIL","Top","Bottom")) then
                list_cards = moveCardsFromListToDeck(player,list_cards,deck_list,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
            else
                list_cards = moveCardsFromListToDeck(player,list_cards,deck_list,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            end

            destroyList(list_cards)
        end
    end

    function onActivateCharacterAction2(player)
        drawCard(player)
    end

    function onActivateCharacterAction3(player)
        local str = "Spawn / Think Fast 50"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 50)
    end

}
