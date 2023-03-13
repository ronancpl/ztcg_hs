ZTCG_CARD
{

    "NAME" "Bruno"
    "IMAGE" "S2C046_Bruno.png"
    "TYPE" "CHAR"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Spearman"
    "COST" "700"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "1"
            "TEXT" "Bash -- Do 10 damage to a character or monster."
        }
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card. "
        }
        LVL_ACTION
        {
            "LEVEL" "50"
            "ATTRB" "3"
            "TEXT" "Bloodthirsty -- Destroy a card under your character. If you do , one of your monsters that attacks this turn gets Fierce until end of turn. "
        }
        "HP" "220"
    }

    function onActivateCharacterAction1(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction2(player)
        drawCard(player)
    end

    function onActivateCharacterAction3(player)
        if getMobsOnTable(player,"ONLY_PLAYER") > 0 then
            if(makePrompt(player,true,"Use Bloodthirsty?","One of your monsters get Fierce.","ZTCG_NIL","ZTCG_NIL","Yes","No")) then
                local cards, list_sz = makeListFromCharacterActions(player, true, false)
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
