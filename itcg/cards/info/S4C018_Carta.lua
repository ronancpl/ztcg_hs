ZTCG_CARD
{

    "NAME" "Carta"
    "IMAGE" "S4C018_Carta.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Human NPC"
    "COST" "760"

    TYPE_MOB
    {
        "LEVEL" "70"
        "ATTCK" "60"
        "HP" "60"
        "TEXT" "NPC Quest -- Damage your opponent's character. Reward -- Look at the top card of your deck. Put it back on the top or bottom of your deck."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Amaze -- Name a card. Reveal the top card of your deck. If you named that card, put it into your hand and do 40 damage to a character or monster."
    }

    function onExecuteAttackAndSurvived(player)
        local def_card = getTargetCARD()
        if(hasSharedFlagsCARD(def_card, "FLAG_TYPE", "TYPE_CHAR") and getGameValue(0) > 0) then
            local card = peekNextCard(player)

            local deck_list = getPlayerDeck(player, "DECK_DECK")
            local list_cards = takeCardsFromDeck(deck_list, 1)

            if(makePrompt(player,"Draw " .. getNameFromCARD(card) .. "?","Or insert it on the bottom of the deck?","ZTCG_NIL","ZTCG_NIL","Top","Bottom")) then
                list_cards = moveCardsFromListToDeck(list_cards,deck_list,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
            else
                list_cards = moveCardsFromListToDeck(list_cards,deck_list,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            end

            destroyList(list_cards)
        end
    end

    function onLevelActionTrigger(player)
        if amaze(player) then
            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            attack(player, chr, 40, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end
    end

}
