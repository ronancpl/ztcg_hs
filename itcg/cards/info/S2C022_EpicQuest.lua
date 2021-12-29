ZTCG_CARD
{

    "NAME" "Epic Quest"
    "IMAGE" "S2C022_EpicQuest.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "690"

    TYPE_ACT
    {
        "LEVEL" "90"
        "TEXT" "Draw 3 cards."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Magician Prowess -- Play a Magician card of your level or less. "
    }

    function onThinkAction(player)
        for i = 1, 3, 1 do
            drawCard(player)
        end
    end

    function onLevelActionTrigger(player)
        local str = "Magician Prowess"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_MAGE", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", level)
    end

}
