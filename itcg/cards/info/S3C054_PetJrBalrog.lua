ZTCG_CARD
{

    "NAME" "Pet Jr. Balrog"
    "IMAGE" "S3C054_PetJrBalrog.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Pet Balrog"
    "COST" "820"

    TYPE_EQP
    {
        "LEVEL" "30"
        "TEXT" "Hungry -- When your turn starts, put the top card of your deck face down under this Pet. (A Pet can have up to 3 cards under it.) Flog -- Whenever one of your monsters attacks, you may put 1 card at random from under Pet Jr. Balrog into your discard pile. If that card was a monster, add its attack value to the monster's attack this turn."
    }

    LVL_ACTION
    {
        "LEVEL" "90"
        "ATTRB" "3"
        "TEXT" "Spawn Unlimited -- Play a monster."
    }

    function onCalcAttackCard(player)
        local src = getSourceCARD()

        local c = countCardsUnder(player,src)
        if c > 0 then
            local cards_under = makeListCardsUnder(player,src)
            if not isEmptyList(cards_under) then
                local card = menuCards(player,cards_under,"Pick a card from under the pet to use.","CARDLIST_HIDE")
                if card ~= 0 then
                    local atk = getBaseAttackFromCARD(getCARD(card))

                    local cardList = takeCardUnder(src,card)

                    local deckGrav = getPlayerDeck(player, "DECK_GRAV")
                    cardList = moveCardsFromListToDeck(cardList,deckGrav,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")

                    destroyList(cardList)

                    if atk > 0 then
                        local dmg = getGameValue(0)
                        updateGameValue(0, dmg + atk)
                    end
                end
            end
        end
    end

    function onStartTurn(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player, src) < 0 then return end

        local deck = getPlayerDeck(player, "DECK_DECK")

        local c = countCardsUnder(player,src)
        if c < 3 then
            local cards = takeCardsFromDeck(deck, 1)
            local card = menuCards(player,cards,"Pick a card to place under the pet.","CARDLIST_HIDE")

            if card ~= 0 then
                cards = takeTargetCardFromList(card,cards)
                putCardUnder(src,card)
            end

            destroyList(cards)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn Unlimited"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY","ZTCG_MAXVALUE")
    end

}
