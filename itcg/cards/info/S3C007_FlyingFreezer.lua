ZTCG_CARD
{

    "NAME" "Flying Freezer"
    "IMAGE" "S3C007_FlyingFreezer.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Summoned Flying Ice Bird"
    "COST" "1030"

    TYPE_MOB
    {
        "LEVEL" "120"
        "ATTCK" "100"
        "HP" "100"
        "TEXT" "Freeze -- When you play Flying Freezer, choose up to 4 of your opponent's monsters. They can't attack next turn. Summoned -- When your turn ends, destroy Flying Freezer if you didn't play it this turn."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Command -- Return this card to your hand. Then level up with the top card of your deck."
    }

    function onThinkMob(player)
        local list, not_empty = makeFilteredTableList(player, "ONLY_ADVSRY",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
        if not_empty then
            local i = 0
            while getListLength(list) > 0 and i < 4 do
                local card = menuCards(player,list,"Select a card to not attack next turn.","CARDLIST_PEEK")
                if card ~= 0 then
                    list = takeTargetCardFromList(card,list)

                    card = getCARD(card)
                    applyStun(player,card,1)

                    i = i + 1
                else
                    break
                end
            end
        end

        destroyList(list)
    end

    function onEndTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if(getCardRegister(src, cid, 0) == 1) then
            local slotid = getSlotIdFromCARD(player,src)
            destroyCard(player,"SLOT_PLAYERMOB" .. slotid)
        else
            editCardRegister(src, cid, 0, 1, 0, null)
        end
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        local d = destroyCharacterAction(player,src,true)

        if d then
            local grav = getPlayerDeck(player, "DECK_GRAV")
            local hand = getPlayerDeck(player, "DECK_HAND")

            local target = makeTargetFromCARD(src)
            local m = moveCards(player,grav,hand,"TAKE_CARDID","PUT_BOTTOM",target)
            destroyList(target)

            if m > 0 then
                local d = drawCard(player)
                if d then
                    levelUpScout(player,false)
                end
            end
        end
    end

}
