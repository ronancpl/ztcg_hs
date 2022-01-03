ZTCG_CARD
{

    "NAME" "Nightghost"
    "IMAGE" "S4C009_Nightghost.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Flying Undead Spook"
    "COST" "670"

    TYPE_MOB
    {
        "LEVEL" "60"
        "ATTCK" "40"
        "HP" "30"
        "TEXT" "Stealthy -- Monsters can't attack Nightghost."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Think Fast 90 -- Play a tactic of level 90 or less."
    }

    function preventTargetMob(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            return 1
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast 90"
        action(player,"ZTCG_NIL","ELEM_ANY",90)
    end


}
