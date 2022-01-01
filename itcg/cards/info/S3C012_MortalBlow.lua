ZTCG_CARD
{

    "NAME" "Mortal Blow"
    "IMAGE" "S3C012_MortalBlow.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Skill"
    "COST" "750"

    TYPE_ACT
    {
        "LEVEL" "90"
        "TEXT" "When your turn ends, do damage to your opponent's character equal to the total damage he or she took this turn."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "1"
        "TEXT" "Spawn / Equip 90 -- Play a monster or item of level 90 or less."
    }

    function onExecuteAttackAndSurvived(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local atkr = getCardPointer(1)
        if hasSharedFlagsCARD(atkr, "FLAG_TYPE", "TYPE_CHAR") then
           local dmg = getCardRegister(src, cid, 0)
            editCardRegister(src, cid, 0, dmg + getGameValue(0), 0, nil)
        end
    end

    function onEndTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local dmg = getCardRegister(src, cid, 0)
        local src = getSourceCARD()

        attack(player, src, dmg, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        editCardRegister(src, cid, 0, 0, 0, nil)
    end

    function onThinkAction(player)
        insertCardTurnAction(player)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 90"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 90)
    end

}
