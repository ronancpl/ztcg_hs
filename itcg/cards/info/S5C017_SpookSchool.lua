ZTCG_CARD
{

    "NAME" "Spook School"
    "IMAGE" "S5C017_SpookSchool.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Flying Spook Upgrade"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "52"
        "ATTCK" "100"
        "HP" "100"
        "TEXT" "Spook Upgrade -- Put on one of your Spook monsters."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Return of the Spook -- Play a Spook from your discard pile. When your turn ends, put it on the bottom of your deck."
    }

    function makeInfoTableList(player,info)
        return makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY",info)
    end

    function destroyCardUnder(player,mob)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local grav = getPlayerDeck(player, "DECK_GRAV")

        local mob_target = makeTargetFromCARD(mob)
        moveCards(player,deck,grav,"TAKE_CARDID","PUT_TOP",mob_target)
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
        local mobs, not_empty = makeInfoTableList(player,"Spook")

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

    function onEndTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local deck = getPlayerDeck(player, "DECK_DECK")
        local n = getCardRegister(src,cardid,0)
        for i = 1, n, 1 do
            local slotid = getCardRegister(src,cardid,i)
            if slotid ~= 0 then
                local spook = takeCardFromTable(player,"SLOT_PLAYERMOB" .. tostring(slotid))
                if spook ~= 0 then
                    spook = moveCardsFromListToDeck(player,spook,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
                    destroyList(spook)
                end
            end
        end

        editCardRegister(src,cardid,0,0,0,nil)
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        insertCardTurnAction(player)

        local hand = getPlayerDeck(player, "DECK_HAND")
        local grav = getPlayerDeck(player, "DECK_GRAV")

        local card_list, qty = getListFromDeck(grav)
        local spook_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","Spook")

        local spook_spawn = menuCards(player,spook_list,"Select a card to spawn.","CARDLIST_PEEK")
        if spook_spawn ~= 0 then
            local spook_target = spook_spawn
            local spook_card = getCARD(spook_spawn)

            spook_spawn = takeTargetCardFromDeck(player,spook_spawn,grav)
            spook_spawn = takeTargetCardFromListToDeck(player,hand,spook_spawn,spook_spawn,"DECK_BOTTOM")
            if summon(player,"PLAY_SCOUTSUMMON","ELEM_ANY","ZTCG_MAXVALUE") then
                local n = getCardRegister(src,cardid,0) + 1
                editCardRegister(src,cardid,0,n,0,nil)

                local slotid = getSlotIdFromCARD(player,spook_card)
                editCardRegister(src,cardid,n,slotid,0,nil)
            else
                local deck = getPlayerDeck(player, "DECK_DECK")
                moveCards(player,hand,deck,"TAKE_CARDID","PUT_BOTTOM",spook_target)
            end

            destroyList(spook_spawn)
        end

        destroyList(spook_list)
    end

}
