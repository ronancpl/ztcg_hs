ZTCG_CARD
{

    "NAME" "Spook School"
    "IMAGE" "S5C017_SpookSchool.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Flying Spook Upgrade"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "52"
        "ATTCK" "100"
        "HP" "100"
        "TEXT" "Spook Upgrade -- Put on one of your Spook monsters."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Return of the Spook -- Play a Spook from your discard pile. When your turn ends, put it on the bottom of your deck."
    }

    function onEndTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local slotid = getCardRegister(src,cardid,0)
        if slotid ~= 0 then
            local spook = takeCardFromTable(player,"SLOT_PLAYERMOB" .. tostring(slotid))
            if spook ~= 0 then
                local deck = getPlayerDeck(player, "DECK_DECK")
                spook = moveCardsFromListToDeck(player,spook,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

                destroyList(spook)
            end
        end
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        insertCardTurnAction(player)

        local grav = getPlayerDeck(player, "DECK_GRAV")
        local card_list, qty = getListFromDeck(grav)
        local spook_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","Spook")

        local spook_spawn = menuCards(player,spook_list,"Select a card to spawn.","CARDLIST_PEEK")
        if spook_spawn ~= 0 then
            local hand = getPlayerDeck(player, "DECK_HAND")
            local spook_card = getCARD(spook_spawn)

            spook_spawn = takeTargetCardFromDeck(player,spook_spawn,grav)
            spook_spawn = takeTargetCardFromListToDeck(player,hand,spook_spawn,spook_spawn,"DECK_BOTTOM")
            summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")

            local slotid = getSlotIdFromCARD(player,spook_card)
            editCardRegister(src,cardid,0,slotid,0,nil)

            destroyList(spook_spawn)
        end

        destroyList(spook_list)
    end

}
