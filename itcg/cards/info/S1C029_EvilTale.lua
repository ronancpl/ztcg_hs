ZTCG_CARD
{

    "NAME" "Evil Tale"
    "IMAGE" "S1C029_EvilTale.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Wand"
    "COST" "810"

    TYPE_EQP
    {
        "LEVEL" "58"
        "TEXT" "Whenever you play a tactic, do 30 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Think Fast / Equip 70 -- Play a tactic or item of level 70 or less. "
    }

    function onPlayAction(player)
        local src = getSourceCARD()
        attack(player, src, 30, "ATKRES_NIL", "ATKSRC_EQP", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 70"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 70)
    end

}
