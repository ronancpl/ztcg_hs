ZTCG_CARD
{

    "NAME" "Dark Lord's Strike"
    "IMAGE" "S4C036_DarkLordsStrike.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "800"

    TYPE_ACT
    {
        "LEVEL" "50"
        "TEXT" "Destroy a non-Boss monster. Then do damage equal to its attack to its player."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Dark Lord Team Up -- Draw a card. Then discard a card from your hand. If you're level 60 or more, you may play Dark Lord."
    }

    function onThinkAction(player)
        local src = getSourceCARD()

        local card = destroyMonster(player)
        if card ~= 0 then
            local dmg = getBaseAttackFromCARD(card)
            attack(player, src, dmg, "ATKRES_DONT_HIT_MOBS", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

    function onLevelActionTrigger(player)
        drawCard(player)
        discardCard(player)

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        local deckHand = getPlayerDeck(player, "DECK_HAND")
        local card_list, qty = getListFromDeck(deckHand)

        local list, not_empty = makeFilteredList(player,card_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANY","ELEM_ANY","Dark Lord")
        if level >= 60 and not_empty then
            local card = menuCards(player,list,"Select a mob to spawn.","CARDLIST_PEEK")
            if card ~= 0 then
                moveCards(player,deckHand,deckHand,"TAKE_CARDID","PUT_BOTTOM",card)
                summon(player,"PLAY_SCOUTSUMMON","ELEM_ANY","ZTCG_MAXVALUE")
            end
        end
        destroyList(list)
    end

}
