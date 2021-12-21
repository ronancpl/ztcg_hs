ZTCG_CARD
{

    "NAME" "Krip"
    "IMAGE" "S1C061_Krip.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Water Shrimp"
    "COST" "590"

    TYPE_MOB
    {
        "LEVEL" "30"
        "ATTCK" "30"
        "HP" "20"
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Slash -- Do 20 damage to a character or monster. "
    }

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end


}
