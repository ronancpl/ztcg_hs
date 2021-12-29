ZTCG_CARD
{

    "NAME" "Manon"
    "IMAGE" "S2C054_Manon.png"
    "TYPE" "BOSS"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Boss"
    "COST" "810"

    TYPE_BOS
    {
        "HP" "160"
        "ATTCK" "60"
        "LEVEL" "105"
        LVL_ACTION
        {
            "LEVEL" "70"
            "ATTRB" "2"
            "TEXT" "Minion Attack -- Reveal the top 2 cards of your deck. Play any monsters revealed this way and discard any others. Destroy monsters played this way at end of turn."
        }
    }

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(not matchRequirements(player, 70, 2, "ELEM_WARRIOR")) then return end

        local deck_list = getPlayerDeck(player, "DECK_DECK")
        local deck_hand = getPlayerDeck(player, "DECK_HAND")
        local deck_grav = getPlayerDeck(player, "DECK_GRAV")
        local cards = takeCardsFromDeck(deck_list, 2)

        local i = 0

        local list = makeFilteredList(player,cards,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
        while not isEmptyList(list) do
            local card = menuCards(player,list,"Select a card to play.","CARDLIST_PEEK")
            if card ~= 0 then
                local cardp = getCARD(card)
                cards = takeTargetCardFromList(card,cards)

                list = moveCardsFromListToDeck(list,deck_hand,"TAKE_CARDID","PUT_BOTTOM",card)
                summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")

                local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
                local cardid = getCardIdFromCARD(chr)
                local slotid = getSlotIdFromCARD(player,cardp)

                editCardRegister(chr, cardid, i,slotid,0,0)
                i = i + 1
            else
                break
            end
        end

        cards = moveCardsFromListToDeck(cards,deck_grav,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")

        destroyList(cards)
        destroyList(list)
    end

    function onStartTurn(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local cardid = getCardIdFromCARD(chr)

        editCardRegister(chr,cardid,0,0,0,0)
        editCardRegister(chr,cardid,1,0,0,0)
    end

    function onEndTurn(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local cardid = getCardIdFromCARD(chr)

        local slotid
        slotid = getCardRegister(chr, cardid, 0)
        if slotid > 0 then
            editCardRegister(chr,cardid,0,0,0,0)
            destroySelf(player,"SLOT_PLAYERMOB" .. slotid)
        end

        slotid = getCardRegister(chr, cardid, 1)
        if slotid > 0 then
            editCardRegister(chr,cardid,1,0,0,0)
            destroySelf(player,"SLOT_PLAYERMOB" .. slotid)
        end
    end

}
