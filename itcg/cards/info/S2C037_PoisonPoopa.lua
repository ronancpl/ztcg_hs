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

    function onExecuteAttack(player)
        local target = getCardPointer(1)
        if target ~= 0 then
            if isBossCARD(target) then return end

            local slotid = getSlotIdFromCARD(not player, target)
            if slotid > 0 then
                local new_list, not_empty = takeCardFromTable(not player, "SLOT_PLAYERMOB" .. slotid)

                if not_empty then
                    local deckGrav = getPlayerDeck(not player, "DECK_GRAV")
                    new_list = moveCardsFromListToDeck(new_list,deckGrav,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
                end

                destroyList(new_list)
            end
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 30"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 30)
    end

}
