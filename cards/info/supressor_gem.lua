ZTCG_CARD
{
    "NAME" "Supressor Gem"
    "IMAGE" "supressor_gem.png"
    "TYPE" "EQUIP"
    "ELEMENT" "WATER"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Water - Equipment - Device" -- subtypes: Water, Equipment, Device
    "COST" "1320"                       -- subtypes are CASE SENSITIVE.

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Summon / Locate 60 - Play a monster of level 60 or less or a field card."
    }

    TYPE_EQP
    {
        "TEXT" "Pick an opposing monster. It will remain silenced, while the monster or this card stands on the field. At the start of your turn, if the targeted monster has been removed from the table by any means, choose another target (if there is any)."
        "LEVEL" "50"
    }

    function onActivateCharacterAction(player)
        -- copypaste here the text which defines the card lvaction
        local str = "Summon / Locate 60"
        playCard(player, str, "PLAY_MOB | PLAY_FIELD", 60)
    end

    -- CARD REGISTER:
    -- 0 <- Mob slot targeted

    function onInitEquipment(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        editCardRegister(src, cardid, 0, -1, 0, null)    -- informs the card does not have a target yet
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local slot = getCardRegister(src, cardid, 0)
        local affected_mob = getOnBoardCARD(not player, slot)  -- the affected mob card

        print("AFFECTED_MOB: ", slot)
        print("NAME is ", getNameFromCARD(affected_mob))

        removeBlockAura(affected_mob, "AURA_SILENCE", src);
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local slot = getCardRegister(src, cardid, 0)
        local affected_mob = getOnBoardCARD(not player, slot)  -- the affected mob card

        print("RE AFFECTED_MOB: ", slot)
        print("RE NAME is ", getNameFromCARD(affected_mob))

        applyBlockAura(affected_mob, "AURA_SILENCE", src);
    end

    function onThinkEquipment(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        editCardRegister(src, cardid, 0, -1, 0, null)  -- init value: -1 (card does not have a target yet)

        local clist = makeFilteredTableList(player, "ONLY_ADVSRY", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
        local chosen = menuCards(player,clist, "SUPRESSOR GEM: Select a card to apply silence.", "CARDLIST_PEEK")
        local target = getCARD(chosen)

        if(not isNullCARD(target)) then
            if(not hasBlockAura(target, "AURA_SILENCE", src)) then
                applyBlockAura(target, "AURA_SILENCE", src)

                local val = getSlotIdFromCARD(not player, target)   -- saving the slot this equipment is targeting
                print("TARGET SGEM:", val)

                local cardid = getCardIdFromCARD(src)
                editCardRegister(src, cardid, 0, val, 0, null)
            end
        end

        destroyList(clist)

    end

    function onDestroy(player)  -- this card has been destroyed, remove the block from the target
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local slot = getCardRegister(src, cardid, 0)
        local affected_mob = getOnBoardCARD(not player, slot)  -- the affected mob card

        removeBlockAura(affected_mob, "AURA_SILENCE", src);
    end

    function onOpponentCardDestroyed(player)
        local target = getTargetCARD()

        local src = getSourceCARD()
        local id = getCardIdFromCARD(src)
        local slot = getCardRegister(src, id, 0)

        local affected_mob = getOnBoardCARD(not player, slot)  -- the affected mob card

        -- print("src: ",getNameFromCARD(affected_mob))
        -- print("tgt: ",getNameFromCARD(target))
        -- print("match", isSameCARD(target, affected_mob))

        if(isSameCARD(target, affected_mob)) then
            removeBlockAura(affected_mob, "AURA_SILENCE", src);
            editCardRegister(src, id, 0, -1, 0, null)  -- target has been destroyed, ready to affect another
        end
    end

    function onStartTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        if(getCardRegister(src, cardid, 0) == -1) then
            local clist = makeFilteredTableList(player, "ONLY_ADVSRY", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
            local chosen = menuCards(player,clist, "SUPRESSOR GEM: Select a card to apply silence.", "CARDLIST_PEEK")
            local target = getCARD(chosen)

            if(not isNullCARD(target)) then
                if(not hasBlockAura(target, "AURA_SILENCE", src)) then
                    applyBlockAura(target, "AURA_SILENCE", src)

                    local val = getSlotIdFromCARD(not player, target)   -- saving the slot this equipment is targeting
                    editCardRegister(src, cardid, 0, val, 0, null)
                end
            end

            destroyList(clist)
        end
    end
}
