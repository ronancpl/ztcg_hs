ZTCG_CARD
{

    "NAME" "Right Arms of Zakum"
    "IMAGE" "S5C087_RightArmsofZakum.png"
    "TYPE" "MOB"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Zakum Arms"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "80"
        "ATTCK" "80"
        "HP" "50"
        "TEXT" "Zeitgeist 20 -- Each of your other Zakum monsters gets +20 attack."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "0"
        "TEXT" "Zpawn -- Play a monster of level 60 or less, or play a Zakum card of level 90 or less."
    }

    function undoBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,20,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Zakum")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_OTHER",src,20,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Zakum")
    end

    function onActivateCharacterAction(player)
        local hand = getPlayerDeck(player, "DECK_HAND")
        local card_list, qty = getListFromDeck(hand)

        local new_list, not_empty = makeFilteredList(player,card_list,0,61,90,"TYPE_ANYMOB", "ELEM_ANY", "Zakum")
        local new_list2, not_empty2 = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE",90,"TYPE_ANYMOB", "ELEM_ANY", "Zakum")

        if not_empty and (getListLength(new_list) >= getListLength(new_list2) or (not makePrompt(player,false,"Select one:","ZTCG_NIL","ZTCG_NIL","ZTCG_NIL","Spawn 60","Zpawn 90"))) then
            local card = menuCards(player,new_list2,"Select a monster to spawn.","CARDLIST_PEEK")
            if card ~= 0 then
                moveCards(player,hand,hand,"TAKE_CARDID","PUT_BOTTOM",card)
                summon(player,"PLAY_SCOUTSUMMON","ELEM_ANY",90)
            end
        else
            local str = "Spawn 60"
            summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",60)
        end

        destroyList(new_list2)
        destroyList(new_list)
    end

}
