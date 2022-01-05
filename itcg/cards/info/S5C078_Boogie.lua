ZTCG_CARD
{

    "NAME" "Boogie"
    "IMAGE" "S5C078_Boogie.png"
    "TYPE" "MOB"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Zakum Guardian"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "35"
        "ATTCK" "30"
        "HP" "40"
        "TEXT" "Trusted Servant -- You may play each of your Boss monsters as if it were 20 levels less."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "0"
        "TEXT" "Boss Hunting 1 -- Reveal the top card of your deck. If it's a Boss, draw it. Otherwise, put it on the bottom of your deck."
    }

    function onActivateCharacterAction(player)
        local card = peekNextCard(player)
        if isBossCARD(card) then
            drawCard(player)
        else
            local deck_list = getPlayerDeck(player, "DECK_DECK")
            local list_cards = takeCardsFromDeck(deck_list, 1)
            list_cards = moveCardsFromListToDeck(list_cards,deck_list,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            destroyList(list_cards)
        end
    end

}
