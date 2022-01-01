ZTCG_CARD
{

    "NAME" "Pig"
    "IMAGE" "S3C056_Pig.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Boar"
    "COST" "830"

    TYPE_MOB
    {
        "LEVEL" "7"
        "ATTCK" "10"
        "HP" "20"
        "TEXT" "Delicious -- When Pig is destroyed, put 1 card from the top of your deck face down under each of your Pets that has fewer than 3 cards under it."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn 80 -- Play a monster of level 80 or less."
    }

    function onMobSentToDiscardPile(player)
        local list, not_empty = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP","ELEM_ANY","Pet")
        while not isEmptyList(list) do
            local card = menuCards(player,list,"Select a pet to feed.","CARDLIST_PEEK")
            if card ~= 0 then
                local deck = getPlayerDeck(player, "DECK_DECK")

                local c = countCardsUnder(player,src)
                if c < 3 then
                    local cards = takeCardsFromDeck(deck, 1)
                    local card = menuCards(player,cards,"Pick a card to place under the pet.","CARDLIST_HIDE")

                    if card ~= 0 then
                        cards = takeTargetCardFromList(card,cards)
                        putCardUnder(src,card)
                    end

                    destroyList(cards)
                end
            else
                break
            end
        end

        destroyList(list)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 80"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",80)
    end


}
