ZTCG_CARD
{

    "NAME" "Jr. Balrog"
    "IMAGE" "S2C009_JrBalrog.png"
    "TYPE" "BOSS"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Boss"
    "COST" "810"

    TYPE_BOS
    {
        "HP" "150"
        "ATTCK" "40"
        "LEVEL" "80"
        LVL_ACTION
        {
            "LEVEL" "0"
            "ATTRB" "0"
            "TEXT" "Rend -- Damage from Jr. Balrog can't be prevented."
        }
        LVL_ACTION
        {
            "LEVEL" "100"
            "ATTRB" "2"
            "TEXT" "Meteor Slam -- Jr. Balrog does 30 damage to a character or monster. Then Jr. Balrog does another 30 damage to a character or monster. "
        }
    }

    function preventTargetCancel(player)
        return 1
    end

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(not matchRequirements(player, 100, 3, "ELEM_BOWMAN")) then return end

        local src = getSourceCARD()
        attack(player, src, 30, "ATKRES_NIL", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 30, "ATKRES_NIL", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
