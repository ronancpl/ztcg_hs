ZTCG_CARD
{

    "NAME" "Tortie"
    "IMAGE" "S2C043_Tortie.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Turtle"
    "COST" "520"

    TYPE_MOB
    {
        "LEVEL" "46"
        "ATTCK" "30"
        "HP" "30"
        "TEXT" "Tough -- Character actions don't damage Tortie."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Rant -- Choose an action on a card under your opponent's character. Your opponent can't use that action next turn. "
    }

    function preventTargetMob(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            return 1
        else
            return 0
        end
    end

    function onLevelActionTrigger(player)
        skipOpponentCharacterAction(player, true)
    end

}
