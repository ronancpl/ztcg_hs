ZTCG_CARD
{

    "NAME" "Starblade"
    "IMAGE" "S1C091_Starblade.png"
    "TYPE" "CHAR"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Fighter"
    "COST" "880"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "1"
            "TEXT" "Bash -- Do 10 damage to a character or monster."
        }
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card. "
        }
        LVL_ACTION
        {
            "LEVEL" "50"
            "ATTRB" "2"
            "TEXT" "Buff -- Monsters that attack this turn each get +20 attack until end of turn. "
        }
        "HP" "260"
    }

    function onActivateCharacterAction1(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction2(player)
        drawCard(player)
    end

    function onActivateCharacterAction3(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        -- action buff
        editCardRegister(src, cid, 0, 10, 0, nil)
        incrementBuffEffect(player,src)
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        if(getCardRegister(src, cid, 0) ~= 10 or not matchRequirements(player, 50, 2, "ELEM_WARRIOR")) then return end

        removeAuraBonus(player,"GLOBALAURA_PASS_ADVSRY",src,20,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        if(getCardRegister(src, cid, 0) ~= 10 or not matchRequirements(player, 50, 2, "ELEM_WARRIOR")) then return end

        applyAuraBonus(player,"GLOBALAURA_PASS_ADVSRY","BUFF_ANY",src,20,0,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
    end

}
