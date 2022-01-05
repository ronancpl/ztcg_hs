ZTCG_CARD
{

    "NAME" "Blue Snail"
    "IMAGE" "S5C077_BlueSnail.png"
    "TYPE" "MOB"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Beginner Pest"
    "COST" "450"

    TYPE_MOB
    {
        "LEVEL" "2"
        "ATTCK" "10"
        "HP" "20"
    }

    LVL_ACTION
    {
        "LEVEL" "10"
        "ATTRB" "0"
        "TEXT" "Bash -- Do 10 damage to a character or monster."
    }

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
