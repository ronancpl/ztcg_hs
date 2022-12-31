ZTCG_CARD
{

    "NAME" "Cold Eye"
    "IMAGE" "S3C004_ColdEye.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Ice Worm"
    "COST" "680"

    TYPE_MOB
    {
        "LEVEL" "40"
        "ATTCK" "30"
        "HP" "30"
        "TEXT" "Ice Breath -- When you play Cold Eye, one of your opponent's monsters loses its abilities until your next turn starts. Do 20 damage to that monster."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn / Think Fast 60 -- Play a monster or tactic of level 60 or less."
    }

    function onThinkMob(player)
        local src = getSourceCARD()

        local list, not_empty = makeFilteredTableList(player, "ONLY_ADVSRY",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
        if not_empty then
            local card = menuCards(player,list,"Select a card to apply Silence.","CARDLIST_PEEK")
            if card ~= 0 then
                card = getCARD(card)
                local slotid = getSlotIdFromCARD(not player, card)

                applySilence(player,card,1)
                attack(player, src, 20, "ATKRES_FIXED_SLOT", "ATKSRC_MOB", "SLOT_ADVSRYMOB" .. slotid, "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
            end
        end
        destroyList(list)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 60"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 60)
    end

}
