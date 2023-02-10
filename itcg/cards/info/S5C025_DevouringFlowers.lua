ZTCG_CARD
{

    "NAME" "Devouring Flowers"
    "IMAGE" "S5C025_DevouringFlowers.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Flora Upgrade"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "22"
        "ATTCK" "30"
        "HP" "90"
        "TEXT" "Flora Upgrade -- Put on one of your Flora monsters. Plant Seeds -- Whenever Devouring Flowers attacks, you may return a Flora card from your discard pile to your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Floral Hunt 3 -- Reveal the top 3 cards of your deck. Put any Floras revealed this way into your hand and the others on the bottom of your deck in any order."
    }

    function makeInfoTableList(player,info)
        return makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY",info)
    end

    function destroyCardUnder(player,mob)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local hand = getPlayerDeck(player, "DECK_HAND")

        local mob_target = makeTargetFromCARD(mob)
        moveCards(player,deck,hand,"TAKE_CARDID","PUT_BOTTOM",mob_target)
        destroyList(mob_target)

        if summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE") then
            local slotid = getSlotIdFromCARD(player, mob)
            destroySelf(player,"SLOT_PLAYERMOB" .. slotid)

            local src = getSourceCARD()
            local src_target = makeTargetFromCARD(src)
            local grav = getPlayerDeck(player, "DECK_GRAV")
            moveCards(player,grav,grav,"TAKE_CARDID","PUT_TOP",src_target)
            destroyList(src_target)
        end
    end

    function onReceiveAttackAndSentToDiscardPile(player)
        local src = getSourceCARD()
        local card = getCardUnder(src,0)
        local mob = getCARD(card)

        setCardPointer(3, mob)
    end

    function onReceiveAttackAndDestroyed(player)
        local mob = getCardPointer(3)
        if mob ~= 0 then
            destroyCardUnder(player,mob)
        end
    end

    function onTryPlay(player)
        local mobs, not_empty = makeInfoTableList(player,"Flora")

        if hasFlag("ZTCG_TRYPLAY","IS_TRY_TABLE") then
            local mob = menuCards(player,mobs,"Select a card to upgrade.","CARDLIST_PEEK")
            if mob ~= 0 then
                local slotid = getSlotIdFromCARD(player, getCARD(mob))
                local card_list = takeCardFromTable(player, "SLOT_PLAYERMOB" .. slotid)

                local src = getSourceCARD()
                card_list = putCardUnder(src,card_list)
                destroyList(card_list)
            else
                updateGameValue(0,0)
            end
        elseif not not_empty then
            updateGameValue(0,0)    -- prevent spawn
        end

        destroyList(mobs)
    end

    function onExecuteAttack(player)
        local grav = getPlayerDeck(player, "DECK_GRAV")
        local card_list = getListFromDeck(grav)

        local mob_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","Flora")
        if not_empty then
            local card = menuCards(player,mob_list,"Select a monster to draw.","CARDLIST_PEEK")
            if card ~= 0 then
                local hand = getPlayerDeck(player, "DECK_HAND")
                moveCards(player,grav,hand,"TAKE_CARDID","PUT_BOTTOM",card)
            end
        end

        destroyList(mob_list)
    end

    function onLevelActionTrigger(player)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local cards_taken = takeCardsFromDeck(player,deck,3)

        local mob_list = makeFilteredList(player,cards_taken,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","Flora")
        while getListLength(mob_list) > 0 do
            local card = menuCards(player,mob_list,"Select a monster to draw.","CARDLIST_PEEK")
            if card ~= 0 then
                local hand = getPlayerDeck(player, "DECK_HAND")
                cards_taken = moveCardsFromListToDeck(player,cards_taken,hand,"TAKE_CARDID","PUT_BOTTOM",card)

                mob_list = takeTargetCardFromList(card,mob_list)
            else
                break
            end
        end

        pickCardOrder(player,cards_taken)
        cards_taken = moveCardsFromListToDeck(player,cards_taken,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

        destroyList(mob_list)
        destroyList(cards_taken)
    end

}
