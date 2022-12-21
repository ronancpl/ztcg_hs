ZTCG_CARD
{

    "NAME" "Flynn"
    "IMAGE" "S5C006_Flynn.png"
    "TYPE" "CHAR"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Sniper"
    "COST" "700"

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
            "ATTRB" "1"
            "TEXT" "Easy Shot -- Do 10 damage to a character or monster."
        }
        LVL_ACTION
        {
            "LEVEL" "30"
            "ATTRB" "2"
            "TEXT" "Flying Spawn X -- Play a Flying monster of your level or less."
        }
        "HP" "190"
    }

    function onActivateCharacterAction1(player)
        drawCard(player)
    end

    function onActivateCharacterAction2(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction3(player)
        local src = getSourceCARD()

        local deckHand = getPlayerDeck(player, "DECK_HAND")
        local card_list = getListFromDeck(deckHand)

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        local mobList, not_empty = makeFilteredList(player,card_list,0,0,level,"TYPE_ANYMOB", "ELEM_ANY", "Flying")
        if not_empty then
            local menuCard = menuCards(player,mobList,"Select a Flying mob to spawn.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                local card = getCARD(menuCard)

                menuCard = takeTargetCardFromDeck(player,menuCard,deckHand)
                menuCard = moveCardsFromListToDeck(player,menuCard,deckHand,"TAKE_CARDID","PUT_BOTTOM",menuCard)
                summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")

                destroyList(menuCard)
            end
        end
        destroyList(mobList)
    end


}
