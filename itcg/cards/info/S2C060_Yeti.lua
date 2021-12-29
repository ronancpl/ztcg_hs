ZTCG_CARD
{

    "NAME" "Yeti"
    "IMAGE" "S2C060_Yeti.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Ice Beast"
    "COST" "730"

    TYPE_MOB
    {
        "LEVEL" "70"
        "ATTCK" "40"
        "HP" "70"
        "TEXT" "Ground Pound -- Yeti gets +40 attack if you didn't play it this turn."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 80 -- Play a monster or item of level 80 or less. "
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src, cid, 0, 1, 0, nil)
    end

    function onCalcAttack(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if getCardRegister(src, cid, 0) > 0 then   -- only after the turn spawn
            local dmg = getGameValue(0)
            updateGameValue(0, dmg + 40)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 80"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 80)
    end

}
