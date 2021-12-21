ZTCG_CARD
{

    "NAME" "Dark Shadow"
    "IMAGE" "S1C056_DarkShadow.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Armor"
    "COST" "650"

    TYPE_EQP
    {
        "LEVEL" "40"
        "TEXT" "Prevent 10 damage from each monster that attacks your character."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 70 -- Play a monster or item of level 70 or less. "
    }

    function onEquipBlockDamage(player)
        local target = getTargetCARD()
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") and  hasSharedFlagsCARD(target,"FLAG_TYPE","TYPE_CHAR") then
            return 10
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 70"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 70)
    end

}
