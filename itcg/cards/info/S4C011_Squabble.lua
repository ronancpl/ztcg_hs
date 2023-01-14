ZTCG_CARD
{

    "NAME" "Squabble"
    "IMAGE" "S4C011_Squabble.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Strategy"
    "COST" "630"

    TYPE_ACT
    {
        "LEVEL" "40"
        "TEXT" "Choose 2 monsters. Each does damage equal to its attack to the other."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn / Think Fast 60 -- Play a monster or tactic of level 60 or less."
    }

    function onThinkAction(player)
        if getMobsOnTable(player,"ONLY_ADVSRY") >= 1 and getMobsOnTable(player,"ANY_PLAYER") >= 2 then
            local opposingMobs = makeFilteredTableList(player,"ONLY_ADVSRY",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
            local mobs = makeFilteredTableList(player,"ANY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")

            local cardA = menuCards(player,opposingMobs,"Select an opposing mob.","CARDLIST_PEEK")
            if cardA ~= 0 then
                mobs = takeTargetCardFromList(cardA,mobs)
                local cardB = menuCards(player,mobs,"Select a mob to squabble.","CARDLIST_PEEK")
                if cardB ~= 0 then
                    local slotStrA
                    local slotA = getSlotIdFromCARD(player,getCARD(cardA))
                    if slotA < 0 then
                        slotA = getSlotIdFromCARD(not player,getCARD(cardA))
                        slotStrA = "SLOT_ADVSRYMOB" .. tostring(slotA)
                    else
                        slotStrA = "SLOT_PLAYERMOB" .. tostring(slotA)
                    end

                    local slotStrB
                    local slotB = getSlotIdFromCARD(player,getCARD(cardB))
                    if slotB < 0 then
                        slotB = getSlotIdFromCARD(not player,getCARD(cardB))
                        slotStrB = "SLOT_ADVSRYMOB" .. tostring(slotB)
                    else
                        slotStrB = "SLOT_PLAYERMOB" .. tostring(slotB)
                    end

                    local atkA = getBaseAttackFromCARD(getCARD(cardA))
                    local atkB = getBaseAttackFromCARD(getCARD(cardB))

                    attack(player, getCARD(cardB), atkB, "ATKRES_FIXED_SLOT_DAMAGE", "ATKSRC_NIL", slotStrA, "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_COUNTER")
                    attack(player, getCARD(cardA), atkA, "ATKRES_FIXED_SLOT_DAMAGE", "ATKSRC_NIL", slotStrB, "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_COUNTER")
                end
            end

            destroyList(mobs)
            destroyList(opposingMobs)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 60"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 60)
    end


}
