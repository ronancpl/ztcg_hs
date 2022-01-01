ZTCG_CARD
{

    "NAME" "Invincible"
    "IMAGE" "S3C021_Invincible.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Skill"
    "COST" "800"

    TYPE_ACT
    {
        "LEVEL" "65"
        "TEXT" "Prevent the first 100 damage that would be done to your character next turn."
    }

    LVL_ACTION
    {
        "LEVEL" "90"
        "ATTRB" "3"
        "TEXT" "Think Fast Unlimited -- Play a tactic."
    }

    function onCalcDefenseCard(player)
        local def_card = getCardPointer(1)
        if(hasSharedFlagsCARD(def_card, "FLAG_TYPE", "TYPE_CHAR")) then
            local src = getSourceCARD()
            local cardid = getCardIdFromCARD(src)

            local dmgPrevent = getCardRegister(src, cardid, 0)
            updateGameValue(0, dmgPrevent)
        end
    end

    function onBlockResultDamage(player)
        local def_card = getCardPointer(1)
        if(hasSharedFlagsCARD(def_card, "FLAG_TYPE", "TYPE_CHAR")) then
            local src = getSourceCARD()
            local cardid = getCardIdFromCARD(src)

            local dmgPrevent = getCardRegister(src, cardid, 0)
            local dmg = getGameValue(1)

            if dmgPrevent > dmg then
                dmgPrevent = dmgPrevent - dmg
                editCardRegister(src, cardid, 0, dmgPrevent, 0, nil)
            else
                dmg = dmg - dmgPrevent
                editCardRegister(src, cardid, 0, 0, 0, nil)
            end
        end
    end

    function onThinkAction(player)
        insertCardTurnAction(player)

        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        editCardRegister(src, cardid, 0, 100, 0, null)
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast Unlimited"
        action(player,"ZTCG_NIL","ELEM_ANY","ZTCG_MAXVALUE")
    end

}
