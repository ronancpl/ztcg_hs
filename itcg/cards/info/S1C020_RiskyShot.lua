ZTCG_CARD
{

    "NAME" "Risky Shot"
    "IMAGE" "S1C020_RiskyShot.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "630"

    TYPE_ACT
    {
        "LEVEL" "40"
        "TEXT" "Flip a coin. If you win, do damage equal to your level to a character and draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Think Fast / Equip 50 -- Play a tactic or item of level 50 or less. "
    }

    function onThinkAction(player)
        local res = throwCoin(player)
        if res then
            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            local level = getCurrentLevelFromCARD(player,chr)
            attack(player, chr, level, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")

            drawCard(player)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 50"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 50)
    end

}
