ZTCG_CARD
{

    "NAME" "Savage Blow"
    "IMAGE" "S2C040_SavageBlow.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "580"

    TYPE_ACT
    {
        "LEVEL" "40"
        "TEXT" "Choose one: Destroy a monster, or your opponent chooses and discards a card from his or her hand."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "2"
        "TEXT" "Spawn 110 -- Play a monster of level 110 or less. "
    }

    function onThinkAction(player)
        if(makePrompt(player,"Select one:","ZTCG_NIL","ZTCG_NIL","ZTCG_NIL","Destroy monster","Opponent discard")) then
            destroyMonster(player)
        else
            discardCard(not player)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 110"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",110)
    end

}
