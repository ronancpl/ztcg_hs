ZTCG_CARD
{

    "NAME" "Dark Scorpio"
    "IMAGE" "S2C032_DarkScorpio.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Armor"
    "COST" "830"

    TYPE_EQP
    {
        "LEVEL" "60"
        "TEXT" "When you would take more than 30 damage all at once take only 30 damage instead."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "3"
        "TEXT" "Crafty -- Play a Thief card of your level or less. "
    }

    function onBlockResultDamage(player)
        if getGameValue(0) > 30 then
            updateGameValue(0, 30)
        end
    end

   function onActivateCharacterAction(player)
        local str = "Crafty"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_THIEF", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", level)
    end


}
