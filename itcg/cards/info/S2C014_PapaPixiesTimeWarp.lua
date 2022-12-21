ZTCG_CARD
{

    "NAME" "Papa Pixie's Time Warp"
    "IMAGE" "S2C014_PapaPixiesTimeWarp.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "700"

    TYPE_ACT
    {
        "LEVEL" "90"
        "TEXT" "You may do each of your character actions at the top and working your way done. When you're done, resume your turn. You can't play more than one Papa Pixie's Time Warp each turn."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "3"
        "TEXT" "Spawn / Think Fast 100 -- Play a monster or tactic of level 100 or less. "
    }

    function onThinkAction(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local cardid = getCardIdFromCARD(card)

        if getCardRegister(card, cardid, 6) == 0 then
            editCardRegister(card, cardid, 6, 1, 0, 0)
            insertCardTurnAction(player)

            characterActions(player)
        end
    end

    function onEndTurn(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local cardid = getCardIdFromCARD(card)

        editCardRegister(card, cardid, 6, 0, 0, 0)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 100"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 100)
    end

}
