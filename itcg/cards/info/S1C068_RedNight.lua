ZTCG_CARD
{

    "NAME" "Red Night"
    "IMAGE" "S1C068_RedNight.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Armor"
    "COST" "540"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "Whenever one of your monsters is destroyed, flip a coin. If you win, your opponent chooses and discards a card from his or her hand."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Spy -- Draw a card. Then discard a card from your hand."
    }

    function onAttackMobDestroyed(player)
        local deckHand = getPlayerDeck(not player, "DECK_HAND")
        local card_list, qty = getListFromDeck(deckHand)

        if qty > 0 then
            if throwCoin(player) then
                discardCard(not player)
            end
        end
    end

    function onLevelActionTrigger(player)
        drawCard(player)
        discardCard(player)
    end

}
