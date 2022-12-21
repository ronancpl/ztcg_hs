ZTCG_CARD
{

    "NAME" "Metal Wand"
    "IMAGE" "S4C026_MetalWand.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Wand"
    "COST" "650"

    TYPE_EQP
    {
        "LEVEL" "18"
        "TEXT" "Whenever you play a tactic, do 10 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Think Fast / Equip 40 -- Play a tactic or item of level 40 or less."
    }

    function onPlayAction(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_EQP", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 40"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 40)
    end

}
