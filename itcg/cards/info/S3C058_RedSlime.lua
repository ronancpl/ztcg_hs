ZTCG_CARD
{

    "NAME" "Red Slime"
    "IMAGE" "S3C058_RedSlime.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Goo"
    "COST" "750"

    TYPE_MOB
    {
        "LEVEL" "55"
        "ATTCK" "60"
        "HP" "70"
        "TEXT" "Splatter -- When you play Red Slime, flip a coin. If you lose, return it to your hand, and you can't play another Red Slime this turn."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "2"
        "TEXT" "Misplace -- Destroy this card. Then destroy an item."
    }

    function resetRegisters()
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src,cid,0,0,0,nil)
    end

    function onStartTurnViewHand(player)
        resetRegisters()
    end

    function onStartTurnViewDeck(player)
        resetRegisters()
    end

    function onStartTurnViewGraveyard(player)
        resetRegisters()
    end

    function onTryPlay(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local val = getCardRegister(src,cid,0)
        if val ~= 0 then
            updateGameValue(0, 0)
        end
    end

    function onThinkMob(player)
        local src = getSourceCARD()
        if not throwCoin(player) then
            local cid = getCardIdFromCARD(src)
            editCardRegister(src, cid, 0, 1, 0, nil)

            local slot = getSlotIdFromCARD(player, src)

            local list, hasCard
            list, hasCard = takeCardFromTable(player, "SLOT_PLAYERMOB" .. tostring(slot))

            if hasCard then
                local deckHand = getPlayerDeck(player, "DECK_HAND")
                list = moveCardsFromListToDeck(player,list, deckHand,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            end

            destroyList(list)
        end
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()

        if getEquipsOnTable(player,"ONLY_ADVSRY") == 0 then return end
        if(not makePrompt(player,true,"Use Misplace?","Destroy this character action, then destroy an equipment.","ZTCG_NIL","ZTCG_NIL","OK","Cancel")) then return end

        destroyCharacterAction(player,src,true)
        destroyEquipment(player)
    end

}
