ZTCG_CARD
{

    "NAME" "Mighty Zakum"
    "IMAGE" "S5C082_MightyZakum.png"
    "TYPE" "MOB"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Zakum Boss"
    "COST" "1000"

    TYPE_MOB
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

    function onActivateCharacterAction(player)
        local cards = takeCardsFromDeck(deck, 4)

        local zcards = makeFilteredList(player,cards,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY","Zakum")
        while not isEmptyList(zcards) do
            local menuCard = menuCards(player,zcards,"Select a card to play.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                zcards = takeTargetCardFromList(menuCard,zcards)
                cards = takeTargetCardFromList(menuCard,cards)

                local card = getCARD(menuCard)
                if hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_MOB | TYPE_JRB | TYPE_BOS") then
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

        cards = moveCardsFromListToDeck(cards,deck,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
        destroyList(zcards)
        destroyList(cards)
    end

}
