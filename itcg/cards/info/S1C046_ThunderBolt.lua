ZTCG_CARD
{

    "NAME" "Thunder Bolt"
    "IMAGE" "S1C046_ThunderBolt.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Skill"
    "COST" "720"

    TYPE_ACT
    {
        "LEVEL" "60"
        "TEXT" "Do 50 damage to each of your opponent's monsters. Then do 50 damage to your opponent's character."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "3"
        "TEXT" "Blast -- Do 30 damage to a character. "
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        attack(player, src, 50, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB1", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 50, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB2", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 50, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB3", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 50, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB4", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 50, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB5", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 50, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB6", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 50, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYMOB7", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        attack(player, src, 50, "ATKRES_FIXED_SLOT", "ATKSRC_ACT", "SLOT_ADVSRYCHAR", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 30, "ATKRES_DONT_HIT_MOBS", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
