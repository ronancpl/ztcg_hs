ZTCG_CARD
{

    "NAME" "Lucida"
    "IMAGE" "S1C034_Lucida.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Dark Kitty"
    "COST" "750"

    TYPE_MOB
    {
        "LEVEL" "73"
        "ATTCK" "60"
        "HP" "90"
        "TEXT" "Wicked -- Whenever you get +HP, do that damage to your opponent's character."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Conjure -- Return another Magician card from under your character to your hand. "
    }

    function onRefreshCard(player)
        local attacker = getSourceCARD()
        local dmg = getGameValue(0)

        if dmg > 0 then
            attack(player, attacker, dmg, "ATKRES_DONT_HIT_MOBS", "ATKSRC_MOB", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

    function onLevelActionTrigger(player)
        local list, list_sz = makeListFromCharacterActions(player, true, false)
        if list_sz > 0 then
            local mg_list = makeFilteredList(player,list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_MAGE","ZTCG_NIL")
            local target = makeTargetFromCARD(getSourceCARD())
            if target ~= 0 then
                mg_list = takeTargetCardFromList(target,mg_list)
            end
            destroyList(target)

            if not isEmptyList(mg_list) then
                while true do
                    local menuCard = menuCards(player,mg_list,"Select a card to draw.","CARDLIST_PEEK")
                    if menuCard ~= 0 then
                        local card = getCARD(menuCard)
                        local src = getSourceCARD()
                        if card ~= src then
                            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
                            local level = getCurrentLevelFromCARD(player,chr)

                            destroyCharacterAction(player,card,true)
                            recoverDestroyedCard(player,card)
                        end

                         break
                    end
                end
            end

            destroyList(mg_list)
        end

        destroyList(list)
    end

}
