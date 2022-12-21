ZTCG_CARD
{

    "NAME" "Nova"
    "IMAGE" "S2C034_Nova.png"
    "TYPE" "CHAR"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Character - Assassin"
    "COST" "800"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card."
        }
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "2"
            "TEXT" "Mastermind -- Play a Weapon, Strategy, or Undead card of your level or less. "
        }
        LVL_ACTION
        {
            "LEVEL" "40"
            "ATTRB" "1"
            "TEXT" "Slash -- Do 20 damage to a character or monster. "
        }
        "HP" "200"
    }

    function onActivateCharacterAction1(player)
        drawCard(player)
    end

    function onActivateCharacterAction2(player)
        local hand = getPlayerDeck(player,"DECK_HAND")
        local deck = getPlayerDeck(player,"DECK_DECK")

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        local card_list = getListFromDeck(hand)

        local wList, w_not_empty = makeFilteredList(player,card_list,"ZTCG_DONTCARE","ZTCG_DONTCARE",level,"TYPE_ANY", "ELEM_ANY", "Weapon")
        local sList, s_not_empty = makeFilteredList(player,card_list,"ZTCG_DONTCARE","ZTCG_DONTCARE",level,"TYPE_ANY", "ELEM_ANY", "Strategy")
        local uList, u_not_empty = makeFilteredList(player,card_list,"ZTCG_DONTCARE","ZTCG_DONTCARE",level,"TYPE_ANY", "ELEM_ANY", "Undead")
        if w_not_empty or s_not_empty or u_not_empty then
            local cards = wList
            cards = appendLists(cards,sList)
            cards = appendLists(cards,uList)

            local menuCard = menuCards(player,cards,"Select a card to play.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                moveCards(player,hand,hand,"TAKE_CARDID","PUT_BOTTOM",menuCard)

                local card = getCARD(menuCard)
                if hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_ANYMOB") then
                    ret = summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_EQP") then
                    ret = equip(player,"PLAY_SCOUTEQUIP", "ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_ACT") then
                    ret = action(player,card, "ELEM_ANY","ZTCG_MAXVALUE")
                elseif hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_FLD") then
                    ret = locate(player,"PLAY_FIRSTCARDFIELD", "ELEM_ANY")
                end
            end
        end

        destroyList(uList)
        destroyList(sList)
        destroyList(wList)
    end

    function onActivateCharacterAction3(player)
        local src = getSourceCARD()
        attack(player, src, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
