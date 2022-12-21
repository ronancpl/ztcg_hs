ZTCG_CARD
{

    "NAME" "Power Knock-Back"
    "IMAGE" "S1C018_PowerKnockBack.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Skill"
    "COST" "560"

    TYPE_ACT
    {
        "LEVEL" "40"
        "TEXT" "Put one of your opponent's monsters into his or her deck under the top card."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Tricky Shot -- Do 20 damage to a character or monster. "
    }

    function onThinkAction(player)
        local deck = getPlayerDeck(not player, "DECK_DECK")
        local top_card = takeCardsFromDeck(player,deck, 1)

        local mobs, notEmpty = makeFilteredTableList(player,"ONLY_ADVSRY",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
        if notEmpty then
            local mob = menuCards(player,mobs,"Which mob do you wish to return to your opponent's deck?","CARDLIST_PEEK")
            if mob ~= 0 then
                local slot = getSlotIdFromCARD(not player,getCARD(mob))
                local table_mob = takeCardFromTable(player,"SLOT_ADVSRYMOB" .. slot)

                table_mob = moveCardsFromListToDeck(player,table_mob,deck,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
                top_card = moveCardsFromListToDeck(player,top_card,deck,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")

                destroyList(table_mob)
            end
        end

        destroyList(top_card)
        destroyList(mobs)
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
