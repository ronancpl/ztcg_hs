ZTCG_CARD
{

    "NAME" "Jr. Cerebes"
    "IMAGE" "S3C052_JrCerebes.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Dog"
    "COST" "720"

    TYPE_MOB
    {
        "LEVEL" "43"
        "ATTCK" "30"
        "HP" "50"
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Crush -- Do 20 damage to a monster."
    }

    function onLevelActionTrigger(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_DONT_HIT_CHAR", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end


}
