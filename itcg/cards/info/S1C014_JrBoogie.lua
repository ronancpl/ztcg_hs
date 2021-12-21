ZTCG_CARD
{

    "NAME" "Jr. Boogie"
    "IMAGE" "S1C014_JrBoogie.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Flying Spook"
    "COST" "560"

    TYPE_MOB
    {
        "LEVEL" "35"
        "ATTCK" "30"
        "HP" "30"
        "TEXT" "Stealthy -- Monsters can't attack Jr. Boogie."
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
