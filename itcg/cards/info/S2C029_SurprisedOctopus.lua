ZTCG_CARD
{

    "NAME" "Surprised Octopus"
    "IMAGE" "S2C029_SurprisedOctopus.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Alien"
    "COST" "540"

    TYPE_MOB
    {
        "LEVEL" "12"
        "ATTCK" "20"
        "HP" "20"
        "TEXT" "Panic -- When you play Surprised Octopus, look at the top 3 cards of your deck and put them back in any order."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "1"
        "TEXT" "Think Fast 90 -- Play a tactic of level 90 or less. "
    }

    function onThinkMob(player)
        local deck = getPlayerDeck(player, "DECK_DECK")

        local cards = takeCardsFromDeck(deck, 3)
        pickCardOrder(player,cards)

        cards = moveCardsFromListToDeck(cards,deck,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
        destroyList(cards)
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast 90"
        action(player,"ZTCG_NIL","ELEM_ANY",90)
    end

}
