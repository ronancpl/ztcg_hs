ZTCG_CARD
{

    "NAME" "Indigo"
    "IMAGE" "S2C007_Indigo.png"
    "TYPE" "CHAR"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Hunter"
    "COST" "800"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "1"
            "TEXT" "Bow Booster -- Get +20 on the next damage you do this turn."
        }
        LVL_ACTION
        {
            "LEVEL" "30"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card. "
        }
        LVL_ACTION
        {
            "LEVEL" "50"
            "ATTRB" "2"
            "TEXT" "Tricky Shot -- Do 20 damage to a character or monster. "
        }
        "HP" "210"
    }

    function onCalcAttackCard(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if(getCardRegister(src, cid, 0) == 10) then
            local dmg = getGameValue(0)
            local bonus = getCardRegister(src, cid, 1)
            updateGameValue(0, dmg + bonus)

            return 1    -- notices bonus from next tactic
        end
    end

    function onExecuteAttackCard(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if(getCardRegister(src, cid, 0) == 10) then
            editCardRegister(src, cid, 0, 0, 0, nil)

            return 1    -- finishes bonus from next tactic
        end
    end

    function onActivateCharacterAction1(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 10, 0, nil)
        editCardRegister(src, cid, 1, 20, 0, nil)
    end

    function onActivateCharacterAction2(player)
        drawCard(player)
    end

    function onActivateCharacterAction3(player)
        local src = getSourceCARD()
        attack(player, src, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
