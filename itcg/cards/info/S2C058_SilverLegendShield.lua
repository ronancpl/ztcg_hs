ZTCG_CARD
{

    "NAME" "Silver Legend Shield"
    "IMAGE" "S2C058_SilverLegendShield.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Armor"
    "COST" "780"

    TYPE_EQP
    {
        "LEVEL" "60"
        "TEXT" "Whenever one of your monsters is destroyed, level up with it."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Bloodthirsty -- Destroy a card under your character. If you do, one of your monsters that attacks this turn gets Fierce until end of turn. "
    }

    function onAttackMobDestroyed(player)
        local target = getTargetCARD()
        local card = makeTargetFromCARD(target)

        local grav = getPlayerDeck(player, "DECK_GRAV")
        local hand = getPlayerDeck(player, "DECK_HAND")
        local m = moveCards(player,grav,hand,"TAKE_CARDID","PUT_BOTTOM",card)
        if m > 0 then
            levelUpScout(player,false)
        end

        destroyList(card)
    end

    function onActivateCharacterAction(player)
        if getMobsOnTable(player,"ONLY_PLAYER") > 0 then
            if(makePrompt(player,true,"Use Bloodthirsty?","One of your monsters get Fierce.","ZTCG_NIL","ZTCG_NIL","Yes","No")) then
                local cards, list_sz = makeListFromCharacterActions(player, true)
                if list_sz > 0 then
                    local menuCard = menuCards(player,cards,"Select a card to remove from your character actions.","CARDLIST_PEEK")

                    if menuCard ~= 0 then
                        local card = getCARD(menuCard)
                        destroyCharacterAction(player,card,true)

                        local list, not_empty = makeFilteredTableList(player, "ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
                        if not_empty then
                            local card = menuCards(player,list,"Select a card to use Fierce.","CARDLIST_PEEK")
                            if card ~= 0 then
                                local src = getSourceCARD()
                                addExtraMobAttack(getCARD(card),src,2)
                            end
                        end
                        destroyList(list)
                    end
                end
                destroyList(cards)
            end
        end
    end

}
