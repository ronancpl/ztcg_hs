ZTCG_CARD
{

    "NAME" "Janitor's Mop"
    "IMAGE" "S2C008_JanitorsMop.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Weapon"
    "COST" "510"

    TYPE_EQP
    {
        "LEVEL" "25"
        "TEXT" "Whenever you play a monster, do 10 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "1"
        "TEXT" "Arrow Storm -- Choose a character or monster. Do 10 damage to it +10 for each Arrow Storm used already this turn. "
    }

    function onPlayMob(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_EQP", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
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
