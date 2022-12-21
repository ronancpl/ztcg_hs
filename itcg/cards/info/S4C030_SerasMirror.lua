ZTCG_CARD
{

    "NAME" "Sera's Mirror"
    "IMAGE" "S4C030_SerasMirror.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Treasure"
    "COST" "750"

    TYPE_EQP
    {
        "LEVEL" "70"
        "TEXT" "Whenever you play a card, you may destroy Sera's Mirror. If you do, search your deck for another card with that card's name and play it. Then shuffle your deck."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Conjure -- Return another Magician card from under your character to your hand."
    }

    function onPlayCard(player)
        local src = getSourceCARD()

        local hand = getPlayerDeck(player,"DECK_HAND")
        local deck = getPlayerDeck(player,"DECK_DECK")

        local card_list = getListFromDeck(deck)

        local card = getTargetCARD()
        local cards, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY",getNameFromCARD(card))
        if not_empty then
            local menuCard = menuCards(player,cards,"Select a card to replace Sera's Mirror.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                moveCards(player,deck,hand,"TAKE_CARDID","PUT_BOTTOM",menuCard)

                local slotid = getSlotIdFromCARD(player, src) - 7
                destroySelf(player,"SLOT_PLAYEREQP" .. slotid)

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

        destroyList(cards)
    end

    function onLevelActionTrigger(player)
        local list, list_sz = getListFromCharacterActions(player, true)
        if list_sz > 0 then
            local mg_list, not_empty = makeFilteredList(player,list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_MAGE","ZTCG_NIL")
            if not_empty then
                while true do
                    local menuCard = menuCards(player,mg_list,"Select a card to draw.","CARDLIST_PEEK")
                    if menuCard ~= 0 then
                        local card = getCARD(menuCard)
                        local src = getSourceCARD()
                        if card ~= src then
                            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
                            local level = getCurrentLevelFromCARD(player,chr)

                            destroyCharacterAction(player,card,true)
                            recoverDestroyedCard(player,card)
                        end

                        break
                    end
                end
            end

            destroyList(mg_list)
        end

        destroyList(list)
    end


}
