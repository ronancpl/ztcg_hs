ZTCG_CARD
{

    "NAME" "Poison Poopa"
    "IMAGE" "S2C037_PoisonPoopa.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Water Fish"
    "COST" "590"

    TYPE_MOB
    {
        "LEVEL" "40"
        "ATTCK" "30"
        "HP" "20"
        "TEXT" "Fugu -- When Poison Poopa damages a non-Boss monster, destroy that monster."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Spawn / Equip 30 -- Play a monster or item of level 30 or less. "
    }

    function destroyCard(player, card, tableStr, isEqp)
        if isBossCARD(card) then return end

        local ret = false
        local slotid = getSlotIdFromCARD(player, card)
        if slotid >= 0 then
            local new_list, not_empty = takeCardFromTable(player, tableStr .. (isEqp and (slotid - 7) or slotid))

            if not_empty then
                local deckGrav = getPlayerDeck(player, "DECK_GRAV")
                new_list = moveCardsFromListToDeck(new_list,deckGrav,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")

                ret = true
            end

            destroyList(new_list)
        end

        return ret
    end

    function onOpponentPlayMob(player)
        local target = getTargetCARD()
        local src = getSourceCARD()

        if target ~= 0 then
            if destroyCard(not player, target, "SLOT_PLAYERMOB", false) then
                destroyCard(player, src, "SLOT_PLAYERMOB", false)
            end
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 30"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 30)
    end

}
