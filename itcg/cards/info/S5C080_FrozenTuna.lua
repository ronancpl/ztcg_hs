ZTCG_CARD
{

    "NAME" "Frozen Tuna"
    "IMAGE" "S5C080_FrozenTuna.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Beginner Ice Weapon"
    "COST" "650"

    TYPE_EQP
    {
        "LEVEL" "20"
        "TEXT" "When you finish doing your character actions each turn, do 10 damage to a character or monster +10 If you played a Jobless card this turn."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "0"
        "TEXT" "Think Fast / Equip 50 -- Play a tactic or item of level 50 or less."
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        editCardRegister(src, cardid, 0, 0, 0, nil)
    end

    function onPlayCard(player)
        local target = getTargetCARD()
        if(hasSharedFlagsCARD(target, "FLAG_ELEM", "ELEM_JOBLESS")) then
            local src = getSourceCARD()
            local cardid = getCardIdFromCARD(src)
            editCardRegister(src, cardid, 0, 1, 0, nil)
        end
    end

    function afterCharacterActions(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local dmg = 10
        if getCardRegister(src, cardid, 0) ~= 0 then
            dmg = dmg + 10
        end

        attack(player, src, dmg, "ATKRES_NIL", "ATKSRC_EQP", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 50"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 50)
    end

}
