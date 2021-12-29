ZTCG_CARD
{

    "NAME" "Phantom Watch"
    "IMAGE" "S2C015_PhantomWatch.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Undead Time Spook"
    "COST" "600"

    TYPE_MOB
    {
        "LEVEL" "95"
        "ATTCK" "70"
        "HP" "70"
        "TEXT" "Stealthy -- Monsters can't attack Phantom Watch."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "3"
        "TEXT" "Deadly Shot -- Do 30 damage to a character or monster. "
    }

    function preventTargetMob(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            return 1
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 30, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
