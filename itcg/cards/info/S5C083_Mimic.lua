ZTCG_CARD
{

    "NAME" "Mimic"
    "IMAGE" "S5C083_Mimic.png"
    "TYPE" "MOB"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Zakum Guardian"
    "COST" "600"

    TYPE_MOB
    {
        "LEVEL" "54"
        "ATTCK" "50"
        "HP" "50"
        "TEXT" "Treasure Hoard -- When Mimic is destroyed, you may reveal an item from your hand. If you do, draw a card. If you don't, your opponent may draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "0"
        "TEXT" "Booby Trap -- Discard an item card from your hand. Do damage equal to that item's level, rounded up to the nearest 10, to a character or monster."
    }

    function onReceiveAttackAndInterceptDestroyed(player)
        local hand = getPlayerDeck(player, "DECK_HAND")
        local list = getListFromDeck(hand)
        local equips, not_empty = makeFilteredList(player,list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP","ELEM_ANY","ZTCG_NIL")

        local revealed = false
        if not_empty then
            local card = menuCards(player,list,"Select a card for reveal.","CARDLIST_PEEK")
            if card ~= 0 then
                revealCard(player,"Has item...",getCARD(card))
                revealed = true
            end
        end

        if not revealed then
            drawCard(not player)
        else
            drawCard(player)
        end

        destroyList(equips)
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")

        local hand = getPlayerDeck(player, "DECK_HAND")
        local list = getListFromDeck(hand)

        local equips, not_empty = makeFilteredList(player,list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP","ELEM_ANY","ZTCG_NIL")
        if not_empty then
            local menuCard = menuCards(player,equips,"Select an equip to destroy for its level in attack.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                local grav = getPlayerDeck(player, "DECK_GRAV")
                moveCards(hand,grav,"TAKE_CARDID","PUT_TOP",menuCard)

                local dmg = getCurrentLevelFromCARD(player, getCARD(menuCard))
                attack(player, chr, dmg, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
            end
        end
    end

}
