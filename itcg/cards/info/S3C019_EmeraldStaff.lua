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
        local lvAdvsry = getCurrentLevelFromCARD(player,card2)

        if lvPlayer < lvAdvsry then
            local grav = getPlayerDeck(player, "DECK_GRAV")
            local card_list, qty = getListFromDeck(grav)
            local list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_MAGE","ZTCG_NIL")

            if qty > 0 then
                local card = menuCards(player,list,"Select a card to add into character actions.","CARDLIST_PEEK")
                if card ~= 0 then
                    local hand = getPlayerDeck(player, "DECK_GRAV")

                    list = takeTargetCardFromList(card,list)
                    takeTargetCardFromDeck(card,grav)

                    list = moveCardsFromListToDeck(list,hand,"TAKE_CARDID","PUT_BOTTOM",card)

                    levelUpScout(player)
                end
            end

            destroyList(list)
        end
    end

}
