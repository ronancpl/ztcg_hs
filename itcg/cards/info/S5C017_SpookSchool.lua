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
                spook = moveCardsFromListToDeck(spook,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            end
            destroyList(spook)
        end
    end

    function onLevelActionTrigger(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local deck = getPlayerDeck(player, "DECK_GRAV")
        local card_list, qty = getListFromDeck(deck)
        local spook_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_MOB","ELEM_ANY","Spook")

        local spook_spawn = menuCards(player,spook_list,"Select a card to spawn.","CARDLIST_HIDE")
        if spook_spawn ~= 0 then
            card_list = takeTargetCardFromList(spook_spawn,card_list)
            spook_list = takeTargetCardFromListToDeck(hand,spook_list,spook_spawn,"DECK_BOTTOM")
            summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")

            local slotid = getSlotIdFromCARD(player, spook_spawn)
            editCardRegister(src,cardid,0,slotid,0,nil)
        end

        destroyList(spook_list)
    end

}
