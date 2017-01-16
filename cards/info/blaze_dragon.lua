ZTCG_CARD
{
    "NAME" "Blaze Dragon"
    "IMAGE" "blaze_dragon.png"
    "TYPE" "JRBOSS"
    "ELEMENT" "FIRE"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Fire - Jr. Boss - Dragon"
    "COST" "1500"

    TYPE_JRB
    {
        "LEVEL" "70"
        "ATTCK" "30"
        "HP" "120"

        LVL_ACTION
        {
            "TEXT" "Scorching Atmosphere - Blaze Dragons attacks becomes unpreventable, and can not be blocked (no drops on attack value)."
        }
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Summon / Equip 70 - Play a monster or an equipment of level 70 or less."
    }

    function onActivateCharacterAction(player)
        -- copypaste here the text which defines the card lvaction
        local str = "Summon / Equip 70 "
        playCard(player, str, "PLAY_MOB | PLAY_EQUIP", 70)
    end

    function onStartAttack(player)
        local src = getSourceCARD()
        local atkr = getCardPointer(0)

        if(isSameCARD(src, atkr)) then
            updateGameValue(0, "DISABLE_PREVENT")  -- Blaze Dragon's attacks are unpreventable (prevent: 0)
        end
    end

    function onOpponentCalcDefenseCard(player)
        local src = getSourceCARD()
        local atkr = getCardPointer(0)

        if(isSameCARD(src, atkr)) then
            return 1    -- opponent can not block attacks from Blaze Dragon
        end
    end

}
