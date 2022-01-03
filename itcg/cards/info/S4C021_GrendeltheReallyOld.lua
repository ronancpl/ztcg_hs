ZTCG_CARD
{

    "NAME" "Grendel the Really Old"
    "IMAGE" "S4C021_GrendeltheReallyOld.png"
    "TYPE" "BOSS"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - NPC Boss"
    "COST" "1000"

    TYPE_BOS
    {
        "LEVEL" "80"
        "ATTCK" "30"
        "HP" "120"
        "TEXT" "Research -- Draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "3"
        "TEXT" "Arcane Knowledge -- Play a tactic card from your discard pile. Then put it on the bottom of your deck."
    }

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(not matchRequirements(player, 80, 3, "ELEM_MAGE")) then return end

        local player_grav = getPlayerDeck(player, "DECK_GRAV")
        local player_deck = getPlayerDeck(player, "DECK_DECK")

        local deck_list = getListFromDeck(player_grav)

        local card_list = makeFilteredList(player,deck_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ACT", "ELEM_ANY", "ZTCG_NIL")

        local card = menuCards(player,card_list1,"Select a card to activate.","CARDLIST_PEEK")
        if card ~= 0 then
            action(player,getCARD(card),"ELEM_ANY","ZTCG_DONTCARE")
            moveCards(player_grav,player_deck,"TAKE_CARDID","PUT_BOTTOM",card)
        end

        destroyList(card_list)
    end

    function onActivateCharacterAction(player)
        local player_grav = getPlayerDeck(player, "DECK_GRAV")
        local player_deck = getPlayerDeck(player, "DECK_DECK")

        local deck_list = getListFromDeck(player_grav)

        local card_list = makeFilteredList(player,deck_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ACT", "ELEM_ANY", "ZTCG_NIL")

        local card = menuCards(player,card_list1,"Select a card to activate.","CARDLIST_PEEK")
        if card ~= 0 then
            action(player,getCARD(card),"ELEM_ANY","ZTCG_DONTCARE")
            moveCards(player_grav,player_deck,"TAKE_CARDID","PUT_BOTTOM",card)
        end

        destroyList(card_list)
    end

}
