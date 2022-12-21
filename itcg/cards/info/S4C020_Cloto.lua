ZTCG_CARD
{

    "NAME" "Cloto"
    "IMAGE" "S4C020_Cloto.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Human NPC"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "20"
        "ATTCK" "20"
        "HP" "20"
        "TEXT" "NPC Quest -- You have Nella and Lakelis when your turn ends. Reward -- Search your deck for a Boss and play it. Then shuffle your deck."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Spawn 30 -- Play a monster of level 30 or less."
    }

    function onEndTurn(player)
        if not isBossOnPlayerTable(player) then
            local list1, not_empty1 = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","Nella")
            local list2, not_empty2 = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","Lakelis")

            if not_empty1 and not_empty2 then
                local deck = getPlayerDeck(player, "DECK_DECK")
                local card_list = getListFromDeck(deck)

                local boss_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_BOS","ELEM_ANY","ZTCG_NIL")
                if not_empty then
                    local menuCard = menuCards(player,boss_list,"Select a boss to play.","CARDLIST_PEEK")
                    if menuCard ~= 0 then
                        local hand = getPlayerDeck(player, "DECK_HAND")
                        moveCards(player,deck,hand,"TAKE_CARDID","PUT_BOTTOM",menuCard)
                        summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
                    end
                end

                destroyList(boss_list)
            end

            destroyList(list2)
            destroyList(list1)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 30"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",30)
    end

}
