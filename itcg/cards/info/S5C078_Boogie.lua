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

    function bossLevelDrop(player,card,src)
        newCardLevelDrop(card,src,20,1)
    end

    function undoBossesLevelDrop(player)
        local src = getSourceCARD()

        local deck_hand = getPlayerDeck(player, "DECK_HAND")
        local card_list = getListFromDeck(deck_hand)
        card_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY", "ELEM_ANY", "ZTCG_NIL")

        local menuCard
        while not isEmptyList(card_list) do
            card_list, menuCard = takeNextCardsFromList(card_list,1)

            local card = getCARD(menuCard)
            removeCardLevelDrop(card,src)

            destroyList(menuCard)
        end

        destroyList(card_list)
    end

    function applyBossesLevelDrop(player)
        local src = getSourceCARD()

        local deckHand = getPlayerDeck(player, "DECK_HAND")
        local card_list, qty = getListFromDeck(deckHand)

        local new_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_JRB | TYPE_BOS", "ELEM_ANY", "ZTCG_NIL")
        if not_empty then
            local menuCard
            while not isEmptyList(new_list) do
                new_list, menuCard = takeNextCardsFromList(new_list,1)

                local card = getCARD(menuCard)
                destroyList(menuCard)

                bossLevelDrop(player,card,src)
            end
        end

        destroyList(new_list)
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        undoBossesLevelDrop(player)
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        applyBossesLevelDrop(player)
    end

    function onReceiveAttackAndDestroyed(player)
        undoBossesLevelDrop(player)
    end

    function onPutCardIntoHand(player)
        local src = getSourceCARD()
        local target = getTargetCARD()

        if isBossCARD(target) then
            bossLevelDrop(player,target,src)
        end
    end

    function onActivateCharacterAction(player)
        local card = peekNextCard(player)
        if card ~= 0 then
            if isBossCARD(card) then
                drawCard(player)
            else
                local deck_list = getPlayerDeck(player, "DECK_DECK")
                local list_cards = takeCardsFromDeck(player,deck_list, 1)
                list_cards = moveCardsFromListToDeck(player,list_cards,deck_list,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
                destroyList(list_cards)
            end
        end
    end

}
