ZTCG_CARD
{

    "NAME" "Athena's Death Arrow"
    "IMAGE" "S4C003_AthenasDeathArrow.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "700"

    TYPE_ACT
    {
        "LEVEL" "90"
        "TEXT" "Do 100 damage to a character or monster. This damage can't be prevented."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Athena Team Up -- Do 20 damage to a character or monster. If you're level 60 or more, you may play Athena Pierce."
    }

    function preventTargetCancel(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if hasFlag("ZTCG_ATKSRC", "ATKSRC_ACT") and getCardRegister(src, cid, 0) == 100 then
            return 1
        else
            return 0
        end
    end

    function onThinkAction(player)
        insertCardNextAction(player)

        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        editCardRegister(src, cid, 0, 100, 0, nil)

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 100, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onStartTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 0, 0, nil)
    end

    function onLevelActionTrigger(player)
        local src = getSourceCARD()
        attack(player,src,20,"ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        local deckHand = getPlayerDeck(player, "DECK_HAND")
        local card_list, qty = getListFromDeck(deckHand)

        local list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY","Athena Pierce")
        if level >= 60 and not_empty then
            local card = menuCards(player,list,"Select a mob to spawn.","CARDLIST_PEEK")
            if card ~= 0 then
                moveCards(deckHand,deckHand,"TAKE_CARDID","PUT_BOTTOM",card)
                summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
            end
        end
        destroyList(list)
    end

}
