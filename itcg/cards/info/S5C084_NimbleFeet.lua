ZTCG_CARD
{

    "NAME" "Nimble Feet"
    "IMAGE" "S5C084_NimbleFeet.png"
    "TYPE" "ACTION"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_COMMON"
    "INFO" "Tactic - Beginner Skill"
    "COST" "630"

    TYPE_ACT
    {
        "LEVEL" "10"
        "TEXT" "Prevent the first 20 damage that would be done to you and to each of your monsters next turn. Clash with your opponent. If you win, draw a card. (To clash, each player reveals the top card of their deck, then puts it on top or bottom. Whoever revealed the highest-level card wins.)"
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "0"
        "TEXT" "Flee -- Clash with your opponent. If you win, draw a card. If you lose, discard your hand."
    }

    function onCalcDefenseCard(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local dmgPrevent = getCardRegister(src, cardid, 0)
        updateGameValue(0, dmgPrevent)
    end

    function onBlockResultDamage(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        local dmgPrevent = getCardRegister(src, cardid, 0)
        local dmg = getGameValue(1)

        if dmgPrevent > dmg then
            dmgPrevent = dmgPrevent - dmg
            editCardRegister(src, cardid, 0, dmgPrevent, 0, nil)
        else
            dmg = dmg - dmgPrevent
            editCardRegister(src, cardid, 0, 0, 0, nil)
        end
    end

    function onThinkAction(player)
        insertCardTurnAction(player)

        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        editCardRegister(src, cardid, 0, 20, 0, nil)

        if playClash(player) then
            drawCard(player)
        end
    end

    function onActivateCharacterAction(player)
        if(not makePrompt(player,"Use Flee?","Avoid using Clash to chance draw a card into discard your cards.","ZTCG_NIL","ZTCG_NIL","Yes","No")) then
            local deck = getPlayerDeck(player, "DECK_DECK")
            local hand = getPlayerDeck(player, "DECK_HAND")

            if playClash(player) then
                drawCard(player)
            else
                moveCards(deck_hand,deck_grav,"TAKE_NEXT","PUT_TOP","ZTCG_MAXVALUE")
            end
        end
    end

}
