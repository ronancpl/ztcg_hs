ZTCG_CARD
{

    "NAME" "Call of the Wild"
    "IMAGE" "S3C034_CalloftheWild.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Strategy"
    "COST" "730"

    TYPE_ACT
    {
        "LEVEL" "40"
        "TEXT" "If you have a monster, destroy 1 of your opponent's monsters. If you have an item, destroy 1 of your opponent's items."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Loot -- If your opponent has 3 or more cards in hand, he or she chooses one and discards it."
    }

    function onThinkAction(player)
        if getMobsOnTable(player,"ONLY_PLAYER") > 0 then
            local menu = makeFilteredTableList(player, "ONLY_ADVSRY", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
            local menuCard = menuCards(player,menu,"Select one monster to destroy.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                local slotid = getSlotIdFromCARD(not player,getCARD(menuCard))
                destroyCard(player,"SLOT_ADVSRYMOB" .. slotid)
            end
            destroyList(menu)
        end

        if getEquipsOnTable(player,"ONLY_PLAYER") > 0 then
            local menu = makeFilteredTableList(player, "ONLY_ADVSRY", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_EQP", "ELEM_ANY", "ZTCG_NIL")
            local menuCard = menuCards(player,menu,"Select one equipment to destroy.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                local slotid = getSlotIdFromCARD(not player,getCARD(menuCard))
                destroyCard(player,"SLOT_ADVSRYEQP" .. (slotid - 7))
            end
            destroyList(menu)
        end
    end

    function onLevelActionTrigger(player)
        local hand = getPlayerDeck(not player, "DECK_HAND")
        local cards, qty = getListFromDeck(hand)

        if qty >= 3 then
            discardCard(not player)
        end
    end

}
