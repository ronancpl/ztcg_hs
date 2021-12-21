ZTCG_CARD
{

    "NAME" "Doombringer"
    "IMAGE" "S1C075_Doombringer.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Weapon"
    "COST" "750"

    TYPE_EQP
    {
        "LEVEL" "70"
        "TEXT" "Get +30 damage you do with each of your character actions."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "3"
        "TEXT" "Roar -- For each monster you have, do 20 damage to a character or monster. "
    }

    function onEquipBuff(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            return 30
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        for i = 1, getMobsOnTable(player,"ONLY_PLAYER"), 1 do
            attack(player, chr, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end
    end


}
