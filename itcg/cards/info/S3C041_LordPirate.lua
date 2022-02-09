ZTCG_CARD
{

    "NAME" "Lord Pirate"
    "IMAGE" "S3C041_LordPirate.png"
    "TYPE" "BOSS"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Boss"
    "COST" "790"

    TYPE_BOS
    {
        "HP" "120"
        "ATTCK" "30"
        "LEVEL" "70"
        LVL_ACTION
        {
            "LEVEL" "70"
            "ATTRB" "2"
            "TEXT" "Hook -- Lord Pirate does 30 damage to a character or monster."
        }
        LVL_ACTION
        {
            "LEVEL" "80"
            "ATTRB" "3"
            "TEXT" "Kidnap -- Remove one of your opponent's monsters or items from the game. When Lord Pirate is destroyed, return that card to its player's hand."
        }
    }

    function effect_h(player,src)
        if(not matchRequirements(player, 70, 2, "ELEM_THIEF")) then return end

        attack(player, src, 30, "ATKRES_NIL", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function effect_k(player,src)
        if(not matchRequirements(player, 80, 3, "ELEM_THIEF")) then return end

        local menu = makeFilteredTableList(player, "ONLY_ADVSRY", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_EQP | TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
        local menuCard = menuCards(player,menu,"Select a card to take from table.","CARDLIST_PEEK")
        if menuCard ~= 0 then
            local card = getCARD(menuCard)
            applyBlockAura(card,"AURA_AWAY", src)

            local cardid = getCardIdFromCARD(src)
            local menuCardid = getCardIdFromCARD(card)

            local n = (getCardRegister(src, cardid, 0) or 0) + 1
            editCardRegister(src,cardid,0,n,0,nil)

            local slotid = getSlotIdFromCARD(not player, card)
            editCardRegister(src,cardid,n,14*menuCardid + (slotid - 1),0,nil)
        end

        destroyList(menu)
    end

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end

        local src = getSourceCARD()
        effect_h(player,src)
        effect_k(player,src)
    end

    function onReceiveAttackAndInterceptDestroyed(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local n = getCardRegister(src, cardid, 0)
        for i = 1, n, 1 do
            local reg = getCardRegister(src, cardid, i)
            local cardid = math.floor(reg / 14)
            local slotid = (reg % 14) + 1

            local strSlot
            if slotid >= 8 then
                strSlot = "SLOT_ADVSRYEQP" .. tostring(slotid - 7)
            else
                strSlot = "SLOT_ADVSRYMOB" .. tostring(slotid)
            end

            local card = getOnBoardCARD(player, strSlot)
            if card ~= 0 and getCardIdFromCARD(card) == cardid then
                removeBlockAura(card, "AURA_AWAY", src)

                local list2, hasCard
                list2, hasCard = takeCardFromTable(player, strSlot)

                if hasCard then
                    local deckHand = getPlayerDeck(not player, "DECK_HAND")
                    list2 = moveCardsFromListToDeck(list2, deckHand,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
                end

                destroyList(list2)
            end
        end
    end

}
