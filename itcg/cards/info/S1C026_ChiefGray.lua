ZTCG_CARD
{

    "NAME" "Chief Gray"
    "IMAGE" "S1C026_ChiefGray.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Alien"
    "COST" "600"

    TYPE_MOB
    {
        "LEVEL" "49"
        "ATTCK" "10"
        "HP" "30"
        "TEXT" "Super Genius -- When you play Chief Gray, reveal the top card of your deck. If it's a tactic, you may play it. If you don't play it, or if it's not a tactic, put it into your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Quest -- Draw a card. "
    }

    function onThinkMob(player)
        local card = peekNextCard(player)

        drawCard(player)
        revealCard(not player,"Opponent has drawn card...",card)

        if(hasSharedFlagsCARD(card, "FLAG_TYPE", "TYPE_ACT")) then
            if(makePrompt(player,true,"Use " .. getNameFromCARD(card) .. "?","ZTCG_NIL","ZTCG_NIL","ZTCG_NIL","OK","Cancel")) then
                action(player,card,"ELEM_ANY","ZTCG_MAXVALUE")
            end
        end
    end

    function onLevelActionTrigger(player)
        drawCard(player)
    end

}
