ZTCG_CARD
{

    "NAME" "King Clang"
    "IMAGE" "S5C046_KingClang.png"
    "TYPE" "BOSS"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Boss"
    "COST" "780"

    TYPE_BOS
    {
        "HP" "100"
        "ATTCK" "30"
        "LEVEL" "55"
        LVL_ACTION
        {
            "LEVEL" "0"
            "ATTRB" "0"
            "TEXT" "Super Tough -- All of your monsters are Tough. (They can't be damaged by character actions.)"
        }
        LVL_ACTION
        {
            "LEVEL" "60"
            "ATTRB" "2"
            "TEXT" "Pinch -- Your opponent chooses a card from his or her hand and discards it."
        }
    }

    function preventIntercomeTargetMob(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            return 1
        else
            return 0
        end
    end

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(not matchRequirements(player, 60, 2, "ELEM_THIEF")) then return end

        discardCard(not player)
    end

}
