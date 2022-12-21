ZTCG_CARD
{

    "NAME" "Maple Soul Searcher"
    "IMAGE" "S2C011_MapleSoulSearcher.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Weapon"
    "COST" "700"

    TYPE_EQP
    {
        "LEVEL" "45"
        "TEXT" "Damage from your character actions can't be prevented."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Think Fast / Equip 40 -- Play a tactic or item of level 40 or less. "
    }

    function onStartAttack(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            updateGameValue(0,0)    -- can't be prevented
        end
    end

    function onActivateCharacterAction(player)
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 40)
    end

}
