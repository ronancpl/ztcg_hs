ZTCG_CARD
{

    "NAME" "Trapped Chest"
    "IMAGE" "S5C054_TrappedChest.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Chest"
    "COST" "530"

    TYPE_EQP
    {
        "LEVEL" "20"
        "TEXT" "When you play Trapped Chest, name a card. Your opponent can't play cards with that name."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Thief Prowess -- Play a Thief card of your level or less."
    }

    function onOpponentTryPlayVerifyChest(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local target = getTargetCARD()
        local targetCid = getCardIdFromCARD(target)

        local cardid = getCardRegister(src,cid,0)
        if cardid == targetCid then
            updateGameValue(0, 0)
        end
    end

    function onOpponentTryPlayAction(player)
        onOpponentTryPlayVerifyChest(player)
    end

    function onOpponentTryPlayEquipment(player)
        onOpponentTryPlayVerifyChest(player)
    end

    function onOpponentTryPlayField(player)
        onOpponentTryPlayVerifyChest(player)
    end

    function onOpponentTryPlayMob(player)
        onOpponentTryPlayVerifyChest(player)
    end

    function makeListFromOpponentDeck(player,deckName)
        local deck = getPlayerDeck(not player,deckName)
        local card_list = getListFromDeck(deck)

        return makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY","ZTCG_NIL")
    end

    function onThinkEquipment(player)
        local list = makeFilteredTableList(player,"ONLY_ADVSRY",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB | TYPE_EQP | TYPE_ACT | TYPE_FLD","ELEM_ANY","ZTCG_NIL")

        local list1 = makeListFromOpponentDeck(player,"DECK_HAND")
        list = appendLists(list,list1)

        local list2 = makeListFromOpponentDeck(player,"DECK_DECK")
        list = appendLists(list,list2)

        local list3 = makeListFromOpponentDeck(player,"DECK_GRAV")
        list = appendLists(list,list3)

        shuffleList(player,list)

        local card = menuCards(player,list,"Select one to prevent your opponent to play.","CARDLIST_PEEK")
        if card ~= 0 then
            revealCard(not player,"This card has been locked...",getCARD(card))

            local src = getSourceCARD()
            local cid = getCardIdFromCARD(src)

            editCardRegister(src,cid,0,getCardIdFromCARD(getCARD(card)),0,nil)
        end

        destroyList(list3)
        destroyList(list2)
        destroyList(list1)
        destroyList(list)
    end

    function onLevelActionTrigger(player)
        local str = "Thief Prowess"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_THIEF", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", level)
    end

}
