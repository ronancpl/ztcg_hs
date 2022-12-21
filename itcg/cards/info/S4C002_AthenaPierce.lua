ZTCG_CARD
{

    "NAME" "Athena Pierce"
    "IMAGE" "S4C002_AthenaPierce.png"
    "TYPE" "BOSS"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - NPC Boss"
    "COST" "1100"

    TYPE_BOS
    {
        "LEVEL" "80"
        "ATTCK" "40"
        "HP" "150"
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "3"
        "TEXT" "Fatal Attack -- For each Bowman card under your character, do 20 damage to a character or monster."
    }

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(not matchRequirements(player, 70, 3, "ELEM_BOWMAN")) then return end

        local src = getSourceCARD()
        local c = getPlayerAttributes(player, "ELEM_BOWMAN")
        for i = 1, c, 1 do
            attack(player,src,20,"ATKRES_NIL", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

}
