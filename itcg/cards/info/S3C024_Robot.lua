ZTCG_CARD
{

    "NAME" "Robot"
    "IMAGE" "S3C024_Robot.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Pet Robot"
    "COST" "850"

    TYPE_EQP
    {
        "LEVEL" "20"
        "TEXT" "Hungry -- When your turn starts, put the top card of your deck face down under this Pet. (A Pet can have up to 3 cards under it.) Power Surge - When Robot has 3 cards under it, reveal them. You may play 1 tactic revealed this way and put the others on the bottom of your deck in any order. "
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Quest -- Draw a card."
    }

    function onStartTurn(player)
        local src = getSourceCARD()
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

        local c = countCardsUnder(player,src)
        if c >= 3 then
            local hand = getPlayerDeck(player, "DECK_HAND")
            local card_list = removeCardsUnder(src)

            local pet_spawns = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ACT","ELEM_ANY","ZTCG_NIL")

            local pet_spawn = menuCards(player,pet_spawns,"Select a tactic to play.","CARDLIST_PEEK")
            if pet_spawn ~= 0 then
                card_list = takeTargetCardFromListToDeck(player,hand,card_list,pet_spawn,"DECK_BOTTOM")
                action(player,getCARD(pet_spawn),"ELEM_ANY","ZTCG_DONTCARE")
            end

            pickCardOrder(player,card_list)
            card_list = moveCardsFromListToDeck(player,card_list,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

            destroyList(pet_spawns)
            destroyList(card_list)
        end
    end

    function onLevelActionTrigger(player)
        drawCard(player)
    end

}
