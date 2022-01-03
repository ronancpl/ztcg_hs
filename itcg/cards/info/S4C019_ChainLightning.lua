ZTCG_CARD
{

    "NAME" "Chain Lightning"
    "IMAGE" "S4C019_ChainLightning.png"
    "TYPE" "ACTION"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Tactic - Skill"
    "COST" "740"

    TYPE_ACT
    {
        "LEVEL" "60"
        "TEXT" "Choose 3 different characters and/or monsters. Do 60 damage to the first, then do 40 damage to the second, then do 20 damage to the third."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "2"
        "TEXT" "Scorch -- Do 20 damage to a character."
    }

    function onThinkAction(player)
        local list, not_empty = makeFilteredTableList(player,"ONLY_ADVSRY",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_CHAR | TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")

        local dmg = 60
        while dmg > 0 and getListLength(list) > 0 do
            local menuCard = menuCards(player,list,"Select a monster to apply Chain Lightning (damage: " .. tostring(dmg) .. " ).","CARDLIST_PEEK")
            if menuCard ~= 0 then
                local slotid = getSlotIdFromCARD(player, getCARD(menuCard))
                list = takeTargetCardFromList(menuCard,list)

                dmg = dmg - 20
            end
        end

        destroyList(list)
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        attack(player, src, 20, "ATKRES_DONT_HIT_MOBS", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end


}
