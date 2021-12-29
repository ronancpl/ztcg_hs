ZTCG_CARD
{

    "NAME" "Chronos"
    "IMAGE" "S2C004_Chronos.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Flying Spook"
    "COST" "510"

    TYPE_MOB
    {
        "LEVEL" "37"
        "ATTCK" "40"
        "HP" "20"
        "TEXT" "Stealthy -- Monsters can't attack Chronos."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Bowman Prowess -- Play a Bowman card of your level or less. "
    }

    function preventTargetMob(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            return 1
        else
            return 0
        end
    end

    function onLevelActionTrigger(player)
        local str = "Bowman Prowess"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_BOWMAN", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", level)
    end

}
