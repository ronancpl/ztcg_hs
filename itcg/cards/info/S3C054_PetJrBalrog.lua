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

    function onStartTurn(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player, src) < 0 then return end

        local cid = getCardIdFromCARD(src)
        editCardRegister(src, cid, 0, 0, 0, nil)    -- atkr slot
        editCardRegister(src, cid, 1, 0, 0, nil)    -- dmg
        editCardRegister(src, cid, 2, 0, 0, nil)    -- recently used slot

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
    end

    function onCalcAttackCard(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(0)

        local slot = getCardRegister(src, cid, 2)
        if slot == getSlotIdFromCARD(player, atkr) then
            return
        end

        local atk = getCardRegister(src, cid, 1)
        local slot = getCardRegister(src, cid, 0)
        if hasFlag("ZTCG_ATTACKSTATE", "THINK_ATTACK") and slot == 0 then
            slot = getSlotIdFromCARD(player, atkr)

            if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
                local c = countCardsUnder(player,src)
                if c > 0 then
                    local cards_under = makeListCardsUnder(player,src)
                    if not isEmptyList(cards_under) then
                        local card = menuCards(player,cards_under,"Pick a card from under the pet to use.","CARDLIST_HIDE")
                        if card ~= 0 then
                            revealCard(not player,"Opponent has drawn card...",getCARD(card))

                            atk = getBaseAttackFromCARD(getCARD(card))
                            editCardRegister(src, cid, 0, slot, 0, nil)
                            editCardRegister(src, cid, 1, atk, 0, nil)

                            local cardList = takeCardUnder(src,card)

                            local deckGrav = getPlayerDeck(player, "DECK_GRAV")
                            cardList = moveCardsFromListToDeck(player,cardList,deckGrav,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")

                            destroyList(cardList)
                        else
                            editCardRegister(src, cid, 2, slot, 0, nil)
                        end
                    end

                    destroyList(cards_under)
                end
            end
        else
            local card = getOnBoardCARD(player, "SLOT_PLAYERMOB" .. slot)
            if not isSameCARD(atkr,card) then
                atk = 0
            end
        end

        if atk > 0 then
            local dmg = getGameValue(0)
            updateGameValue(0, dmg + atk)
        end
    end

    function onExecuteAttackCard(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player, src) < 0 then return end

        local cid = getCardIdFromCARD(src)
        editCardRegister(src, cid, 0, 0, 0, nil)
        editCardRegister(src, cid, 1, 0, 0, nil)
        editCardRegister(src, cid, 2, 0, 0, nil)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn Unlimited"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY","ZTCG_MAXVALUE")
    end

}
