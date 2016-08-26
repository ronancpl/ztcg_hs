ZTCG_CARD
{
    "NAME" "Bounty Hunter"
    "IMAGE" "bounty_hunter.png"
    "TYPE" "MOB"
    "ELEMENT" "DARK"
    "RARITY" "3"
    "INFO" "Dark - Monster - Trickster"
    "COST" "950"

    TYPE_MOB
    {

        "LEVEL" "42"
        "ATTCK" "10"
        "HP" "30"

        -- TEXT field is optional
        "TEXT" "Contrive - When this card is played, decide whether you will use this effect or not. Select a normal monster from your hand to be put under this card. Toss a coin. If won, Bounty Hunter will gain bonus attack equals to the attack value of the card used. Else, your opponent controls Bounty Hunter (destroyed if there is no slot available)."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Spy - Peek the next card of your deck. Return it back to top or bottom."
    }

    function onActivateCharacterAction(player)
        local deck_list = getPlayerDeck(player, "DECK_DECK")

        -- GENERATES a linked list containing all pertaining cards (1 card on this case, or none if deck is empty)
        local card_taken = takeCardsFromDeck(deck_list, 1)
        local card = getCARD(card_taken)

        if(not isNullCARD(card)) then
            revealCard(player,"Next Card...",card)
            local name = getNameFromCARD(card)

            if(makePrompt(player,"Send card to which edge of the deck?",name,"ZTCG_NIL","ZTCG_NIL","Top","Bottom")) then
                -- send TOP
                card_taken = moveCardsFromListToDeck(card_taken,deck_list,"TAKE_NEXT","PUT_TOP", 1)
            else
                -- send BOTTOM
                card_taken = moveCardsFromListToDeck(card_taken,deck_list,"TAKE_NEXT","PUT_BOTTOM", 1)
            end
        end

        -- although the card has been moved already, the linked list still exists. Call destroyList to free the allocated memory.
        destroyList(card_taken)
    end

    function onThinkMob(player)
        local src = getSourceCARD()     -- it is recommended to always declare src card at the start of a pointcut function

        local deck = getPlayerDeck(player, "DECK_HAND")
        local list = getDataFromDeck(deck)

        -- returns a list with all mobs on the player's hand
        local card_list = makeFilteredList(player,list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_MOB", "ELEM_ANY", "ZTCG_NIL")

        if(not isEmptyList(card_list)) then
            if(makePrompt(player,"Bounty Hunter has been played. Use Contrive?","Use a monster card to receive its attack as bonus.","ZTCG_NIL","ZTCG_NIL","Yes","No")) then
                local chosen = menuCards(player,card_list,"CONTRIVE: Convert mob to bonus attack for Bounty Hunter", "CARDLIST_PEEK")

                if(not isNullCARD(chosen)) then
                    if(throwCoin(player)) then
                        -- won

                        -- at the moment the 'chosen' card gets extracted from the list, a NEW linked list is made
                        chosen = takeTargetCardFromDeck(chosen,deck)

                        -- inate skill of Bounty Hunter: first card under it gives bonus attack based on it's attack attribute
                        chosen = putCardUnder(src, chosen)

                        destroyList(chosen)

                    else
                        -- lost

                        -- if opponent does not have a slot available, Bounty Hunter is destroyed
                        if(nextFreeMobSlot(not player) == -1) then
                            local src_slot = getSlotIdFromCARD(player, src)
                            destroySelf(player,src_slot)
                        else
                            -- dont need to define undoBuffs / applyBuffs because the nature of this effect is to change sides permanently, even if it gets silenced
                            applyBlockAura(src, "AURA_HIJACK", "ZTCG_NIL")
                        end
                    end
                end
            end
        end

        destroyList(card_list)
    end

    function onCalcAttack(player)
        -- inate skill: will add to his attack power the attack value of the FIRST card under him.
        local dmg = getGameValue(0)
        local src = getSourceCARD()

        local card = getCardUnder(src,0)
        local c = getCARD(card)
        local base = getBaseAttackFromCARD(c)

        local buff = base + dmg
        updateGameValue(0, buff)
    end

}
