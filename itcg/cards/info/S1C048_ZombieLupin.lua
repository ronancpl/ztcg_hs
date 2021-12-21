ZTCG_CARD
{

    "NAME" "Zombie Lupin"
    "IMAGE" "S1C048_ZombieLupin.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Undead Monkey"
    "COST" "500"

    TYPE_MOB
    {
        "LEVEL" "40"
        "ATTCK" "20"
        "HP" "20"
        "TEXT" "Devious -- When you play Zombie Lupin, return a tactic from your discard pile to your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Drink Potion -- You get +HP equal to your level. "
    }

    function onThinkMob(player)
        local deck = getPlayerDeck(player, "DECK_GRAV")
        local card_list, qty = getListFromDeck(deck)
        local new_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ACT","ELEM_ANY","ZTCG_NIL")

        if not_empty then
            local card = menuCards(player,new_list,"Select a tactic to draw.","CARDLIST_PEEK")
            if card ~= 0 then
                recoverDestroyedCard(player,getCARD(card))
            end
        end

        destroyList(new_list)
    end

    function onLevelActionTrigger(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        refreshHP(player,chr,level)
    end


}
