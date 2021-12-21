ZTCG_CARD
{

    "NAME" "Platoon Chronos"
    "IMAGE" "S1C017_PlatoonChronos.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Undead Spook"
    "COST" "500"

    TYPE_MOB
    {
        "LEVEL" "41"
        "ATTCK" "30"
        "HP" "40"
        "TEXT" "Stealthy -- Monsters can't attack Platoon Chronos."
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

    function onLevelActionTrigger(player)
        recoverCard(player, "DECK_HAND", "RECOVER_MOB", "LESSER", 30)
    end

}
