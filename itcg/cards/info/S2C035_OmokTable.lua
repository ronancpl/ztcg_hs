ZTCG_CARD
{

    "NAME" "Omok Table"
    "IMAGE" "S2C035_OmokTable.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Minigame"
    "COST" "670"

    TYPE_EQP
    {
        "LEVEL" "30"
        "TEXT" "When your turn starts, you may look at the top card of your deck. Put it back on the top or the bottom of your deck."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Think Fast / Equip 80   -- Play a tactic or item of level 80 or less. "
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        local card = peekNextCard(player)
        if card ~= 0 then
            local deck_list = getPlayerDeck(player, "DECK_DECK")
            local list_cards = takeCardsFromDeck(player,deck_list, 1)

            if(makePrompt(player,false,"Draw " .. getNameFromCARD(card) .. "?","Or insert it on the bottom of the deck?","ZTCG_NIL","ZTCG_NIL","Top","Bottom")) then
                list_cards = moveCardsFromListToDeck(player,list_cards,deck_list,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
            else
                list_cards = moveCardsFromListToDeck(player,list_cards,deck_list,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            end

            destroyList(list_cards)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 80"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 80)
    end

}
