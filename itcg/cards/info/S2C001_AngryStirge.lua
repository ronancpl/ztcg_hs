ZTCG_CARD
{

    "NAME" "Angry Stirge"
    "IMAGE" "S2C001_AngryStirge.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Flying Bat"
    "COST" "600"

    TYPE_MOB
    {
        "LEVEL" "20"
        "ATTCK" "30"
        "HP" "20"
        "TEXT" "Fearsome -- A monster or character of level 40 or less can't attack Angry Stirge or damage it with character actions."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Snare -- Reveal the top card of your deck. If it's a monster of level 20 or less, play it. Otherwise put it back. "
    }

    function preventTargetMob(player)
        local atkr = getCardPointer(0)
        local level = getCurrentLevelFromCARD(not player,atkr)

        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB | ATKSRC_CHA") and level <= 40 then
            return 1
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local card = peekNextCard(player)
        if card ~= 0 then
            --revealCard(not player,"Next Card...",card)

            local level = getCurrentLevelFromCARD(player,card)
            if hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_ANYMOB") and level <= 20 then
                local deck = getPlayerDeck(player, "DECK_DECK")
                local card_taken = takeCardsFromDeck(player,deck, 1)

                local hand = getPlayerDeck(player, "DECK_HAND")
                card_taken = moveCardsFromListToDeck(player,card_taken,hand,"TAKE_NEXT","PUT_BOTTOM", 1)
                summon(player,"PLAY_SCOUTSUMMON","ELEM_ANY",20)

                destroyList(card_taken)
            end
        end
    end

}
