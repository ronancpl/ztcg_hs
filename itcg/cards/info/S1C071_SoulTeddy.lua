ZTCG_CARD
{

    "NAME" "Soul Teddy"
    "IMAGE" "S1C071_SoulTeddy.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Undead Toy Bear"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "63"
        "ATTCK" "50"
        "HP" "40"
        "TEXT" "Tough -- Character actions don't damage Soul Teddy. Startle -- Whenever Soul Teddy attacks your opponent's character, that player discards a card at random from his or her hand."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Loot -- If your opponent has 3 or more cards in hand, he or she chooses one and discards it. "
    }

    function preventTargetMob(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            return 1
        else
            return 0
        end
    end

    function onExecuteNormalAttack(player)
        local def_card = getCardPointer(1)
        if hasSharedFlagsCARD(def_card,"FLAG_TYPE", "TYPE_CHAR") then
            discardCardRandom(not player)
        end
    end

    function onLevelActionTrigger(player)
        local hand = getPlayerDeck(not player, "DECK_HAND")
        local cards, qty = getListFromDeck(hand)

        if qty >= 3 then
            discardCard(not player)
        end
    end

}
