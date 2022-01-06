ZTCG_CARD
{

    "NAME" "Pack of Boars"
    "IMAGE" "S5C071_PackofBoars.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Boar Upgrade"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "42"
        "ATTCK" "70"
        "HP" "70"
        "TEXT" "Boar Upgrade -- Put on one of your Boar monsters. Scout -- When you play Pack of Boars, reveal the top card of your deck. If it's a monster, put it into your hand. Otherwise, put it back."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Boar Scout -- Reveal the top card of your deck. If it's a Boar card, put it into your hand. Otherwise, put it back."
    }

    function onThinkMob(player)
        scoutMob(player,"SCOUT_NORMAL","ELEM_ANY")
    end

    function onActivateCharacterAction(player)
        local card = peekNextCard(player)

        local deck = getPlayerDeck(player, "DECK_DECK")
        local hand = getPlayerDeck(player, "DECK_HAND")
        local list_cards = takeCardsFromDeck(deck, 1)

        if not isInfoCARD(getCARD(list_cards), "Boar") then
            list_cards = moveCardsFromListToDeck(list_cards,deck,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
        else
            list_cards = moveCardsFromListToDeck(list_cards,hand,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
        end

        destroyList(list_cards)
    end

}