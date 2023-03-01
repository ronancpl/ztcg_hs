ZTCG_CARD
{

    "NAME" "Shammos"
    "IMAGE" "S4C053_Shammos.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Troll NPC"
    "COST" "850"

    TYPE_MOB
    {
        "LEVEL" "50"
        "ATTCK" "40"
        "HP" "40"
        "TEXT" "NPC Quest -- You have 4 or more monsters in your discard pile when your turn ends. Reward -- Return a monster card from your discard pile to your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Spawn 60 -- Play a monster of level 60 or less."
    }

    function onEndTurn(player)
        local grav = getPlayerDeck(player, "DECK_GRAV")
        local deckl, qty = getListFromDeck(grav)

        local menu = makeFilteredList(player, deckl, 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
        if getListLength(menu) >= 4 then
            recoverCard(player, "DECK_HAND", "RECOVER_MOB", "LESSER", "ZTCG_MAXVALUE")
        end
        destroyList(menu)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 60"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",60)
    end

}
