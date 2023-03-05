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
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 60 -- Play a monster or item of level 60 or less. "
    }

    function onExecuteAttack(player)
        local def_card = getCardPointer(1)
        if isBossCARD(def_card) then return end

        local slotid = getSlotIdFromCARD(not player, def_card)
        if slotid > 0 then
            destroyCard(player,"SLOT_ADVSRYMOB" .. slotid)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 60"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 60)
    end

}
