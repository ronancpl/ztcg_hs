ZTCG_CARD
{

    "NAME" "Street Slime"
    "IMAGE" "S4C055_StreetSlime.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Goo"
    "COST" "600"

    TYPE_MOB
    {
        "LEVEL" "19"
        "ATTCK" "10"
        "HP" "10"
        "TEXT" "Burble -- Street Slime gets +10 attack and +10 HP for each of your other Goo in play or in your discard pile."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Stick Together -- Monsters that attack this turn each get +10 attack for each Goo you have when you attack."
    }

    function onThinkMob(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        editCardRegister(src, cid, 1, 1, 0, nil)

        local grav = getPlayerDeck(player,"DECK_GRAV")
        local card_list = getListFromDeck(grav)
        local goo_list = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY", "ELEM_ANY", "Goo")
        local goo_table = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY", "ELEM_ANY", "Goo")
        local len = getListLength(goo_list) + getListLength(goo_table) - 1
        destroyList(goo_table)
        destroyList(goo_list)

        incrementBuffEffect(player,src)
        newBuff(src,src,10 * len,10 * len,0,1)
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 10, 0, nil)
        incrementBuffEffect(player,src)
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        if(getCardRegister(src, cid, 0) ~= 10) then
            if(getCardRegister(src, cid, 1) == 1) then
                local grav = getPlayerDeck(player,"DECK_GRAV")
                local card_list = getListFromDeck(grav)
                local goo_list = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY", "ELEM_ANY", "Goo")
                local goo_table = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY", "ELEM_ANY", "Goo")
                local len = getListLength(goo_list) + getListLength(goo_table) - 1
                destroyList(goo_table)
                destroyList(goo_list)

                removeBuff(src,src,10 * len,10 * len,0)
            end
        else
            local goo_table = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY", "ELEM_ANY", "Goo")
            local len = getListLength(goo_table)
            destroyList(goo_table)

            removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,10 * len,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
        end
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        if(getCardRegister(src, cid, 0) ~= 10) then
            if(getCardRegister(src, cid, 1) == 1) then
                local grav = getPlayerDeck(player,"DECK_GRAV")
                local card_list = getListFromDeck(grav)
                local goo_list = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY", "ELEM_ANY", "Goo")
                local goo_table = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY", "ELEM_ANY", "Goo")
                local len = getListLength(goo_list) + getListLength(goo_table) - 1
                destroyList(goo_table)
                destroyList(goo_list)

                newBuff(src,src,10 * len,10 * len,0,1)
            end
        else
            local goo_table = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY", "ELEM_ANY", "Goo")
            local len = getListLength(goo_table)
            destroyList(goo_table)

            applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_ANY",src,10 * len,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
        end
    end

}
