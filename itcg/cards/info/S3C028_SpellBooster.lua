ZTCG_CARD
{

    "NAME" "Spell Booster"
    "IMAGE" "S3C028_SpellBooster.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Skill"
    "COST" "740"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "Draw 2 cards. Then put a card from your hand face down on top of your deck."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 40 -- Play a monster or item of level 40 or less."
    }

    function onThinkAction(player)
        drawCard(player)
        drawCard(player)

        local hand = getPlayerDeck(player, "DECK_HAND")
        local card_list, qty = getListFromDeck(hand)
        if qty > 0 then
            local deck = getPlayerDeck(player, "DECK_DECK")

            while true do
                local menuCard = menuCards(player,card_list,"Select a card to put on the top of the deck.","CARDLIST_PEEK")
                if menuCard ~= 0 then
                    local card = takeTargetCardFromDeck(player,menuCard,hand)
                    card = moveCardsFromListToDeck(player,card,deck,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")

                    break
                end
            end
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 40"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 40)
    end

}
