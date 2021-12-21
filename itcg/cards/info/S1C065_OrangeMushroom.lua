ZTCG_CARD
{

    "NAME" "Orange Mushroom"
    "IMAGE" "S1C065_OrangeMushroom.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Mushroom"
    "COST" "650"

    TYPE_MOB
    {
        "LEVEL" "8"
        "ATTCK" "30"
        "HP" "10"
        "TEXT" "Loot -- If your opponent has 3 or more cards in hand, he or she chooses one and discards it."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Equip 40 -- Play an item of level 40 or less. "
    }

    function onThinkMob(player)
        local hand = getPlayerDeck(not player, "DECK_HAND")
        local cards, qty = getListFromDeck(hand)

        if qty >= 3 then
            discardCard(not player)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Equip 40"
        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY",40)
    end


}
