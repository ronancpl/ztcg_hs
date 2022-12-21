ZTCG_CARD
{

    "NAME" "Wooden Target Dummy"
    "IMAGE" "S4C014_WoodenTargetDummy.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Dummy"
    "COST" "790"

    TYPE_MOB
    {
        "LEVEL" "51"
        "ATTCK" "0"
        "HP" "100"
        "TEXT" "Shield 100 -- Wooden Target Dummy prevents 100 damage to your character instead of 10. Immobile -- Wooden Target Dummy can't attack."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "1"
        "TEXT" "Spawn 100 -- Play a monster of level 100 or less."
    }

    function preventSelfTargetCharacter(player)
        return 1
    end

    function preventSelfTargetMob(player)
        return 1
    end

    function onCalcDefenseCard(player)
        local def_card = getCardPointer(1)
        if(hasSharedFlagsCARD(def_card, "FLAG_TYPE", "TYPE_CHAR")) then
            local src = getSourceCARD()
            local cardid = getCardIdFromCARD(src)

            local dmgPrevent = getGameValue(0) + 90
            updateGameValue(0, dmgPrevent)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 100"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",100)
    end

}
