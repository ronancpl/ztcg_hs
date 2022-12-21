ZTCG_CARD
{

    "NAME" "Pianus"
    "IMAGE" "S2C036_Pianus.png"
    "TYPE" "BOSS"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Boss"
    "COST" "800"

    TYPE_BOS
    {
        "HP" "200"
        "ATTCK" "50"
        "LEVEL" "110"
        LVL_ACTION
        {
            "LEVEL" "90"
            "ATTRB" "2"
            "TEXT" "White-Hot Doom Blast -- Pianus does 100 damage to a character or monster."
        }
    }

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(not matchRequirements(player, 90, 3, "ELEM_THIEF")) then return end

        local src = getSourceCARD()
        attack(player, src, 100, "ATKRES_NIL", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
