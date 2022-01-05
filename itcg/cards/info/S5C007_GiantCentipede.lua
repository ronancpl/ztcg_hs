ZTCG_CARD
{

    "NAME" "Giant Centipede"
    "IMAGE" "S5C007_GiantCentipede.png"
    "TYPE" "BOSS"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Boss"
    "COST" "830"

    TYPE_BOS
    {
        "HP" "90"
        "ATTCK" "40"
        "LEVEL" "59"
        LVL_ACTION
        {
            "LEVEL" "60"
            "ATTRB" "2"
            "TEXT" "Trample 30 -- Giant Centipede does 30 damage to each other monster that isn't Flying."
        }
    }

    local function attackNotInfo(src,dmg,slotStr,slotid,info)
        local card = getOnBoardCARD(player, slotid)
        if card ~= 0 and not isInfoCARD(card,info) then
            attack(player, src, 30, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", slotStr .. tostring(slotid), "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end
    end

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(not matchRequirements(player, 60, 2, "ELEM_BOWMAN")) then return end

        local src = getSourceCARD()
        attackNotInfo(src,30,"SLOT_ADVSRYMOB",1,"Flying")
        attackNotInfo(src,30,"SLOT_ADVSRYMOB",2,"Flying")
        attackNotInfo(src,30,"SLOT_ADVSRYMOB",3,"Flying")
        attackNotInfo(src,30,"SLOT_ADVSRYMOB",4,"Flying")
        attackNotInfo(src,30,"SLOT_ADVSRYMOB",5,"Flying")
        attackNotInfo(src,30,"SLOT_ADVSRYMOB",6,"Flying")
        attackNotInfo(src,30,"SLOT_ADVSRYMOB",7,"Flying")
    end

}
