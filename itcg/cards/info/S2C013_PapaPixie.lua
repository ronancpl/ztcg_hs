ZTCG_CARD
{

    "NAME" "Papa Pixie"
    "IMAGE" "S2C013_PapaPixie.png"
    "TYPE" "BOSS"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Boss"
    "COST" "700"

    TYPE_BOS
    {
        "HP" "120"
        "ATTCK" "40"
        "LEVEL" "74"
        LVL_ACTION
        {
            "LEVEL" "60"
            "ATTRB" "1"
            "TEXT" "Spook Summon -- If Papa Pixie has 60 HP or less, you may search your deck for a Spook and play it. Then shuffle your deck."
        }
    }

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(not matchRequirements(player, 60, 2, "ELEM_BOWMAN")) then return end

        local src = getSourceCARD()
        if getHpFromCARD(src) <= 60 then
            local deck = getPlayerDeck(player, "DECK_DECK")
            local card_list, qty = getListFromDeck(deck)
            local new_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_MOB","ELEM_ANY","Spook")

            if not_empty then
                local card = menuCards(player,new_list,"Select a monster to draw.","CARDLIST_PEEK")
                if card ~= 0 then
                    local hand = getPlayerDeck(player, "DECK_HAND")
                    moveCards(player,deck,hand,"TAKE_CARDID","PUT_BOTTOM",card)

                    summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
                    shuffleDeck(player,"DECK_DECK")
                end
            end

            destroyList(new_list)
        end
    end
}
