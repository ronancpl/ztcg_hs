ZTCG_CARD
{

    "NAME" "Blue Mushroom"
    "IMAGE" "S2C002_BlueMushroom.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Mushroom"
    "COST" "570"

    TYPE_MOB
    {
        "LEVEL" "20"
        "ATTCK" "20"
        "HP" "20"
        "TEXT" "Bump -- When you play Blue Mushroom, you may return a monster to its player's hand."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Spawn 30 -- Play a monster of level 30 or less. "
    }

    function onThinkMob(player)
        local list, not_empty = makeFilteredTableList(player, "ANY_PLAYER", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
        if not_empty then
            local menuCard = menuCards(player,list,"Select a monster to withdraw.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                local card = getCARD(menuCard)
                local slotid = getSlotIdFromCARD(player, getCARD(menuCard))

                local p
                local slot
                if slotid < 0 then
                    slotid = getSlotIdFromCARD(not player, card)
                    slot = "SLOT_ADVSRYMOB" .. slotid

                    p = not player
                else
                    slot = "SLOT_PLAYERMOB" .. slotid
                    p = player
                end

                local list2, hasCard
                list2, hasCard = takeCardFromTable(player, slot)

                if hasCard then
                    local deckHand = getPlayerDeck(p, "DECK_HAND")
                    list2 = moveCardsFromListToDeck(list2, deckHand,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
                end

                destroyList(list2)
            end
        end

        destroyList(list)
    end

    function onActivateCharacterAction(player)
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",30)
    end

}
