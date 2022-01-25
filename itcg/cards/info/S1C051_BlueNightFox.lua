ZTCG_CARD
{

    "NAME" "Blue NightFox"
    "IMAGE" "S1C051_BlueNightfox.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Armor"
    "COST" "780"

    TYPE_EQP
    {
        "LEVEL" "70"
        "TEXT" "Your opponent's monsters can't attack on the turn they're played."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "3"
        "TEXT" "Crafty -- Play a thief card of your level or less. "
    }

    function onOpponentPlayMob(player)
        local target = getTargetCARD()
        applyStun(player,target,1)
    end

    function onActivateCharacterAction(player)
        local str = "Crafty"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_THIEF", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", level)
    end

}
