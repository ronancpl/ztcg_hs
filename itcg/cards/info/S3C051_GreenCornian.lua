ZTCG_CARD
{

    "NAME" "Green Cornian"
    "IMAGE" "S3C051_GreenCornian.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Dragon Beast"
    "COST" "910"

    TYPE_MOB
    {
        "LEVEL" "100"
        "ATTCK" "70"
        "HP" "100"
        "TEXT" "Relentless 70 -- Whenever Green Cornian destroys a monster, do 70 damage to your opponent's character."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Revive Dragon -- Return a Dragon from your discard pile to your hand."
    }

    function onAttackOpponentMobDestroyed(player)
        local src = getSourceCARD()
        if src == getCardPointer(0) and getSlotIdFromCARD(player, src) > -1 then
            attack(player, src, 70, "ATKRES_DONT_HIT_MOBS", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

    function onLevelActionTrigger(player)
        local deckHand = getPlayerDeck(player, "DECK_HAND")

        local deckGrav = getPlayerDeck(player, "DECK_GRAV")
        local deck_list = getListFromDeck(deckGrav)

        local menu, not_empty = makeFilteredList(player,deck_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "Dragon")
        if not_empty then
            local card = menuCards(player,menu,"Select a mob to revive.","CARDLIST_PEEK")
            if card ~= 0 then
                recoverDestroyedCard(player,getCARD(card))
            end
        end
        destroyList(menu)
    end

}
