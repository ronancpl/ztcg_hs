ZTCG_CARD
{

    "NAME" "Dark Yeti and Pepe"
    "IMAGE" "S2C048_DarkYetiandPepe.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Dark Ice-Bird Beast"
    "COST" "890"

    TYPE_MOB
    {
        "LEVEL" "82"
        "ATTCK" "50"
        "HP" "70"
        "TEXT" "Split-- When Dark Yeti and Pepe is destroyed, you may search your deck for the card Yeti or the card Pepe and play it. Then shuffle your deck."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "3"
        "TEXT" "Spawn / Equip 90 -- Play a monster or item of level 90 or less. "
    }

    function onReceiveAttackAndSentToDiscardPile(player)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local card_list, qty = getListFromDeck(deck)

        local list1, not_empty1 = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY", "King Ice Bird")
        local list2, not_empty2 = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY", "Ice Beast")

        if not_empty1 or not_empty2 then
            list1 = appendLists(list1,list2)

            local card = menuCards(player,list1,"Select a mob to play.","CARDLIST_PEEK")
            if card ~= 0 then
                local hand = getPlayerDeck(player, "DECK_HAND")

                local cardList = takeTargetCardFromDeck(player,card,deck)
                cardList = moveCardsFromListToDeck(player,cardList,hand,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
                summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")

                destroyList(cardList)
            end
        end

        destroyList(list2)
        destroyList(list1)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 90"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 90)
    end

}
