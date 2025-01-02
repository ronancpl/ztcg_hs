ZTCG_CARD
{

    "NAME" "Boosted Heal"
    "IMAGE" "S2C021_BoostedHeal.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Skill"
    "COST" "560"

    TYPE_ACT
    {
        "LEVEL" "35"
        "TEXT" "For each Magician card under your character, you get +20 HP. You can't go over your starting HP with Boosted Heal."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Think Fast 70 -- Play a tactic of level 70 or less. "
    }

    function onThinkAction(player)
        local attr = getPlayerAttributes(player, "ELEM_MAGE")

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,chr,attr * 20)
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast 70"
        action(player,"ZTCG_NIL","ELEM_ANY",70)
    end

}
