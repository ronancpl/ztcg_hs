ZTCG_CARD
{

    "NAME" "Adobis"
    "IMAGE" "S5C074_Adobis.png"
    "TYPE" "MOB"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Human Zakum NPC"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "40"
        "ATTCK" "20"
        "HP" "40"
        "TEXT" "NPC Quest -- Level up with a Boss card. Reward -- You may play a Boss from your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "0"
        "TEXT" "Collect and Trade -- Reveal and item, a monster, and a tactic card from your hand and put them on the bottom of your deck. If you do, draw 4 cards."
    }

    function onLevelUp(player)
        local card = getTargetCARD()
        if isBossCARD(card) and not isBossOnPlayerTable(player) then
            local hand = getPlayerDeck(player, "DECK_HAND")
            local list = getListFromDeck(hand)

            local clist = makeFilteredList(player, list, 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_BOS", "ELEM_ANY", "ZTCG_NIL")
            if not isEmptyList(clist) then
                local card = menuCards(player,clist,"Select a boss to spawn.","CARDLIST_PEEK")
                if card ~= 0 then
                    local card = takeTargetCardFromDeck(player,card,hand)
                    card = takeTargetCardFromListToDeck(player,hand,card,card,"DECK_BOTTOM")

                    summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
                    destroyList(card)
                end
            end
        end
    end

    function onActivateCharacterAction(player)
        local hand = getPlayerDeck(player, "DECK_HAND")
        local list = getListFromDeck(hand)

        local clist_m = makeFilteredList(player, list, 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
        local clist_e = makeFilteredList(player, list, 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_EQP", "ELEM_ANY", "ZTCG_NIL")
        local clist_t = makeFilteredList(player, list, 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_ACT", "ELEM_ANY", "ZTCG_NIL")

        if not isEmptyList(clist_m) and not isEmptyList(clist_e) and not isEmptyList(clist_t) then
            if makePrompt(player,true,"Use Collect and Trade to draw cards?","Reveal each of monster, item and tactic to draw cards.","ZTCG_NIL","ZTCG_NIL","OK","Cancel") then
                local card_m = menuCards(player,clist_m,"Select one mob.","CARDLIST_PEEK")
                local card_e = menuCards(player,clist_e,"Select one item.","CARDLIST_PEEK")
                local card_t = menuCards(player,clist_t,"Select one tactic.","CARDLIST_PEEK")

                if card_m ~= 0 and card_e ~= 0 and card_t ~= 0 then
                    local deck = getPlayerDeck(player, "DECK_DECK")

                    moveCards(player,hand,deck,"TAKE_CARDID","PUT_BOTTOM",card_m)
                    moveCards(player,hand,deck,"TAKE_CARDID","PUT_BOTTOM",card_e)
                    moveCards(player,hand,deck,"TAKE_CARDID","PUT_BOTTOM",card_t)

                    for i = 1, 4, 1 do
                        drawCard(player)
                    end
                end
            end
        end

        destroyList(clist_t)
        destroyList(clist_e)
        destroyList(clist_m)
    end

}
