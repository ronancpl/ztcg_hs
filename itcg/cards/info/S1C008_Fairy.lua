ZTCG_CARD
{

    "NAME" "Fairy"
    "IMAGE" "S1C008_Fairy.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Flying Fairy"
    "COST" "580"

    TYPE_MOB
    {
        "LEVEL" "30"
        "ATTCK" "30"
        "HP" "20"
        "TEXT" "Hide -- Whenever your opponent levels up, return Fairy to your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "2"
        "TEXT" "Spawn 30 -- Play a monster of level 30 or less. "
    }

    function onOpponentLevelUp(player)
        local src = getSourceCARD()
        local slot = getSlotIdFromCARD(player, src)

        local list, hasCard
        list, hasCard = takeCardFromTable(player, slot)

        if hasCard then
            local deckHand = getPlayerDeck(player, "DECK_HAND")
            list = moveCardsFromListToDeck(list, deckHand,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
        end

        destroyList(list)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 30"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",30)
    end

}
