ZTCG_CARD
{

    "NAME" "Goo Zoo"
    "IMAGE" "S5C063_GooZoo.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Goo Upgrade"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "40"
        "ATTCK" "40"
        "HP" "40"
        "TEXT" "Goo Upgrade -- Put on one of your Goo monsters. Divide -- When Goo Zoo would be destroyed, if there's a card under it, you may play that card instead."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Grew New Goo -- Search your deck for a Goo, reveal it, and put it into your hand. Then shuffle your deck."
    }

    function onLevelActionTrigger(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local deck = getPlayerDeck(player, "DECK_DECK")
        local hand = getPlayerDeck(player, "DECK_HAND")

        local card_list, qty = getListFromDeck(deck)
        local goo_list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","Goo")

        local goo_spawn = menuCards(player,goo_list,"Select a card to spawn.","CARDLIST_PEEK")
        if goo_spawn ~= 0 then
            revealCard(not player,"Opponent has drawn card...",getCARD(goo_spawn))
            moveCards(player,deck,hand,"TAKE_CARDID","PUT_BOTTOM",goo_spawn)
        end

        destroyList(goo_list)
        shuffleDeck(deck)
    end

}
