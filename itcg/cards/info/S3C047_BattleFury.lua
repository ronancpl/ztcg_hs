ZTCG_CARD
{

    "NAME" "Battle Fury"
    "IMAGE" "S3C047_BattleFury.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Strategy"
    "COST" "770"

    TYPE_ACT
    {
        "LEVEL" "20"
        "TEXT" "One of your monsters gets Fierce this turn. (It attacks twice this turn.)"
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Think Fast / Equip 50 -- Play a tactic of level 50 or less."
    }

    function onThinkAction(player)
        local moblist, not_empty = makeFilteredTableList(player, "ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")

        if not_empty then
            local chosen = menuCards(player,moblist,"Select a monster to get Fierce.", "ZTCG_PEEK")

            if chosen ~= 0 then
                local card = getCARD(chosen)
                local src = getSourceCARD()
                addExtraMobAttack(card,src,2)
            end
        end

        destroyList(moblist)
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 50"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 50)
    end

}
