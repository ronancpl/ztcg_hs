ZTCG_CARD
{

    "NAME" "Mighty Zakum"
    "IMAGE" "S5C082_MightyZakum.png"
    "TYPE" "BOSS"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Zakum Boss"
    "COST" "1000"

    TYPE_BOS
    {
        "LEVEL" "140"
        "ATTCK" "60"
        "HP" "210"
        "TEXT" "Zummon -- You may play Mighty Zakum as if it were 10 levels less for each Zakum card you have in play and in your discard pile."
    }

    LVL_ACTION
    {
        "LEVEL" "100"
        "ATTRB" "0"
        "TEXT" "Zupreme Power -- Reveal the top 4 cards of your deck. Play each Zakum card from among them and put the others on the bottom of your deck in any order."
    }

    function recalcZakumCardLevelDrop(player)
        local deck_grav = getPlayerDeck(player, "DECK_GRAV")
        local card_list, qty = getListFromDeck(deck_grav)

        local cards = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY","Zakum")
        local qty_g = getListLength(cards)

        local clist = makeFilteredTableList(player, "ONLY_PLAYER", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_ANY", "ELEM_ANY", "Zakum")
        local qty_f = getListLength(clist)

        destroyList(clist)
        destroyList(cards)

        return (qty_g + qty_f) * 10
    end

    function onReactivateCardLevelDrop(player)
        local src = getSourceCARD()
        newCardLevelDrop(src,src,recalcZakumCardLevelDrop(player),1)
    end

    function onPutIntoHand(player)
        local src = getSourceCARD()
        newCardLevelDrop(src,src,recalcZakumCardLevelDrop(player),1)
    end

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(not matchRequirements(player, 100, 0, "ELEM_WARRIOR")) then return end

        local hand = getPlayerDeck(player,"DECK_HAND")
        local deck = getPlayerDeck(player,"DECK_DECK")
        local cards = takeCardsFromDeck(player,deck, 4)

        local zcards = makeFilteredList(player,cards,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY","Zakum")
        while not isEmptyList(zcards) do
            local menuCard = menuCards(player,zcards,"Select a card to play.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                zcards = takeTargetCardFromList(menuCard,zcards)
                cards = moveCardsFromListToDeck(player,cards,hand,"TAKE_CARDID","PUT_BOTTOM",menuCard)

                local card = getCARD(menuCard)
                if hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_ANYMOB") then
                    ret = summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_EQP") then
                    ret = equip(player,"PLAY_SCOUTEQUIP", "ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_ACT") then
                    ret = action(player,card, "ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_FLD") then
                    ret = locate(player,"PLAY_FIRSTCARDFIELD", "ELEM_ANY")
                end
            end
        end

        pickCardOrder(player,cards)

        cards = moveCardsFromListToDeck(player,cards,deck,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
        destroyList(zcards)
        destroyList(cards)
    end

}
