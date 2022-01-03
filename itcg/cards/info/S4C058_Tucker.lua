ZTCG_CARD
{

    "NAME" "Tucker"
    "IMAGE" "S4C058_Tucker.png"
    "TYPE" "CHAR"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Page"
    "COST" "800"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card."
        }
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "1"
            "TEXT" "Refresh -- You get +10 HP."
        }
        LVL_ACTION
        {
            "LEVEL" "30"
            "ATTRB" "1"
            "TEXT" "NPC Spawn -- Play an NPC of your level or less. It gets +20 HP until your next turn starts."
        }
        "HP" "240"
    }

    function applyBuffs(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local slotid = getCardRegister(src,cardid,0)
        if slotid > 0 then
            local card = getOnBoardCARD(player, "SLOT_PLAYERMOB"  .. tostring(slotid))
            if card ~= 0 then
                newBuff(card,src,0,20,0,1)
            end
        end
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local slotid = getCardRegister(src,cardid,0)
        if slotid > 0 then
            local card = getOnBoardCARD(player, "SLOT_PLAYERMOB"  .. tostring(slotid))
            if card ~= 0 then
                removeBuff(card,src,0,20,0)
            end
        end
    end

    function onStartTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        editCardRegister(src,cardid,0,0,0,nil)
    end

    function onActivateCharacterAction1(player)
        drawCard(player)
    end

    function onActivateCharacterAction2(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,card,10)
    end

    function onActivateCharacterAction3(player)
        local src = getSourceCARD()

        local deckHand = getPlayerDeck(player, "DECK_HAND")
        local card_list = getListFromDeck(deckHand)

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        local npcList, not_empty = makeFilteredList(player,card_list,0,0,level,"TYPE_ANYMOB", "ELEM_ANY", "NPC")
        if not_empty then
            local menuCard = menuCards(player,npcList,"Select a NPC to spawn.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                local card = getCARD(menuCard)

                menuCard = takeTargetCardFromDeck(menuCard,deckHand)
                menuCard = moveCardsFromListToDeck(menuCard,deckHand,"TAKE_CARDID","PUT_BOTTOM",menuCard)
                summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")

                local slotid = getSlotIdFromCARD(player, card)
                card = getOnBoardCARD(player, "SLOT_PLAYERMOB"  .. tostring(slotid))

                local cardid = getCardIdFromCARD(src)
                editCardRegister(src,cardid,0,slotid,0,nil)
                newBuff(card,src,0,20,0,1)

                destroyList(menuCard)
            end
        end
        destroyList(npcList)
    end


}
