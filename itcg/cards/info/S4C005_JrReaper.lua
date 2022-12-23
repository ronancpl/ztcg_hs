ZTCG_CARD
{

    "NAME" "Jr. Reaper"
    "IMAGE" "S4C005_JrReaper.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Pet Undead Spook"
    "COST" "570"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "Hungry -- When your turn starts, put the top card of your deck face down under this Pet. (A Pet can have up to 3 cards under it.) Death Cord -- When Jr. Reaper has 3 cards under it, reveal them. Put any Spooks revealed this way into your hand and the others on the bottom of your deck in any order."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "1"
        "TEXT" "Spawn 70 -- Play a monster of level 70 or less."
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

            local pet_spawns = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_MOB","ELEM_ANY","Spook")
            while not isEmptyList(pet_spawns) do
                local pet_spawn = menuCards(player,pet_spawns,"Select a card to draw.","CARDLIST_PEEK")
                if pet_spawn == 0 then
                    break
                end

                revealCard(not player,"Opponent has drawn card...",getCARD(pet_spawn))

                card_list = takeTargetCardFromList(pet_spawn,card_list)
                pet_spawns = takeTargetCardFromListToDeck(player,hand,pet_spawns,pet_spawn,"DECK_BOTTOM")
            end

            pickCardOrder(player,card_list)
            card_list = moveCardsFromListToDeck(player,card_list,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

            destroyList(pet_spawns)
            destroyList(card_list)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 70"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",70)
    end

}
