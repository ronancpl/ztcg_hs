ZTCG_CARD
{

    "NAME" "Psycho Jack"
    "IMAGE" "S5C051_PsychoJack.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Dark Toy"
    "COST" "730"

    TYPE_MOB
    {
        "LEVEL" "30"
        "ATTCK" "30"
        "HP" "20"
        "TEXT" "Loony -- When Psycho Jack is destroyed, if your opponent is higher level than you, he or she chooses a card under his or her character and destroys it."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Ketchup -- If your opponent is higher level than you, level up with the top card of your deck."
    }

    function onReceiveAttackAndSentToDiscardPile(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level1 = getCurrentLevelFromCARD(player,chr)

        local adv = getOnBoardCARD(not player, "SLOT_PLAYERCHAR")
        local level2 = getCurrentLevelFromCARD(not player,adv)

        if level1 < level2 then
            local cardList, qty = getListFromCharacterActions(not player, true)
            if qty > 0 then
                while true do
                    local card = menuCards(player,cardList,"Select a card to remove from your character actions.","CARDLIST_PEEK")
                    if card ~= 0 then
                        destroyCharacterAction(not player,getCARD(card),true)
                        break
                    end
                end
            end
        end
    end

    function onLevelActionTrigger(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level1 = getCurrentLevelFromCARD(player,chr)

        local adv = getOnBoardCARD(not player, "SLOT_PLAYERCHAR")
        local level2 = getCurrentLevelFromCARD(player,adv)

        if level1 < level2 then
            drawCard(player)
            levelUpScout(player)
        end
    end



}
