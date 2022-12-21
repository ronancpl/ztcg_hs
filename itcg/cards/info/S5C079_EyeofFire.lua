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

    function onStartTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 10, 0, nil)
    end

    function onThinkEquipment(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 10, 0, nil)
    end

    function onPlayCard(player) -- after playing mob
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 10, 0, nil)
    end

    function onPlayMob(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if getCardRegister(src, cid, 0) > 0 then
            editCardRegister(src, cid, 0, 0, 0, nil)

            if not scoutMob(player,"SCOUT_SUMMON","ELEM_ANY") then
                local deck = getPlayerDeck(player, "DECK_DECK")
                local deck_list = getListFromDeck(deck)

                if(hasSharedFlagsCARD(getCARD(deck_list), "FLAG_TYPE", "TYPE_ANYMOB")) then
                    local list_cards = takeCardsFromDeck(player,deck, 1)
                    list_cards = moveCardsFromListToDeck(player,list_cards,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
                    summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")

                    destroyList(list_cards)
                end
            end
        end
    end

    function onActivateCharacterAction(player)
        local str = "Equip 60"
        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY",60)
    end

}
