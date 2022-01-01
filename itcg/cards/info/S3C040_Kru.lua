ZTCG_CARD
{

    "NAME" "Kru"
    "IMAGE" "S3C040_Kru.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Water Scoundrel"
    "COST" "680"

    TYPE_MOB
    {
        "LEVEL" "68"
        "ATTCK" "60"
        "HP" "50"
        "TEXT" "Loot -- If your opponent has 3 or more cards in hand, he or she chooses one and discards it."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn 70 -- Play a monster of level 70 or less."
    }

    function onThinkMob(player)
        local hand = getPlayerDeck(not player, "DECK_HAND")
        local cards, qty = getListFromDeck(hand)

        if qty >= 3 then
            discardCard(not player)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 70"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",70)
    end

}
