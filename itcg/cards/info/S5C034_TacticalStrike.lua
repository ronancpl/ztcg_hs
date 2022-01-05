ZTCG_CARD
{

    "NAME" "Tactical Strike"
    "IMAGE" "S5C034_TacticalStrike.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "810"

    TYPE_ACT
    {
        "LEVEL" "80"
        "TEXT" "Do damage equal to 10 times the number of Magician cards under your character to each of your opponent's monsters. Then do that much damage to a character."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "3"
        "TEXT" "Magic Force -- Do 40 damage to a character."
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        local attr = getPlayerAttributes(PLAYER, "ELEM_MAGE")

        attack(player, src, 10 * attr, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB1", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10 * attr, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB2", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10 * attr, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB3", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10 * attr, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB4", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10 * attr, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB5", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10 * attr, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB6", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10 * attr, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB7", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 10 * attr, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYCHAR", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        attack(player, src, 40, "ATKRES_DONT_HIT_MOBS", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
