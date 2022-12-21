ZTCG_CARD
{

    "NAME" "Emerald Staff"
    "IMAGE" "S3C019_EmeraldStaff.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Staff"
    "COST" "790"

    TYPE_EQP
    {
        "LEVEL" "15"
        "TEXT" "Whenever you play a tactic, get +10 HP."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Grudge -- If you're a lower level than your opponent, you may level up with a card from your discard pile."
    }

    function onPlayAction(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,card,10)
    end

    function onLevelActionTrigger(player)
        local card1 = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local lvPlayer = getCurrentLevelFromCARD(player,card1)

        local card2 = getOnBoardCARD(player, "SLOT_ADVSRYCHAR")
        local lvAdvsry = getCurrentLevelFromCARD(not player,card2)

        if lvPlayer < lvAdvsry then
            local grav = getPlayerDeck(player, "DECK_GRAV")
            local card_list, qty = getListFromDeck(grav)
            local list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY","ZTCG_NIL")

            if not_empty then
                local card = menuCards(player,list,"Select a card to add into character actions.","CARDLIST_PEEK")
                if card ~= 0 then
                    local hand = getPlayerDeck(player, "DECK_HAND")

                    card = takeTargetCardFromDeck(player,card,grav)
                    card = moveCardsFromListToDeck(player,card,hand,"TAKE_CARDID","PUT_BOTTOM",card)
                    destroyList(card)

                    levelUpScout(player)
                end
            end

            destroyList(list)
        end
    end

}
