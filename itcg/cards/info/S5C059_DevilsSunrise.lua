ZTCG_CARD
{

    "NAME" "Devil's Sunrise"
    "IMAGE" "S5C059_DevilsSunrise.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Zakum Weapon"
    "COST" "730"

    TYPE_EQP
    {
        "LEVEL" "90"
        "TEXT" "Whenever you play a monster from your hand, do 60 damage to a character or monster. When your turn ends, you may return one of your monsters to your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Frontal Assault -- One of your monsters that attacks this turn gets +30 attack until the end of turn."
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        editCardRegister(src,cardid,0,0,0,nil)
    end

    function onPlayMob(player)
        local src = getSourceCARD()
        attack(player, src, 60, "ATKRES_NIL", "ATKSRC_EQP", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onEndTurn(player)
        local list, not_empty = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
        if not_empty then
            local card = menuCards(player,list,"Select a card to withdraw.","CARDLIST_PEEK")
            if card ~= 0 then
                local slotid = getSlotIdFromCARD(player,getCARD(card))

                local outList = takeCardFromTable(player, "SLOT_PLAYERMOB" .. slotid)
                local hand = getPlayerDeck(player, "DECK_HAND")
                outList = moveCardsFromListToDeck(player,outList,hand,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

                destroyList(outList)
            end
        end

        destroyList(list)
    end

    function onCalcNextAttack(player)
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

    function onExecuteNextAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if(getCardRegister(src, cid, 0) == 10) then
            editCardRegister(src, cid, 0, 0, 0, nil)

            return 1    -- finishes bonus from next tactic
        end
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 10, 0, nil)
        editCardRegister(src, cid, 1, 30, 0, nil)

        insertCardNextAction(player)  -- card pointer : next attack
    end

}
