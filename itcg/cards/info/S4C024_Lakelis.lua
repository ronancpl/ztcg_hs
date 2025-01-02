ZTCG_CARD
{

    "NAME" "Lakelis"
    "IMAGE" "S4C024_Lakelis.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Human NPC"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "30"
        "ATTCK" "30"
        "HP" "20"
        "TEXT" "NPC Quest -- You have a Boss when your turn ends. Reward -- Draw a card for each Boss that each player has."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "1"
        "TEXT" "Spawn 100 -- Play a monster of level 100 or less."
    }

    function onEndTurn(player)
        if isBossOnPlayerTable(player) then
            local c = isBossOnPlayerTable(not player) and 2 or 1
            for i = 1, c, 1 do
                drawCard(player)
            end
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 100"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",100)
    end

}
