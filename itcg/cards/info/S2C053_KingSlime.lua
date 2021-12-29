ZTCG_CARD
{

    "NAME" "King Slime"
    "IMAGE" "S2C053_KingSlime.png"
    "TYPE" "BOSS"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Boss"
    "COST" "740"

    TYPE_BOS
    {
        "HP" "60"
        "ATTCK" "20"
        "LEVEL" "40"
        LVL_ACTION
        {
            "LEVEL" "0"
            "ATTRB" "0"
            "TEXT" "Split-- When King Slime is destroyed, you may search your deck for a Goo monster and play it. Then shuffle your deck."
        }
        LVL_ACTION
        {
            "LEVEL" "40"
            "ATTRB" "1"
            "TEXT" "Shock Wave -- King Slime does 10 damage to each of your opponent's monsters. Then King Slime does 10 damage to your opponent's character. "
        }
    }

    function onAttackMobDestroyed(player)
        local target = getTargetCARD()
        if(hasSharedFlagsCARD(target, "FLAG_TYPE", "TYPE_BOS")) then
            local deck = getPlayerDeck(player, "DECK_DECK")
            local card_list, qty = getListFromDeck(deck)

            if qty > 0 then
                local cards, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","Goo")
                if not_empty then
                    local card = menuCards(player,cards,"Select a card to draw.","CARDLIST_PEEK")
                    if card ~= 0 then
                        local hand = getPlayerDeck(player, "DECK_HAND")
                        cards = moveCardsFromListToDeck(cards,hand,"TAKE_CARDID","PUT_BOTTOM",card)
                        summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
                    end
                end

                destroyList(cards)
            end

            shuffleDeck(deck)
        end
    end

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(not matchRequirements(player, 40, 2, "ELEM_WARRIOR")) then return end

        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_MOB", "SLOT_ADVSRYMOB1", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_MOB", "SLOT_ADVSRYMOB2", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_MOB", "SLOT_ADVSRYMOB3", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_MOB", "SLOT_ADVSRYMOB4", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_MOB", "SLOT_ADVSRYMOB5", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_MOB", "SLOT_ADVSRYMOB6", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_MOB", "SLOT_ADVSRYMOB7", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10, "ATKRES_FIXED_SLOT", "ATKSRC_MOB", "SLOT_ADVSRYCHAR", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
