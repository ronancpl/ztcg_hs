ZTCG_CARD
{

    "NAME" "Masterful Knock-Back"
    "IMAGE" "S2C012_MasterfulKnockBack.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "560"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "Return a monster to its player's hand. Monsters with that name can't be played next turn."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "2"
        "TEXT" "Spawn 120 -- Play a monster of level 120 or less. "
    }

    function onOpponentTryPlayMob(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local target = getTargetCARD()
        local targetCid = getCardIdFromCARD(target)

        local cardid = getCardRegister(src,cid,0)
        if cardid == targetCid then
            updateGameValue(0, 0)
        end
    end

    function onThinkAction(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        insertCardTurnAction(player)

        local clist = makeFilteredTableList(player, "ONLY_ADVSRY", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
        local card = menuCards(player,clist,"Select a card to withdraw from the table.","CARDLIST_PEEK")
        if card ~= 0 then
            local cardid = getCardIdFromCARD(getCARD(card))
            editCardRegister(src, cid, 0, cardid, 0, null)

            local slot = getSlotIdFromCARD(not player, getCARD(card))

            local list, hasCard
            list, hasCard = takeCardFromTable(player, "SLOT_ADVSRYMOB" .. slot)

            if hasCard then
                local deckHand = getPlayerDeck(not player, "DECK_HAND")
                list = moveCardsFromListToDeck(player,list, deckHand,"TAKE_CARDID","PUT_BOTTOM",card)
            end
            destroyList(list)
        end
        destroyList(clist)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 120"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",120)
    end

}
