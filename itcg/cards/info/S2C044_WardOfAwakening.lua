ZTCG_CARD
{

    "NAME" "Ward Of Awakening"
    "IMAGE" "S2C044_WardOfAwakening.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "610"

    TYPE_ACT
    {
        "LEVEL" "50"
        "TEXT" "Play a tactic from any discard pile. Then return it to that discard pile."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn / Think Fast 70 -- Play a monster or tactic of level 70 or less. "
    }

    function onThinkAction(player)
        local player_deck = getPlayerDeck(player, "DECK_GRAV")
        local opponent_deck = getPlayerDeck(not player, "DECK_GRAV")

        local deck_list1 = getListFromDeck(player_deck)
        local deck_list2 = getListFromDeck(opponent_deck)

        local card_list1 = makeFilteredList(player,deck_list1,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ACT", "ELEM_ANY", "ZTCG_NIL")
        local card_list2 = makeFilteredList(player,deck_list2,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ACT", "ELEM_ANY", "ZTCG_NIL")
        card_list1 = appendLists(card_list1,card_list2)

        local card = menuCards(player,card_list1,"Select a card to activate.","CARDLIST_PEEK")
        if card ~= 0 then
            action(player,getCARD(card),"ELEM_ANY","ZTCG_DONTCARE")
        end

        destroyList(card_list2)
        destroyList(card_list1)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 70"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 70)
    end

}
