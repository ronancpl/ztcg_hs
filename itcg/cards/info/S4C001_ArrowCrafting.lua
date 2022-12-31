ZTCG_CARD
{

    "NAME" "Arrow Crafting"
    "IMAGE" "S4C001_ArrowCrafting.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "800"

    TYPE_ACT
    {
        "LEVEL" "60"
        "TEXT" "Reveal the top card of your deck. Do damage to a character or monster equal to that card's level rounded up to the nearest 10. Then put the card back."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "2"
        "TEXT" "Improvise -- Discard a card from your hand. Then do 30 damage to a character or monster."
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        local card = peekNextCard(player)
        if card ~= 0 then
            --revealCard(not player,"Next card...",card)

            local dmg = getRoundedNearest(getCurrentLevelFromCARD(player, card))
            attack(player,src,dmg,"ATKRES_NIL", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

    function onActivateCharacterAction(player)
        local deckHand = getPlayerDeck(player, "DECK_HAND")
        local card_list, qty = getListFromDeck(deckHand)
        if qty <= 0 then return end

        if(not makePrompt(player,true,"Use Improvise?","Discard a card. Do 30 damage to a character or monster.","ZTCG_NIL","ZTCG_NIL","OK","Cancel")) then return end
        discardCard(player)

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player,chr,30,"ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
