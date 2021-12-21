ZTCG_CARD
{

    "NAME" "Tauromacis"
    "IMAGE" "S1C093_Tauromacis.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Bull Human"
    "COST" "800"

    TYPE_MOB
    {
        "LEVEL" "70"
        "ATTCK" "50"
        "HP" "40"
        "TEXT" "Prevail -- When Tauromacis is destroyed return it to your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Train Hard -- If you have 3 or more Warrior cards under your character, you may level up with another card. "
    }

    function onAttackMobDestroyed(player)
        local src = getSourceCARD()
        local srcCard = makeTargetFromCard(src)

        local deckGrav = getPlayerDeck(player, "DECK_GRAV")
        local cardList = takeTargetCardFromDeck(srcCard,deckGrav)

        local deckHand = getPlayerDeck(player, "DECK_HAND")
        cardList = moveCardsFromListToDeck(cardList, deckHand,"TAKE_NEXT","PUT_BOTTOM",1)

        destroyList(cardList)
        destroyList(srcCard)
    end

    function onLevelActionTrigger(player)
        if getPlayerAttributes(player, "ELEM_WARRIOR") >= 3 then
            levelUp(player)
        end
    end


}
