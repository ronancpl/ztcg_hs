ZTCG_CARD
{

    "NAME" "Devil Slime"
    "IMAGE" "S2C049_DevilSlime.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Goo"
    "COST" "510"

    TYPE_MOB
    {
        "LEVEL" "23"
        "ATTCK" "10"
        "HP" "20"
        "TEXT" "Vanish -- When Devil Slime is destroyed level up with it, but you don't get the +HP for leveling up."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "1"
        "TEXT" "Spawn 30 -- Play a monster of level 30 or less. "
    }

    function onReceiveAttackAndDestroyed(player)
        local src = getSourceCARD()
        local target = getCardPointer(1)

        if isSameCARD(src,target) then
            local card = makeTargetFromCARD(src)

            local grav = getPlayerDeck(player, "DECK_GRAV")
            local hand = getPlayerDeck(player, "DECK_HAND")

            local qty
            local cards = takeTargetCardFromDeck(player,card,grav)

            cards, qty = moveCardsFromListToDeck(player,cards,hand,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            if qty > 0 then
                levelUpScout(player,true)
            end

            destroyList(cards)
            destroyList(card)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 30"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",30)
    end

}
