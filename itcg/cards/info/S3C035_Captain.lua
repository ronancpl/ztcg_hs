ZTCG_CARD
{

    "NAME" "Captain"
    "IMAGE" "S3C035_Captain.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Water Scoundrel"
    "COST" "800"

    TYPE_MOB
    {
        "LEVEL" "70"
        "ATTCK" "70"
        "HP" "40"
        "TEXT" "Tough -- Character actions don't damage Captain."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Slash -- Do 20 damage to a character or monster."
    }

    function preventTargetMob(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            return 1
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
