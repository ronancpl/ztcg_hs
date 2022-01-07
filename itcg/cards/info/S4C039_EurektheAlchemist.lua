ZTCG_CARD
{

    "NAME" "Eurek the Alchemist"
    "IMAGE" "S4C039_EurektheAlchemist.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Human NPC"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "40"
        "ATTCK" "30"
        "HP" "30"
        "TEXT" "NPC Quest -- You have an item when your turn ends. Reward -- Do 30 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "3"
        "TEXT" "Master Equip X -- Play an item of your level or less. If you have 4 or more items, do 30 damage to a character."
    }

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY",level)

        if getEquipsOnTable(player,"ONLY_PLAYER") >= 4 then
            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            attack(player, chr, 30, "ATKRES_DONT_HIT_MOBS", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end
    end

}
