ZTCG_CARD
{

    "NAME" "Balrog's Dance"
    "IMAGE" "S4C046_BalrogsDance.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "750"

    TYPE_ACT
    {
        "LEVEL" "35"
        "TEXT" "One of your monsters gets +30 attack this turn. Whenever it damages your opponent's character this turn, destroy one of that opponent's items."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Dances with Balrogs Team Up -- Get +20 HP. If you're level 60 or more, you may play Dances with Balrogs."
    }

    function onCalcAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_TYPE", "TYPE_ANYMOB") and getCardRegister(src, cid, 0) == 10) then
            local dmg = getGameValue(0)
            local bonus = getCardRegister(src, cid, 1)
            updateGameValue(0, dmg + bonus)

            return 1    -- notices bonus from next tactic
        end
    end

    function onExecuteAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_TYPE", "TYPE_ANYMOB") and getCardRegister(src, cid, 0) == 10) then
            editCardRegister(src, cid, 0, 0, 0, nil)

            local def_card = getCardPointer(1)
            if(hasSharedFlagsCARD(def_card, "FLAG_TYPE", "TYPE_CHAR")) then
                destroyEquipment(player)
            end

            return 1    -- finishes bonus from next tactic
        end
    end

    function onThinkAction(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 10, 0, nil)
        editCardRegister(src, cid, 1, 30, 0, nil)

        insertCardNextAction(player)  -- card pointer : next attack
    end

    function onLevelActionTrigger(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,chr,20)

        local level = getCurrentLevelFromCARD(player,chr)

        local deckHand = getPlayerDeck(player, "DECK_HAND")
        local card_list, qty = getListFromDeck(deckHand)

        local list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY","Dances With Balrog")
        if level >= 60 and not_empty then
            local card = menuCards(player,list,"Select a mob to spawn.","CARDLIST_PEEK")
            if card ~= 0 then
                moveCards(player,deckHand,deckHand,"TAKE_CARDID","PUT_BOTTOM",card)
                summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
            end
        end
        destroyList(list)
    end

}
