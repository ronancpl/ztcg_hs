ZTCG_CARD
{

    "NAME" "Boomer"
    "IMAGE" "S4C032_Boomer.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Bomb"
    "COST" "630"

    TYPE_MOB
    {
        "LEVEL" "27"
        "ATTCK" "30"
        "HP" "20"
        "TEXT" "Short Fuse -- Whenever a monster damages Boomer, flip a coin. If you win, destroy that monster and Boomer."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "1"
        "TEXT" "Spawn 100 -- Play a monster of level 100 or less."
    }

    function onReceiveAttack(player)
        if hasFlag("ZTCG_ATKSRC","ATKSRC_MOB") then
            if throwCoin(player) then
                local slotid

                local atkr = getCardPointer(0)
                slotid = getSlotIdFromCARD(not player,atkr)
                destroySelf(player,"SLOT_ADVSRYMOB" .. slotid)

                local src = getSourceCARD()
                slotid = getSlotIdFromCARD(player,src)
                destroySelf(player,"SLOT_PLAYERMOB" .. slotid)
            end
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 100"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",100)
    end

}
