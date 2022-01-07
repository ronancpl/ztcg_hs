ZTCG_CARD
{

    "NAME" "Chirppy"
    "IMAGE" "S3C003_Chirppy.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Flying Bird"
    "COST" "600"

    TYPE_MOB
    {
        "LEVEL" "31"
        "ATTCK" "20"
        "HP" "40"
        "TEXT" "Stealthy -- Monsters can't attack Chirppy."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "2"
        "TEXT" "Easy Shot -- Do 10 damage to a character or monster."
    }

    function preventTargetMob(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") then
            return 1
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
