ZTCG_CARD
{

    "NAME" "Aggro"
    "IMAGE" "S5C055_Aggro.png"
    "TYPE" "ACTION"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "480"

    TYPE_ACT
    {
        "LEVEL" "40"
        "TEXT" "Reveal a monster card from your hand. Play it unless your opponent chooses to take 40 damage. If he or she does, keep that card revealed and you may reveal another monster card from your hand and repeat this process. When you're done, return the unplayed revealed cards to your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Spawn 110 -- Play a monster of level 110 or less."
    }

    function onThinkAction(player)
        local src = getSourceCARD()

        local hand = getPlayerDeck(player, "DECK_HAND")
        local list = getListFromDeck(hand)
        local cards, not_empty = makeFilteredList(player,list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")

        if not_empty then
            while getListLength(cards) > 0 do
                local menuCard = menuCards(player,cards,"Select a card to propose.","CARDLIST_PEEK")
                if menuCard ~= 0 then
                    cards = takeTargetCardFromList(menuCard,cards)

                    if(makePrompt(not player,true,"Accept " .. getNameFromCARD(getCARD(menuCard)) .. "?","The card will be spawned.","ZTCG_NIL","ZTCG_NIL","OK","Cancel")) then
                        moveCards(player,hand,hand,"TAKE_CARDID","PUT_BOTTOM",menuCard)
                        ret = summon(player,"PLAY_FORCESUMMON","ELEM_ANY","ZTCG_MAXVALUE")
                    else
                        attack(player, src, 40, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
                    end
                else
                    break
                end
            end
        end

        destroyList(cards)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 110"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",110)
    end

}
