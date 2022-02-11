ZTCG_CARD
{

    "NAME" "Seal"
    "IMAGE" "S3C027_Seal.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Skill"
    "COST" "670"

    TYPE_ACT
    {
        "LEVEL" "40"
        "TEXT" "Remove a monster from the game until your next turn starts."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "1"
        "TEXT" "Think Fast / Equip 90 -- Play a tactic or item of level 90 or less."
    }

    function onThinkAction(player)
        local card = getOnBoardCARD(player, "SLOT_ADVSRYCHAR")
        local src = getSourceCARD()

        local list, not_empty = makeFilteredTableList(player, "ONLY_ADVSRY",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
        if not_empty then
            local card = menuCards(player,list,"Select a card to take from table.","CARDLIST_PEEK")
            if card ~= 0 then
                applyAway(player,getCARD(card),1)
            end
        end

        destroyList(list)
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 90"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 90)
    end

}
