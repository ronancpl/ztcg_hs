ZTCG_CARD
{

    "NAME" "Cico"
    "IMAGE" "S1C053_Cico.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Water Beast"
    "COST" "510"

    TYPE_MOB
    {
        "LEVEL" "25"
        "ATTCK" "30"
        "HP" "20"
        "TEXT" "Loot -- If your opponent has 3 or more cards in hand, he or she chooses one and discards it."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 30 -- Play a monster or item of level 30 or less. "
    }

    function onThinkMob(player)
        local hand = getPlayerDeck(not player, "DECK_HAND")
        local cards, qty = getListFromDeck(hand)

        if qty >= 3 then
            discardCard(not player)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 30"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 30)
    end

}
