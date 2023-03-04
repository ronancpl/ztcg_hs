ZTCG_CARD
{

    "NAME" "Porcupine"
    "IMAGE" "S3C023_Porcupine.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Pet Porcupine"
    "COST" "850"

    TYPE_EQP
    {
        "LEVEL" "30"
        "TEXT" "Hungry -- When your turn starts, put the top card of your deck face down under this Pet. (A Pet can have up to 3 cards under it.) Quillspray -- Whenever your turn starts, you may put the cards under Porcupine on the bottom of your deck in any order. For each card you put under your deck this way, do 10 damage to each of your opponent's monsters and then to your opponent's character."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "1"
        "TEXT" "Quill Attack -- Choose a character. For each pet you have, do 10 damage to that character."
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
                card = putCardUnder(src,card)
            end

            destroyList(card)
            destroyList(card_list)
        end

        local c = countCardsUnder(player,src)
        if c >= 0 then
            local hand = getPlayerDeck(player, "DECK_HAND")

            local q = 0

            local card_list = makeListCardsUnder(player,src)
            local pet_spawns = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY","ZTCG_NIL")
            while not isEmptyList(pet_spawns) do
                local pet_spawn = menuCards(player,pet_spawns,"Select a card to send to bottom of the deck, for active effect Quillspray.","CARDLIST_HIDE")
                if pet_spawn == 0 then
                    break
                end

                local card = takeCardUnder(src,pet_spawn)
                card = moveCardsFromListToDeck(player,card,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
                destroyList(card)

                pet_spawns = takeTargetCardFromList(pet_spawn,pet_spawns)
                q = q + 1
            end

            destroyList(pet_spawns)
            destroyList(card_list)

            for i = 1, q, 1 do
                attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_EQP", "SLOT_ADVSRYMOB1", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
                attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_EQP", "SLOT_ADVSRYMOB2", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
                attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_EQP", "SLOT_ADVSRYMOB3", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
                attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_EQP", "SLOT_ADVSRYMOB4", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
                attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_EQP", "SLOT_ADVSRYMOB5", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
                attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_EQP", "SLOT_ADVSRYMOB6", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
                attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_EQP", "SLOT_ADVSRYMOB7", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
                attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_EQP", "SLOT_ADVSRYCHAR", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
            end
        end
    end

    function onActivateCharacterAction(player)
        local pet_list = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP","ELEM_ANY","Pet")
        local pet_count = getListLength(pet_list)
        destroyList(pet_list)

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        for i = 1, pet_count, 1 do
            attack(player, chr, 10, "ATKRES_DONT_HIT_MOBS", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

}
