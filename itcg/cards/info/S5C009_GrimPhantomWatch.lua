ZTCG_CARD
{

    "NAME" "Grim Phantom Watch"
    "IMAGE" "S5C009_GrimPhantomWatch.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Flying Undead Spook"
    "COST" "750"

    TYPE_MOB
    {
        "LEVEL" "99"
        "ATTCK" "80"
        "HP" "80"
        "TEXT" "Clock Tick -- Whenever Grim Phantom Watch attacks, clash with your opponent. If you win, you may play the top card of your deck. (To clash, each player reveals the top card of their deck, then puts it on top or bottom. Whoever reveawled the highest-level card wins.)"
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Clash Time -- Clash with your opponent. If you win, do 40 damage to a character or monster."
    }

    function onExecuteAttack(player)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local list, qty = getListFromDeck(deck)

        if qty > 0 then
            if playClash(player) then
                local card = peekNextCard(player)

                local hand = getPlayerDeck(player, "DECK_HAND")
                local cards_taken = takeCardsFromDeck(deck, 1)

                cards_taken = moveCardsFromListToDeck(cards_taken,hand,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
                destroyList(cards_taken)

                if hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_MOB | TYPE_JRB | TYPE_BOS") then
                    ret = summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_EQP") then
                    ret = equip(player,"PLAY_SCOUTEQUIP", "ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_ACT") then
                    ret = action(player,card, "ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_FLD") then
                    ret = locate(player,"PLAY_FIRSTCARDFIELD", "ELEM_ANY")
                end
            end
        end
    end

    function onLevelActionTrigger(player)
        if playClash(player) then
            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            attack(player, chr, 40, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end
    end

}
