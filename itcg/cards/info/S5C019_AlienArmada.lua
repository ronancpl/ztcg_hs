ZTCG_CARD
{

    "NAME" "Alien Armada"
    "IMAGE" "S5C019_AlienArmada.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Alien Upgrade"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "42"
        "ATTCK" "50"
        "HP" "50"
        "TEXT" "Alien Upgrade -- Put on one of your Alien monsters. Collective Genius -- Whenever one of your Aliens attacks, draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Quest -- Draw a card."
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
        local mobs, not_empty = makeInfoTableList(player,"Alien")

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

    function onLaunchAttack(player)
        local atkr = getCardPointer(0)
        if isInfoCARD(atkr, "Alien") then
            drawCard(player)
        end
    end

    function onLevelActionTrigger(player)
        drawCard(player)
    end

}
