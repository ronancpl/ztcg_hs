ZTCG_CARD
{

    "NAME" "Vogen's Forge"
    "IMAGE" "S4C045_VogensForge.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Strategy"
    "COST" "750"

    TYPE_ACT
    {
        "LEVEL" "35"
        "TEXT" "Choose one: Destroy an item, or play an item of your level or less from your discard pile."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Spy -- Draw a card. Then discard a card from your hand."
    }

    function onThinkAction(player)
        if(makePrompt(player,false,"Select one:","ZTCG_NIL","ZTCG_NIL","ZTCG_NIL","Destroy equipment","Play from discard")) then
            destroyEquipment(player)
        else
            local player_hand = getPlayerDeck(player, "DECK_HAND")

            local player_grav = getPlayerDeck(player, "DECK_GRAV")
            local deck_list = getListFromDeck(player_grav)

            local card_list, not_empty = makeFilteredList(player,deck_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP", "ELEM_ANY", "ZTCG_NIL")
            if not_empty then
                local card = menuCards(player,card_list,"Select a card to play.","CARDLIST_PEEK")
                if card ~= 0 then
                    moveCards(player,player_grav,player_hand,"TAKE_CARDID","PUT_BOTTOM",card)
                    equip(player,"PLAY_SCOUTEQUIP", "ELEM_ANY","ZTCG_MAXVALUE")
                end
            end

            destroyList(card_list)
        end
    end

    function onLevelActionTrigger(player)
        drawCard(player)
        discardCard(player)
    end

}
