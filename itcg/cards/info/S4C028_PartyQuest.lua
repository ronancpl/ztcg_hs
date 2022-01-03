ZTCG_CARD
{

    "NAME" "Party Quest"
    "IMAGE" "S4C028_PartyQuest.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Strategy"
    "COST" "750"

    TYPE_ACT
    {
        "LEVEL" "50"
        "TEXT" "For each monster you have, draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Quest -- Draw a card."
    }

    function onThinkAction(player)
        local c = getMobsOnTable(player,"ONLY_PLAYER")
        for i = 1, c, 1 do
            drawCard(player)
        end
    end

    function onLevelActionTrigger(player)
        drawCard(player)
    end

}
