ZTCG_CARD
{

    "NAME" "Goo Zoo"
    "IMAGE" "S5C063_GooZoo.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Goo Upgrade"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "40"
        "ATTCK" "40"
        "HP" "40"
        "TEXT" "Goo Upgrade -- Put on one of your Goo monsters. Divide -- When Goo Zoo would be destroyed, if there's a card under it, you may play that card instead."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Grew New Goo -- Search your deck for a Goo, reveal it, and put it into your hand. Then shuffle your deck."
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
        destroyCardUnder(player,mob)
    end

    function onTryPlay(player)
        local mobs, not_empty = makeInfoTableList(player,"Goo")

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

    function onLevelActionTrigger(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local deck = getPlayerDeck(player, "DECK_DECK")
        local hand = getPlayerDeck(player, "DECK_HAND")

        local card_list, qty = getListFromDeck(deck)
        local goo_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","Goo")

        local goo_spawn = menuCards(player,goo_list,"Select a card to spawn.","CARDLIST_PEEK")
        if goo_spawn ~= 0 then
            revealCard(not player,"Opponent has drawn card...",getCARD(goo_spawn))
            moveCards(player,deck,hand,"TAKE_CARDID","PUT_BOTTOM",goo_spawn)
        end

        destroyList(goo_list)
        shuffleDeck(player,"DECK_DECK")
    end

}
