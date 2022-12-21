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
            local card_list = takeCardsFromDeck(player,deck, 1)
            local card = makeTargetFromCARD(getCARD(card_list))

            if card ~= 0 then
                card_list = takeTargetCardFromList(card,card_list)
                putCardUnder(src,card)
            end

            destroyList(card_list)
        end

        local deck = getPlayerDeck(player, "DECK_DECK")
        local c = countCardsUnder(player,src)
        if c >= 3 then
            local hand = getPlayerDeck(player, "DECK_HAND")
            local card_list = removeCardsUnder(src)

            local pet_spawns,not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP","ELEM_ANY","ZTCG_NIL")
            if not_empty then
                local pet_spawn = menuCards(player,pet_spawns,"Select a card to equip.","CARDLIST_PEEK")
                if pet_spawn ~= 0 then
                    card_list = takeTargetCardFromList(pet_spawn,card_list)
                    pet_spawns = takeTargetCardFromListToDeck(player,hand,pet_spawns,pet_spawn,"DECK_BOTTOM")
                    equip(player,"PLAY_SCOUTEQUIP","ELEM_ANY","ZTCG_MAXVALUE")
                end
            end

            pickCardOrder(player,card_list)
            card_list = moveCardsFromListToDeck(player,card_list,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

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

    function onOpponentCardDestroyed(player)
        local target = getTargetCARD()
        if(hasSharedFlagsCARD(target, "FLAG_TYPE", "TYPE_ANYMOB")) then
            local src = getSourceCARD()
            local cardid = getCardIdFromCARD(src)

            local n = getCardRegister(src,cardid,0)
            editCardRegister(src,cardid,0,n + 1,0,nil)
        end
    end

}
