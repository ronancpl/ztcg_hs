ZTCG_CARD
{

    "NAME" "Pack of Boars"
    "IMAGE" "S5C071_PackofBoars.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Boar Upgrade"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "42"
        "ATTCK" "70"
        "HP" "70"
        "TEXT" "Boar Upgrade -- Put on one of your Boar monsters. Scout -- When you play Pack of Boars, reveal the top card of your deck. If it's a monster, put it into your hand. Otherwise put it back."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Boar Scout -- Reveal the top card of your deck. If it's a Boar card, put it into your hand. Otherwise put it back."
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
        local mobs, not_empty = makeInfoTableList(player,"Boar")

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
        scoutMob(player,"SCOUT_NORMAL","ELEM_ANY")
    end

    function onActivateCharacterAction(player)
        local card = peekNextCard(player)
        if card ~= 0 then
            if isInfoCARD(card, "Boar") then
                drawCard(player)
                --revealCard(not player,"Opponent has drawn card...",card)
            end
        end
    end

}
