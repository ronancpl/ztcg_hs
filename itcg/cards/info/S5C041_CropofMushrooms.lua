ZTCG_CARD
{

    "NAME" "Crop of Mushrooms"
    "IMAGE" "S5C041_CropofMushrooms.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Mushroom Upgrade"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "40"
        "ATTCK" "70"
        "HP" "60"
        "TEXT" "Mushroom Upgrade -- Put on one of your Mushroom monsters. Loot -- When you play Crop of Mushrooms, if your opponent has 3 or more cards in hand, he or she chooses one and discards it."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Mushroom Respawn -- Play a Mushroom of your level or less from your discard pile."
    }

    function onThinkMob(player)
        local hand = getPlayerDeck(not player, "DECK_HAND")
        local cards, qty = getListFromDeck(hand)

        if qty >= 3 then
            discardCard(not player)
        end
    end

    function onLevelActionTrigger(player)
        local grav = getPlayerDeck(player, "DECK_GRAV")
        local card_list, qty = getListFromDeck(grav)
        local list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_MAGE","Mushroom")

        if qty > 0 then
            local card = menuCards(player,list,"Select a card to revive.","CARDLIST_PEEK")
            if card ~= 0 then
                local hand = getPlayerDeck(player, "DECK_GRAV")

                list = takeTargetCardFromList(card,list)
                takeTargetCardFromDeck(card,grav)

                list = moveCardsFromListToDeck(list,hand,"TAKE_CARDID","PUT_BOTTOM",card)
                summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
            end
        end

        destroyList(list)
    end

}
