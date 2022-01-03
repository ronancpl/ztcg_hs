ZTCG_CARD
{

    "NAME" "Shawn's Descent"
    "IMAGE" "S4C054_ShawnsDescent.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Strategy"
    "COST" "720"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "Look at the top 5 cards of your deck. You may reveal a monster card from among them and put it into your hand. Put the others on the bottom of your deck in any order."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Think Fast / Equip 70 -- Play a tactic or item of level 70 or less."
    }

    function onThinkAction(player)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local cards_taken = takeCardsFromDeck(deck,5)

        local mob_list = makeFilteredList(player,cards_taken,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
        local card = menuCards(player,mob_list,"Select a monster to draw.","CARDLIST_PEEK")
        if card ~= 0 then
            local hand = getPlayerDeck(player, "DECK_HAND")
            cards_taken = moveCardsFromListToDeck(cards_taken,hand,"TAKE_CARDID","PUT_BOTTOM",card)
        end
        cards_taken = moveCardsFromListToDeck(cards_taken,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

        destroyList(mob_list)
        destroyList(cards_taken)
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 70"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 70)
    end

}
