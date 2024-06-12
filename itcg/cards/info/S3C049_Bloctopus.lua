ZTCG_CARD
{

    "NAME" "Bloctopus"
    "IMAGE" "S3C049_Bloctopus.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Toy Guardian"
    "COST" "760"

    TYPE_MOB
    {
        "LEVEL" "35"
        "ATTCK" "20"
        "HP" "30"
        "TEXT" "Escape -- If your opponent makes you discard Bloctopus, you may play it instead of putting it into your discard pile."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Scout -- Reveal the top card of your deck. If it's a monster card, put it into your hand. Otherwise, put it back."
    }

    function onDiscard(player)
        if hasFlag("ZTCG_PLAYERTYPE", "IS_ADVSRY") then
            local src = getSourceCARD()
            local card = makeTargetFromCARD(src)

            local grav = getPlayerDeck(player, "DECK_GRAV")
            local hand = getPlayerDeck(player, "DECK_HAND")
            local cardList = takeTargetCardFromDeck(player,card,grav)
            local qty

            cardList, qty = moveCardsFromListToDeck(player,cardList,hand,"TAKE_NEXT","PUT_BOTTOM","ZTCG_MAXVALUE")
            if qty > 0 then
                summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
            end

            destroyList(cardList)
            destroyList(card)
        end
    end

    function onLevelActionTrigger(player)
        scoutMob(player,"SCOUT_NORMAL","ELEM_ANY")
    end

}
