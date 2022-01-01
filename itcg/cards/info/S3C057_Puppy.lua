ZTCG_CARD
{

    "NAME" "Puppy"
    "IMAGE" "S3C057_Puppy.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Pet Dog"
    "COST" "650"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "Hungry -- When your turn starts, put the top card of your deck face down under this Pet. (A Pet can have up to 3 cards under it.) Dog's Life -- When Puppy has 3 cards under it, get +30 HP and put those cards on the bottom of your deck in any order"
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Spawn 50 -- Play a monster of level 50 or less."
    }

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

        local c = countCardsUnder(player,src)
        if c >= 3 then
            local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            refreshHP(player,card,30)

            local hand = getPlayerDeck(player, "DECK_HAND")
            local card_list = removeCardsUnder(src)

            pickCardOrder(player,card_list)
            card_list = moveCardsFromListToDeck(card_list,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

            destroyList(card_list)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 50"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",50)
    end

}
