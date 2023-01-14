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

    function onDestroy(player)
        local src = getSourceCARD()
        local list, not_empty = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP","ELEM_ANY","Pet")
        while not isEmptyList(list) do
            local pet
            list, pet = takeNextCardsFromList(list,1)

            local deck = getPlayerDeck(player, "DECK_DECK")

            local c = countCardsUnder(player,getCARD(pet))
            if c < 3 then
                local card_list = takeCardsFromDeck(player,deck, 1)
                local card = makeTargetFromCARD(getCARD(card_list))

                if card ~= 0 then
                    card_list = takeTargetCardFromList(card,card_list)
                    card = putCardUnder(getCARD(pet),card)
                end

                destroyList(card)
                destroyList(card_list)
            end

            destroyList(pet)
        end

        destroyList(list)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 80"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",80)
    end


}
