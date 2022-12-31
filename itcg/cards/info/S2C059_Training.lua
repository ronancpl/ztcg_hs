ZTCG_CARD
{

    "NAME" "Training"
    "IMAGE" "S2C059_Training.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Strategy"
    "COST" "700"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "Level up with the top card of your deck."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Spawn 120 -- Play a monster of level 120 or less. "
    }

    function onThinkAction(player)
        local d = drawCard(player)
        if d then
            levelUpScout(player,false)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 120"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",120)
    end

}
