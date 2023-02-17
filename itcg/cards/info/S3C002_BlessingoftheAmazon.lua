ZTCG_CARD
{

    "NAME" "Blessing of the Amazon"
    "IMAGE" "S3C002_BlessingoftheAmazon.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "580"

    TYPE_ACT
    {
        "LEVEL" "10"
        "TEXT" "Do 40 damage to a character or monster. This damage can't be prevented."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Perfect Aim -- Damage you do with character actions can't be prevented this turn."
    }

    function onStartAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") and getCardRegister(src, cid, 0) == 777 then
            updateGameValue(0,0)    -- can't be prevented
        end
    end

    function onThinkAction(player)
        local src = getSourceCARD()
        attack(player, src, 40, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "DISABLE_PREVENT", "IS_STARTER")
    end

    function onStartTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 0, 0, nil)
    end

    function onLevelActionTrigger(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 777, 0, nil)

        insertCardTurnAction(player)
    end

}
