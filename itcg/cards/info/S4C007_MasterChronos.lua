ZTCG_CARD
{

    "NAME" "Master Chronos"
    "IMAGE" "S4C007_MasterChronos.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Flying Undead Spook"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "46"
        "ATTCK" "30"
        "HP" "40"
        "TEXT" "Possess -- When you play Master Chronos, choose one of your opponent's monsters. That monster does damage equal to its attack to itself."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Revive Spook -- Return a Spook from your discard pile to your hand."
    }

    function onThinkMob(player)
        local list, not_empty = makeFilteredTableList(player,"ONLY_ADVSRY",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
        if not_empty then
            local menuCard = menuCards(player,list,"Select a mob to attack itself.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                local card = getCARD(menuCard)
                local slotid = getSlotIdFromCARD(not player, card)
                local dmg = getBaseAttackFromCARD(card)

                attack(player, card, dmg, "ATKRES_FIXED_SLOT", "ATKSRC_MOB", "SLOT_ADVSRYMOB" .. tostring(slotid), "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
            end
        end
        destroyList(list)
    end

    function onLevelActionTrigger(player)
        local deckHand = getPlayerDeck(player, "DECK_HAND")

        local deckGrav = getPlayerDeck(player, "DECK_GRAV")
        local deck_list = getListFromDeck(deckGrav)

        local menu, not_empty = makeFilteredList(player,deck_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Spook")
        if not_empty then
            local menuCard = menuCards(player,menu,"Select a mob to revive.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                local card = getCARD(menuCard)

                recoverDestroyedCard(player,card)
            end
        end
        destroyList(menu)
    end

}
