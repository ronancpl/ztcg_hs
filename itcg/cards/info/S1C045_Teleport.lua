ZTCG_CARD
{

    "NAME" "Teleport"
    "IMAGE" "S1C045_Teleport.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Skill"
    "COST" "700"

    TYPE_ACT
    {
        "LEVEL" "50"
        "TEXT" "Next turn, monsters can't attack your character."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Jump Quest -- If you're level 70 or more, draw 2 cards. "
    }

    function onOpponentStartAttack(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            local res = getGameValue(2)     -- no target if already cannot hit mobs
            if res >= 2 then
                updateGameValue(2, "ATKRES_NO_TARGET")
            else
                updateGameValue(2, "ATKRES_DONT_HIT_CHAR")
            end
        end
    end

    function onThinkAction(player)
        insertCardTurnAction(player)    -- extended pointcut reach, like in "when something else occurs"
    end

    function onLevelActionTrigger(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        if level >= 70 then
            drawCard(player)
            drawCard(player)
        end
    end

}
