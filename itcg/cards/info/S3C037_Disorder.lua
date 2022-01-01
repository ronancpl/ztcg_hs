ZTCG_CARD
{

    "NAME" "Disorder"
    "IMAGE" "S3C037_Disorder.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Skill"
    "COST" "760"

    TYPE_ACT
    {
        "LEVEL" "35"
        "TEXT" "Destroy up to 2 monsters that have attack 30 or less."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Pilfer -- Return an item card from your discard pile to your hand."
    }

    function onThinkAction(player)
        local mob_list = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")

        for i = 1, 7, 1 do
            local board_card = getOnBoardCARD(player,"SLOT_ADVSRYMOB" .. tostring(i))
            if board_card ~= 0 then
                if getBaseAttackFromCARD(board_card) > 30 then
                    local card = makeTargetFromCARD(board_card)
                    mob_list, not_null = takeTargetCardFromList(card,mob_list)
                end
            end
        end

        local i = 0
        while i < 2 do
            local menuCard = menuCards(player,mob_list,"Select a monster to destroy.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                mob_list = takeTargetCardFromList(menuCard,mob_list)

                local slotid = getSlotIdFromCARD(player,getCARD(menuCard))
                destroySelf(player,"SLOT_ADVSRYMOB" .. slotid)
            else
                break
            end

            i = i + 1
        end

        destroyList(mob_list)
    end

    function onLevelActionTrigger(player)
        local deck = getPlayerDeck(player, "DECK_GRAV")
        local card_list, qty = getListFromDeck(deck)
        local new_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP","ELEM_ANY","ZTCG_NIL")

        if not_empty then
            local card = menuCards(player,new_list,"Select an equipment to draw.","CARDLIST_PEEK")
            if card ~= 0 then
                recoverDestroyedCard(player,getCARD(card))
            end
        end

        destroyList(new_list)
    end

}
