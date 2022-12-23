ZTCG_CARD
{

    "NAME" "Malady"
    "IMAGE" "S5C031_Malady.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Flying Witch"
    "COST" "800"

    TYPE_MOB
    {
        "LEVEL" "55"
        "ATTCK" "40"
        "HP" "40"
        "TEXT" "Tactician 20 -- When you play Malady, you may play a tactic of level 20 or less from your hand or discard pile. Then put that card on the bottom of your deck."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn / Think Fast 70 -- Play a monster of level 70 or less."
    }

    function onThinkMob(player)
        local player_grav = getPlayerDeck(player, "DECK_GRAV")
        local player_hand = getPlayerDeck(player, "DECK_HAND")
        local player_deck = getPlayerDeck(player, "DECK_DECK")

        local deck_list1 = getListFromDeck(player_grav)
        local deck_list2 = getListFromDeck(player_hand)

        local card_list1 = makeFilteredList(player,deck_list1,0,0,20,"TYPE_ACT", "ELEM_ANY", "ZTCG_NIL")
        local card_list2 = makeFilteredList(player,deck_list2,0,0,20,"TYPE_ACT", "ELEM_ANY", "ZTCG_NIL")
        card_list1 = appendLists(card_list1,card_list2)

        local card = menuCards(player,card_list1,"Select a card to activate.","CARDLIST_PEEK")
        if card ~= 0 then
            action(player,getCARD(card),"ELEM_ANY","ZTCG_DONTCARE")

            local list = takeTargetCardFromDeck(player,card,player_grav)
            if isEmptyList(list) then
                list = takeTargetCardFromDeck(player,card,player_hand)
            end
            list = moveCardsFromListToDeck(player,list,player_deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            destroyList(list)
        end

        destroyList(card_list2)
        destroyList(card_list1)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 70"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 70)
    end
}
