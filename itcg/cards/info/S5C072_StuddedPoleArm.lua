ZTCG_CARD
{

    "NAME" "Studded Pole Arm"
    "IMAGE" "S5C072_StuddedPoleArm.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Weapon"
    "COST" "630"

    TYPE_EQP
    {
        "LEVEL" "20"
        "TEXT" "Each of your monsters gets +10 attack."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 70 -- Play a monster or tiem of level 70 or less."
    }

    function onEquipBuff(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            return 10   -- any move from mobs apply equip bonus
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 70"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 70)
    end

}
