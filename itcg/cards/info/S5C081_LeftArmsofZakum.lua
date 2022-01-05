ZTCG_CARD
{

    "NAME" "Left Arms of Zakum"
    "IMAGE" "S5C081_LeftArmsofZakum.png"
    "TYPE" "MOB"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Zakum Arms"
    "COST" "720"

    TYPE_MOB
    {
        "LEVEL" "80"
        "ATTCK" "50"
        "HP" "80"
        "TEXT" "Zeal 50 -- When your turn ends, choose a character or Boss. That character or Boss gets +50 HP, but can't go over it's starting HP with Zeal."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "0"
        "TEXT" "Zpawn -- Play a monster of level 60 or less, or play a Zakum card of level 90 or less."
    }

    function onActivateMobEffect(player)
        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end

        local list, not_empty = makeFilteredTableList(player,"PLAYER_ONLY",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_CHA | TYPE_JRB | TYPE_BOS","ELEM_ANY","ZTCG_NIL")
        local card = menuCards(player,list,"Select a card for Zeal.","CARDLIST_PEEK")
        if card ~= 0 then
            refreshHP(player,getCARD(card),50)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 60"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",60)
    end

}
