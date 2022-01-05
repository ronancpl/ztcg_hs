ZTCG_CARD
{

    "NAME" "Left Behind"
    "IMAGE" "S5C047_LeftBehind.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Strategy"
    "COST" "640"

    TYPE_ACT
    {
        "LEVEL" "10"
        "TEXT" "Your opponent chooses and destroys one of his or her monsters."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Stab -- Do 10 damage to a character or monster."
    }

    function onThinkAction(player)
        local list, not_empty = makeFilteredTableList(player,"ONLY_ADVSRY",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
        if not_empty then
            while true do
                local card = menuCards(not player,list,"Select one of your mobs to destroy.","CARDLIST_PEEK")
                if card ~= 0 then
                    local slotid = getSlotIdFromCARD(not player, getCARD(card))
                    destroySelf(player,"SLOT_ADVSRYMOB" .. slotid)

                    break
                end
            end
        end

        destroyList(list)
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
