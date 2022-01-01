ZTCG_CARD
{

    "NAME" "Rookie Knock-Back"
    "IMAGE" "S3C014_RookieKnockBack.png"
    "TYPE" "ACTION"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Skill"
    "COST" "640"

    TYPE_ACT
    {
        "LEVEL" "40"
        "TEXT" "Choose a monster. That monster can't attack your character next turn. Draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "10"
        "ATTRB" "1"
        "TEXT" "Spawn 20 -- Play a monster of level 20 or less."
    }

    function onThinkAction(player)
        local list, not_empty = makeFilteredTableList(player, "ONLY_ADVSRY", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")
        if not_empty then
            local menuCard = menuCards(player,list,"Select a monster to Stun for one turn.","CARDLIST_PEEK")
            local card = getCARD(menuCard)

            applyStun(player, card, 1)
        end
        destroyList(list)

        drawCard(player)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 20"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",20)
    end

}
