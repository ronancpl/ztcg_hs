ZTCG_CARD
{

    "NAME" "Avenger"
    "IMAGE" "S1C049_Avenger.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Skill"
    "COST" "540"

    TYPE_ACT
    {
        "LEVEL" "70"
        "TEXT" "Destroy up to 3 monsters. Draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "1"
        "TEXT" "Think Fast 90 -- Play a tactic of level 90 or less. "
    }

    function onThinkAction(player)
        local c = 3
        while (c > 0 and getMobsOnTable(player,"ONLY_ADVSRY") > 0) do
            destroyMonster(player)
            c = c - 1
        end
        drawCard(player)
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast 90"
        action(player,"ZTCG_NIL","ELEM_ANY",90)
    end


}
