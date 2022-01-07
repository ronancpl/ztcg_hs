ZTCG_CARD
{

    "NAME" "Griffey"
    "IMAGE" "S5C064_Griffey.png"
    "TYPE" "BOSS"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Boss"
    "COST" "810"

    TYPE_BOS
    {
        "HP" "180"
        "ATTCK" "80"
        "LEVEL" "105"
        LVL_ACTION
        {
            "LEVEL" "60"
            "ATTRB" "2"
            "TEXT" "Uni Horn -- Discard a card from your hand. If you do, add the discarded card's level, rounded up to the nearest 10, to Griffey's attack this turn and draw a card."
        }
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        editCardRegister(src,cardid,1,0,0,nil)
    end

    function onCalcAttack(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local dmg = getGameValue(0)
        local add = getCardRegister(src,cardid,1)
        updateGameValue(0,dmg + add)
    end

    function onActivateMobEffect(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        if (not hasFlag("ZTCG_PLAYERTYPE","IS_PLAYER")) then return end
        if(not matchRequirements(player, 60, 2, "ELEM_MAGE")) then return end

        local hand = getPlayerDeck(player, "DECK_HAND")
        local list, qty = getListFromDeck(hand)
        if qty > 0 then
            if(not makePrompt(player,"Use Uni Horn?","Discard a card to convert its level to Griffey's attack.","ZTCG_NIL","ZTCG_NIL","Yes","No")) then return end

            local card = discardCard(player)
            if card ~= 0 then
                local level = getCurrentLevelFromCARD(player,card)
                editCardRegister(src,cardid,1,getRoundedNearest(level),0,nil)

                drawCard(player)
            end
        end
    end

}
