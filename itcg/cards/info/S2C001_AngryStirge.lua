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
        local level = getCurrentLevelFromCARD(player,atkr)

        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB | ATKSRC_CHA") and level <= 40 then
            return 1
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local deck_list = getPlayerDeck(player, "DECK_DECK")
        local card_taken = takeCardsFromDeck(deck_list, 1)
        local card = getCARD(card_taken)

        revealCard(player,"Next Card...",card)

        local level = getCurrentLevelFromCARD(player,atkr)
        if hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_MOB | TYPE_JRB | TYPE_BOS") and level <= 20 then
            local hand_list = getPlayerDeck(player, "DECK_HAND")
            card_taken = moveCardsFromListToDeck(card_taken,hand_list,"TAKE_NEXT","PUT_TOP", 1)
            summon(player,"PLAY_FORCESUMMON","ELEM_ANY",20)
        else
            -- send TOP
            card_taken = moveCardsFromListToDeck(card_taken,deck_list,"TAKE_NEXT","PUT_TOP", 1)
        end

        destroyList(card_taken)
    end

}
