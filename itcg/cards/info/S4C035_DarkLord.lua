ZTCG_CARD
{

    "NAME" "Dark Lord"
    "IMAGE" "S4C035_DarkLord.png"
    "TYPE" "BOSS"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - NPC Boss"
    "COST" "1200"

    TYPE_BOS
    {
        "LEVEL" "80"
        "ATTCK" "70"
        "HP" "130"

        LVL_ACTION
        {
            "LEVEL" "60"
            "ATTRB" "1"
            "TEXT" "Stealthy Blow -- Choose one: Do 40 damage to a character or your opponent discards a card at random from his or her hand."
        }

        LVL_ACTION
        {
            "LEVEL" "90"
            "ATTRB" "3"
            "TEXT" "Shadow Rip -- Destroy a monster or item."
        }
    }

    function onActivateMobEffect(player)
        local src = getSourceCARD()

        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(matchRequirements(player, 60, 1, "ELEM_THIEF")) then
            if(makePrompt(player,false,"Select one:","ZTCG_NIL","ZTCG_NIL","ZTCG_NIL","Damage character","Opponent discard")) then
                attack(player, src, 40, "ATKRES_DONT_HIT_MOBS", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
            else
                discardCardRandom(not player)
            end
        end

        if(matchRequirements(player, 90, 3, "ELEM_THIEF")) then
            local mobs = getMobsOnTable(player,"ONLY_ADVSRY")
            local eqps = getEquipsOnTable(player,"ONLY_ADVSRY")

            if mobs > 0 and eqps > 0 then
                if makePrompt(player,false,"Select one:","ZTCG_NIL","ZTCG_NIL","ZTCG_NIL","Destroy monster","Destroy equipment") then
                    destroyMonster(player)
                else
                    destroyEquipment(player)
                end
            elseif mobs > 0 then
                destroyMonster(player)
            elseif eqps > 0 then
                destroyEquipment(player)
            end
        end
    end

}
