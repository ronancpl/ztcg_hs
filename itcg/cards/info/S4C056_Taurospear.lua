ZTCG_CARD
{

    "NAME" "Taurospear"
    "IMAGE" "S4C056_Taurospear.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Bull Human"
    "COST" "890"

    TYPE_MOB
    {
        "LEVEL" "75"
        "ATTCK" "70"
        "HP" "50"
        "TEXT" "Prevail -- When Taurospear is destroyed, return it to your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Expert Scout -- If you're level 70 or more, reveal the top 2 cards of your deck. If they're both monsters, draw them. Otherwise put them back in any order."
    }

    function onAttackMobDestroyed(player)
        local src = getSourceCARD()
        local srcCard = makeTargetFromCARD(src)

        local deckGrav = getPlayerDeck(player, "DECK_GRAV")
        local cardList = takeTargetCardFromDeck(srcCard,deckGrav)

        local deckHand = getPlayerDeck(player, "DECK_HAND")
        cardList = moveCardsFromListToDeck(cardList, deckHand,"TAKE_NEXT","PUT_BOTTOM",1)

        destroyList(cardList)
        destroyList(srcCard)
    end

    function onLevelActionTrigger(player)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local cards_taken = takeCardsFromDeck(deck, 2)

        if getListLength(cards_taken) >= 2 then
            local card1 = getCARD(cards_taken)
            local cards_taken2 = takeTargetCardFromList(cards_taken,cards_taken)
            local card2 = getCARD(cards_taken2)

            if(hasSharedFlagsCARD(card1, "FLAG_TYPE", "TYPE_MOB | TYPE_JRB | TYPE_BOS")) and (hasSharedFlagsCARD(card2, "FLAG_TYPE", "TYPE_MOB | TYPE_JRB | TYPE_BOS")) then
                cards_taken = moveCardsFromListToDeck(cards_taken,deck,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
                cards_taken2 = moveCardsFromListToDeck(cards_taken2,deck,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")

                scoutMob(player,"SCOUT_NORMAL","ELEM_ANY")
                scoutMob(player,"SCOUT_NORMAL","ELEM_ANY")
            else
                cards_taken = appendLists(cards_taken,cards_taken2)
                pickCardOrder(player,cards_taken)

                cards_taken = moveCardsFromListToDeck(cards_taken,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            end

            destroyList(cards_taken)
        else
            scoutMob(player,"SCOUT_NORMAL","ELEM_ANY")
        end
    end

}
