ZTCG_CARD
{

    "NAME" "Puppy"
    "IMAGE" "S3C057_Puppy.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Pet Dog"
    "COST" "650"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "Hungry -- When your turn starts, put the top card of your deck face down under this Pet. (A Pet can have up to 3 cards under it.) Dog's Life -- When Puppy has 3 cards under it, get +30 HP and put those cards on the bottom of your deck in any order."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Spawn 50 -- Play a monster of level 50 or less."
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player, src) < 0 then return end

        local deck = getPlayerDeck(player, "DECK_DECK")

        local c = countCardsUnder(player,src)
        if c < 3 then
            local card_list = takeCardsFromDeck(player,deck, 1)
            local card = makeTargetFromCARD(getCARD(card_list))

            if card ~= 0 then
                card_list = takeTargetCardFromList(card,card_list)
                putCardUnder(src,card)
            end

            destroyList(card_list)
        end

        local c = countCardsUnder(player,src)
        if c >= 3 then
            local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            refreshHP(player,card,30)

            local card_list = removeCardsUnder(src)

            pickCardOrder(player,card_list)
            card_list = moveCardsFromListToDeck(player,card_list,deck,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")

            destroyList(card_list)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 50"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",50)
    end

}
