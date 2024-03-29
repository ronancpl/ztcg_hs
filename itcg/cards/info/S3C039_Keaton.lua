ZTCG_CARD
{

    "NAME" "Keaton"
    "IMAGE" "S3C039_Keaton.png"
    "TYPE" "CHAR"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Hermit"
    "COST" "800"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card."
        }
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "1"
            "TEXT" "Equip 30 -- Play an item of level 30 or less."
        }
        LVL_ACTION
        {
            "LEVEL" "50"
            "ATTRB" "1"
            "TEXT" "Feeding Frenzy -- Put cards from the top of your deck face down under one of your Pets until that Pet has 3 cards under it."
        }
        "HP" "200"
    }

    function onActivateCharacterAction1(player)
        drawCard(player)
    end

    function onActivateCharacterAction2(player)
        equip(player, "PLAY_NORMALEQUIP","ELEM_ANY",30)
    end

    function makeFilteredPetFeedList(player)
        local menu = makeFilteredTableList(player, "ONLY_PLAYER", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_EQP", "ELEM_ANY", "Pet")

        local petMenu = makeFilteredTableList(player, "ONLY_PLAYER", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_EQP", "ELEM_ANY", "Pet")
        local pet
        while not isEmptyList(petMenu) do
            petMenu, pet = takeNextCardsFromList(petMenu,1)
            if countCardsUnder(player, getCARD(pet)) >= 3 then
                menu = takeTargetCardFromList(pet,menu)
            end
            destroyList(pet)
        end
        destroyList(petMenu)

        return menu, not isEmptyList(menu)
    end

    function onActivateCharacterAction3(player)
        local menu, notEmpty = makeFilteredPetFeedList(player)
        if notEmpty then
            local pet = menuCards(player,menu,"Select a pet to feed.","CARDLIST_PEEK")
            if pet ~= 0 then
                local count = countCardsUnder(player, getCARD(pet))
                if count < 3 then
                    local deck = getPlayerDeck(player, "DECK_DECK")
                    local cards_taken = takeCardsFromDeck(player,deck, 3 - count)

                    while getListLength(cards_taken) > 0 do
                        local card = makeTargetFromCARD(getCARD(cards_taken))

                        cards_taken = takeTargetCardFromList(card,cards_taken)
                        card = putCardUnder(getCARD(pet),card)

                        destroyList(card)
                    end

                    destroyList(cards_taken)
                end
            end
        end

        destroyList(menu)
    end

}
