ZTCG_CARD
{

    "NAME" "Mass Respawn"
    "IMAGE" "S5C013_MassRespawn.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "600"

    TYPE_ACT
    {
        "LEVEL" "50"
        "TEXT" "For each Bowman card under your character, you may play a monster of level 30 or less from your discard pile."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Think Fast 50 -- Play a tactic of level 50 or less."
    }

    function onThinkAction(player)
        local n = getPlayerAttributes(player,"ELEM_BOWMAN")

        local grav = getPlayerDeck(player, "DECK_GRAV")
        local hand = getPlayerDeck(player, "DECK_HAND")
        local card_list, qty = getListFromDeck(grav)

        local cards = makeFilteredList(player,card_list,0,0,30,"TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
        for i = 1, n, 1 do
            if isEmptyList(cards) then
                break
            end

            local menuCard = menuCards(player,cards,"Select a card to play.","CARDLIST_PEEK")
            moveCards(player,grav,hand,"TAKE_CARDID","PUT_BOTTOM",menuCard)
            summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")

            cards = takeTargetCardFromList(menuCard,cards)
        end

        destroyList(cards)
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast 50"
        action(player,"ZTCG_NIL","ELEM_ANY",50)
    end

}
