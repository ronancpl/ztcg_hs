ZTCG_CARD
{

    "NAME" "Rain of Arrows"
    "IMAGE" "S1C019_RainOfArrows.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Strategy"
    "COST" "510"

    TYPE_ACT
    {
        "LEVEL" "40"
        "TEXT" "For each card in your opponent's hand, do 20 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Steady Hand -- If you're level 50 or more, get +10 damage you do with character actions until end of turn. "
    }

    function onThinkAction(player)
        local src = getSourceCARD()

        local deck = getPlayerDeck(not player, "DECK_HAND")
        local deckl, qty = getListFromDeck(deck)

        for i = 1, qty, 1 do
            attack(player,src,20,"ATKRES_NIL", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

    function onLevelActionTrigger(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        if level >= 50 then
            local src = getSourceCARD()
            incrementBuffEffect(player,src)
            newBuff(chr,src,10,0,0,1)
        end
    end


}
