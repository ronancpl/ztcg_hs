ZTCG_CARD
{

    "NAME" "Black Boogie"
    "IMAGE" "S5C076_BlackBoogie.png"
    "TYPE" "MOB"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Flying Zakum Guardian"
    "COST" "630"

    TYPE_MOB
    {
        "LEVEL" "65"
        "ATTCK" "70"
        "HP" "30"
        "TEXT" "Inspired -- If you have a Boss, Black Boogie can't be damaged."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Zommand -- Search your deck for a Zakum card, reveal it, and put it into your hand. Then shuffle your deck."
    }

    function preventTargetMob(player)
        if isBossOnPlayerTable(player) then
            return 1
        else
            return 0
        end
    end

    function onLevelActionTrigger(player)
        local deck = getPlayerDeck(player, "DECK_DECK")
        local card_list, qty = getListFromDeck(deck)

        if qty > 0 then
            local cards = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY","Zakum")

            local card = menuCards(player,cards,"Select a tactic to draw.","CARDLIST_PEEK")
            if card ~= 0 then
                local hand = getPlayerDeck(player, "DECK_HAND")
                moveCards(player,deck,hand,"TAKE_CARDID","PUT_BOTTOM",card)

                revealCard(not player,"Opponent has drawn card...",getCARD(card))
                shuffleDeck(deck)
            end

            destroyList(cards)
        end
    end

}
