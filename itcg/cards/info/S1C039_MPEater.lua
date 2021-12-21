ZTCG_CARD
{

    "NAME" "MP Eater"
    "IMAGE" "S1C039_MPEater.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Skill"
    "COST" "620"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "Until the start of your next turn, your opponent's monsters lose their abilities. Do 50 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Jumble -- Swap the position of this card with another card under your character. "
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        attack(player,src, 50, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")

        applyGlobalSilence(player)
    end

    function onLevelActionTrigger(player)
        local cardA = getSourceCARD()

        local cards = getListFromCharacterActions(player, true)
        local cardB = menuCards(player,cards,"Select a card to swap its character action.","CARDLIST_PEEK")

        if cardB ~= 0 then
            swapCharacterActions(player, cardA, getCARD(cardB))
        end

        destroyList(cards)
    end


}
