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
        local target = getTargetCARD()

        local cardid = getCardIdFromCARD(src)
        local n = getCardRegister(src,cardid,0)
        local slotid = getSlotIdFromCARD(player, target)

        editCardRegister(src,cardid,n+1,slotid,0,nil)
        editCardRegister(src,cardid,0,n+1,0,nil)

        attack(player, src, 60, "ATKRES_NIL", "ATKSRC_EQP", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onEndTurn(player)
        local list = makeFilteredTableList(player,"ONLY_PLAYER",0,"DONT_CARE","DONT_CARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")

        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        local n = getCardRegister(src,cardid,0)

        if not isEmptyList(list) then
            while true do
                local card = menuCards(player,list,"Select a card to withdraw.","CARDLIST_PEEK")
                if card ~= 0 then
                    local slotidA = getSlotIdFromCARD(player,getCARD(card))

                    local n = getCardRegister(src,cardid,0)
                    local submit = false
                    for i = 1,n,1 do
                        local slotidB = getCardRegister(src,cardid,i)
                        if slotidA == slotidB then
                            submit = true
                        end
                    end

                    if submit or true then
                        outList = takeCardFromTable(player, "SLOT_PLAYERMOB" .. slotidA)
                        local hand = getPlayerDeck(player, "DECK_HAND")
                        outList = moveCardsFromListToDeck(outList,hand,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

                        break
                    end
                else
                    break
                end
            end
        end
    end

    function onCalcAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(0)
        if(hasSharedFlagsCARD(atkr, "FLAG_TYPE", "TYPE_MOB | TYPE_JRB | TYPE_BOS") and getCardRegister(src, cid, 0) == 10) then
            local dmg = getGameValue(0)
            local bonus = getCardRegister(src, cid, 1)
            updateGameValue(0, dmg + bonus)

            return 1    -- notices bonus from next tactic
        end
    end

    function onExecuteAttack(player)
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
