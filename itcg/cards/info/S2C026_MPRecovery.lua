ZTCG_CARD
{

    "NAME" "MP Recovery"
    "IMAGE" "S2C026_MPRecovery.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "450"

    TYPE_ACT
    {
        "LEVEL" "10"
        "TEXT" "Return a tactic card from your discard pile to your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Amaze -- Name a card. Reveal the top card of your deck. If you named that card, put it into your hand and do 40 damage to a character or monster. "
    }

    function onThinkAction(player)
        local deck = getPlayerDeck(player, "DECK_GRAV")
        local card_list, qty = getListFromDeck(deck)
        local new_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ACT","ELEM_ANY","ZTCG_NIL")

        if not_empty then
            local card = menuCards(player,new_list,"Select a tactic to draw.","CARDLIST_PEEK")
            if card ~= 0 then
                recoverDestroyedCard(player,getCARD(card))
            end
        end

        destroyList(new_list)
    end

    function onLevelActionTrigger(player)
        if amaze(player) then
            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            attack(player, chr, 40, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

}
