ZTCG_CARD
{

    "NAME" "Final Attack : Bow"
    "IMAGE" "S2C006_FinalAttackBow.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Skill"
    "COST" "500"

    TYPE_ACT
    {
        "LEVEL" "20"
        "TEXT" "For each Bowman card under your character do 10 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "1"
        "TEXT" "Arrow Storm -- Choose a character or monster. Do 10 damage to it +10 for each Arrow Storm used already this turn. "
    }

    function onThinkAction(player)
        local src = getSourceCARD()

        local attr = getPlayerAttributes(player, "ELEM_BOWMAN")
        for i = 1, attr, 1 do
            attack(player, src, 10, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end
    end

    function onStartTurn(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local cardid = getCardIdFromCARD(card)
        editCardRegister(card, cardid, 5, 0, 0, 0)
    end

    function onActivateCharacterAction(player)
        local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local cardid = getCardIdFromCARD(card)

        local storm = getCardRegister(card, cardid, 5)
        attack(player, card, 10 + (10 * storm), "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        editCardRegister(card, cardid, 5, storm + 1, 0, 0)
    end

}
