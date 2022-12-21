ZTCG_CARD
{

    "NAME" "Black Dragon"
    "IMAGE" "S3C031_BlackDragon.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Pet Dragon"
    "COST" "930"

    TYPE_EQP
    {
        "LEVEL" "20"
        "TEXT" "Hungry -- When your turn starts, put the top card of your deck face down under this Pet. (A Pet can have up to 3 cards under it.) Morph -- When your turn starts, you may put 3 cards from under Black Dragon on the bottom of your deck in any order. If you do, it becomes a monster with 80 attack and 120 HP until your next turn starts."
    }

    LVL_ACTION
    {
        "LEVEL" "10"
        "ATTRB" "1"
        "TEXT" "Feeding Time -- If one of your Pets has fewer than 3 cards under it, put the top card of your deck face down under that Pet."
    }

    function afterCharacterActions(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        if getCardRegister(src,cardid,0) > 0 then
            attack(player, src, 80, "ATKRES_NIL", "ATKSRC_EQP", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

    function onStartTurn(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player, src) < 0 then return end

        local cardid = getCardIdFromCARD(src)
        editCardRegister(src,cardid,0,0,0,nil)

        local src = getSourceCARD()
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

        local c = countCardsUnder(player,src)
        if c >= 3 then
            local card_list = removeCardsUnder(src)
            pickCardOrder(player,card_list)
            card_list = moveCardsFromListToDeck(player,card_list,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            destroyList(card_list)

            editCardRegister(src,cardid,0,1,0,nil)
        end
    end

    function onActivateCharacterAction(player)
        local menu, notEmpty = makeFilteredTableList(player, "ONLY_PLAYER", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_EQP", "ELEM_ANY", "Pet")
        if notEmpty then
            local pet = menuCards(player,menu,"Select a pet to feed.","CARDLIST_PEEK")
            if pet ~= 0 and countCardsUnder(player, getCARD(pet)) < 3 then
                local deck = getPlayerDeck(player, "DECK_DECK")
                local card_list = takeCardsFromDeck(player,deck, 1)

                local card = makeTargetFromCARD(getCARD(card_list))
                if card ~= 0 then
                    putCardUnder(getCARD(pet),card)
                    card_list = takeTargetCardFromList(card,card_list)
                end

                destroyList(card_list)
            end
        end

        destroyList(menu)
    end

}
