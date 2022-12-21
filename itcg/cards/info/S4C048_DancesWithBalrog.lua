ZTCG_CARD
{

    "NAME" "Dances With Balrog"
    "IMAGE" "S4C048_DancesWithBalrog.png"
    "TYPE" "BOSS"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - NPC Boss"
    "COST" "950"

    TYPE_BOS
    {
        "LEVEL" "80"
        "ATTCK" "40"
        "HP" "160"
    }

    LVL_ACTION
    {
        "LEVEL" "90"
        "ATTRB" "3"
        "TEXT" "MegaSpawn -- Search your deck for a non-Boss monster and play it. Then shuffle your deck."
    }

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(matchRequirements(player, 90, 3, "ELEM_WARRIOR")) then
            local deck = getPlayerDeck(player, "DECK_DECK")
            local card_list, qty = getListFromDeck(deck)

            local mob_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_MOB","ELEM_ANY","ZTCG_NIL")
            if not_empty then
                local menuCard = menuCards(player,mob_list,"Select a card to play.","CARDLIST_PEEK")
                if menuCard ~= 0 then
                    local hand = getPlayerDeck(player, "DECK_HAND")
                    moveCards(player,deck,hand,"TAKE_CARDID","PUT_BOTTOM",menuCard)
                    summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
                end
            end

            destroyList(mob_list)
        end
    end

}
