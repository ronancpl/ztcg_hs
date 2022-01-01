ZTCG_CARD
{

    "NAME" "Mini Yeti"
    "IMAGE" "S3C042_MiniYeti.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Pet Beast"
    "COST" "840"

    TYPE_EQP
    {
        "LEVEL" "30"
        "TEXT" "Hungry -- When your turn starts, put the top card of your deck face down under this Pet. (A Pet can have up to 3 cards under it.) Auto-loot -- When Mini Yeti has 3 cards under it, reveal them. You may play 1 item revealed this way and put the others on the bottom of your deck in any order."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Get Treasure -- When your turn ends, draw a card for each monster you destroyed this turn."
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        editCardRegister(src,cardid,0,0,0,nil)

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

        local deck = getPlayerDeck(player, "DECK_DECK")
        local c = countCardsUnder(player,src)
        if c >= 3 then
            local hand = getPlayerDeck(player, "DECK_HAND")
            local card_list = removeCardsUnder(src)

            local pet_spawns,not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP","ELEM_ANY","ZTCG_NIL")
            if not_empty then
                local pet_spawn = menuCards(player,pet_spawns,"Select a card to equip.","CARDLIST_HIDE")
                if pet_spawn ~= 0 then
                    card_list = takeTargetCardFromList(pet_spawn,card_list)
                    pet_spawns = takeTargetCardFromListToDeck(hand,pet_spawns,pet_spawn,"DECK_BOTTOM")
                    equip(player,"PLAY_SCOUTEQUIP","ELEM_ANY","ZTCG_MAXVALUE")
                end
            end

            pet_spawns = moveCardsFromListToDeck(pet_spawns,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            card_list = moveCardsFromListToDeck(card_list,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

            destroyList(pet_spawns)
            destroyList(card_list)
        end
    end

    function onEndTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        if getCardRegister(src,cardid,1) ~= 0 then
            local n = getCardRegister(src,cardid,0)
            for i = 1, n, 1 do
                drawCard(player)
            end

            editCardRegister(src,cardid,1,0,0,nil)
        end
    end

    function onLevelActionTrigger(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        insertCardTurnAction(player)
        editCardRegister(src,cardid,1,1,0,nil)
    end

    function onOpponentMobSentToDiscardPile(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local n = getCardRegister(src,cardid,0)
        editCardRegister(src,cardid,0,n + 1,0,nil)
    end

}
