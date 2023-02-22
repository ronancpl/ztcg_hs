ZTCG_CARD
{

    "NAME" "Crop of Mushrooms"
    "IMAGE" "S5C041_CropofMushrooms.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Mushroom Upgrade"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "40"
        "ATTCK" "70"
        "HP" "60"
        "TEXT" "Mushroom Upgrade -- Put on one of your Mushroom monsters. Loot -- When you play Crop of Mushrooms, if your opponent has 3 or more cards in hand, he or she chooses one and discards it."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Mushroom Respawn -- Play a Mushroom of your level or less from your discard pile."
    }

    function makeInfoTableList(player,info)
        return makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY",info)
    end

    function destroyCardUnder(player,mob)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local hand = getPlayerDeck(player, "DECK_HAND")
        local grav = getPlayerDeck(player, "DECK_GRAV")

        local mob_target = makeTargetFromCARD(mob)
        moveCards(player,deck,hand,"TAKE_CARDID","PUT_BOTTOM",mob_target)

        if summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE") then
            local slotid = getSlotIdFromCARD(player, mob)
            destroySelf(player,"SLOT_PLAYERMOB" .. slotid)
        else
            moveCards(player,hand,grav,"TAKE_CARDID","PUT_TOP",mob_target)
        end

        destroyList(mob_target)

        local src = getSourceCARD()
        local src_target = makeTargetFromCARD(src)
        moveCards(player,grav,grav,"TAKE_CARDID","PUT_TOP",src_target)
        destroyList(src_target)
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
        local mobs, not_empty = makeInfoTableList(player,"Mushroom")

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

    function onThinkMob(player)
        local hand = getPlayerDeck(not player, "DECK_HAND")
        local cards, qty = getListFromDeck(hand)

        if qty >= 3 then
            discardCard(not player)
        end
    end

    function onLevelActionTrigger(player)
        local grav = getPlayerDeck(player, "DECK_GRAV")
        local card_list, qty = getListFromDeck(grav)
        local list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY","Mushroom")

        if not_empty then
            local card = menuCards(player,list,"Select a card to revive.","CARDLIST_PEEK")
            if card ~= 0 then
                local hand = getPlayerDeck(player, "DECK_HAND")

                card = takeTargetCardFromDeck(player,card,grav)
                card = moveCardsFromListToDeck(player,card,hand,"TAKE_CARDID","PUT_BOTTOM",card)
                summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")

                destroyList(card)
            end
        end

        destroyList(list)
    end

}
