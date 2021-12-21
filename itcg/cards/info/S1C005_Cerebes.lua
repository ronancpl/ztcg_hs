ZTCG_CARD
{

    "NAME" "Cerebes"
    "IMAGE" "S1C005_Cerebes.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Dog"
    "COST" "950"

    TYPE_MOB
    {
        "LEVEL" "72"
        "ATTCK" "70"
        "HP" "70"
        "TEXT" "Earthquake -- Whenever a monster damages Cerebes, do 40 damage to that monster."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 120 -- Play a monster or item of level 120 or less. "
    }

    function onReceiveAttack(player)
        if hasFlag("ZTCG_ATKSRC","ATKSRC_MOB") then
            local target = getCardPointer(0)
            local slot = getSlotIdFromCARD(not player, target)

            local src = getSourceCARD()
            attack(player, src, 40, "ATKRES_FIXED_SLOT", "ATKSRC_MOB", "SLOT_ADVSRYMOB" .. tostring(slot), "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 120"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 120)
    end

}
