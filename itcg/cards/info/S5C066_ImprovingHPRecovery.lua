ZTCG_CARD
{

    "NAME" "Improving HP Recovery"
    "IMAGE" "S5C066_ImprovingHPRecovery.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Strategy"
    "COST" "700"

    TYPE_ACT
    {
        "LEVEL" "20"
        "TEXT" "Whenever a monster does damage this turn, you get that much +HP."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Nap -- You get +40 HP."
    }

    function onExecuteAttackCard(player)
        if hasFlag("ZTCG_ATKSRC","ATKSRC_MOB") then
            local dmg = getGameValue(0)

            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            refreshHP(player,chr,dmg)
        end
    end

    function onReceiveAttackCard(player)
        if hasFlag("ZTCG_ATKSRC","ATKSRC_MOB") then
            local dmg = getGameValue(0)

            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            refreshHP(player,chr,dmg)
        end
    end

    function onThinkAction(player)
        insertCardTurnAction(player)
    end

    function onLevelActionTrigger(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,chr,40)
    end

}
