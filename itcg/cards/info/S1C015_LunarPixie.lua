ZTCG_CARD
{

    "NAME" "Lunar Pixie"
    "IMAGE" "S1C015_LunarPixie.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Flying Spook"
    "COST" "580"

    TYPE_MOB
    {
        "LEVEL" "45"
        "ATTCK" "40"
        "HP" "20"
        "TEXT" "Stealthy -- Monsters can't attack Lunar Pixie. Haunt -- When you play Lunar Pixie, do 20 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Revive -- Return a monster of level 30 or less from your discard pile to your hand. "
    }

    function preventTargetMob(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            return 1
        else
            return 0
        end
    end

    function onThinkMob(player)
        local src = getSourceCARD()
        attack(player, src, 20, "ATKRES_NIL", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onLevelActionTrigger(player)
        recoverCard(player, "DECK_HAND", "RECOVER_MOB", "LESSER", 30)
    end

}
