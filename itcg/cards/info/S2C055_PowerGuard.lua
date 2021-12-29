ZTCG_CARD
{

    "NAME" "Power Guard"
    "IMAGE" "S2C055_PowerGuard.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Skill"
    "COST" "730"

    TYPE_ACT
    {
        "LEVEL" "30"
        "TEXT" "Choose a monster and prevent all damages to it next turn."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "1"
        "TEXT" "Spawn / Think Fast 70 -- Play a monster or tactic of level 70 or less. "
    }

    function preventIntercomeTargetMob(player)
        local target = getTargetCARD()
        if target == getCardPointer(3) then
            return 1
        else
            return 0
        end
    end

    function onThinkAction(player)
        insertCardTurnAction(player)

        local list, not_empty = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
        if not_empty then
            local card = menuCards(player,list,"Select a card to prevent all damage to it.","CARDLIST_PEEK")
            if card ~= 0 then
                local preventMob = getCARD(card)
                setCardPointer(3, preventMob)
            end
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 70"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 70)
    end

}
