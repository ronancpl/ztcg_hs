ZTCG_CARD
{

    "NAME" "Blood Slain"
    "IMAGE" "S1C050_BloodSlain.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Weapon"
    "COST" "800"

    TYPE_EQP
    {
        "LEVEL" "50"
        "TEXT" "Whenever one of your character actions, monster attacks, or tactics does damage, it gets +10 damage."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "3"
        "TEXT" "Sneak X -- Play a card of your level or less. "
    }

    function onEquipBuff(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB | ATKSRC_CHA | ATKSRC_ACT") then
            return 10
        end
    end

    function onActivateCharacterAction(player)
        local str = "Sneak X"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", level)
    end

}
