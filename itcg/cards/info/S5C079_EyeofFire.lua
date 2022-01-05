ZTCG_CARD
{

    "NAME" "Eye of Fire"
    "IMAGE" "S5C079_EyeofFire.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Zakum Fire Jewelry"
    "COST" "680"

    TYPE_EQP
    {
        "LEVEL" "60"
        "TEXT" "Whenever you play a monster from your hand, reveal the top card of your deck. If it's a monster, play it. Otherwise, put it on the bottom of your deck."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "0"
        "TEXT" "Equip 60 -- Play an item of level 60 or less."
    }

    function onPlayMob(player)
        if not scoutMob(player,"SCOUT_SUMMON","ELEM_ANY") then
            local deck_list = getPlayerDeck(player, "DECK_DECK")

            local list_cards = takeCardsFromDeck(deck_list, 1)
            list_cards = moveCardsFromListToDeck(list_cards,deck_list,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

            destroyList(list_cards)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Equip 60"
        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY",60)
    end

}
