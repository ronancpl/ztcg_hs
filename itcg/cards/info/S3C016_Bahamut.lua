ZTCG_CARD
{

    "NAME" "Bahamut"
    "IMAGE" "S3C016_Bahamut.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Summoned Flying Dragon"
    "COST" "1100"

    TYPE_MOB
    {
        "LEVEL" "120"
        "ATTCK" "50"
        "HP" "100"
        "TEXT" "Mega Fierce -- Bahamut attacks 3 times each turn. Summoned -- When your turn ends, destroy Bahamut if you didn't play it this turn."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Command -- Return this card to your hand. Then level up with the top card of your deck."
    }

    function onThinkMob(player)
        local src = getSourceCARD()
        addExtraMobAttack(src, src, 3)  -- just played this card, apply attack bonus
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        addExtraMobAttack(src, src, 3)
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        removeExtraMobAttack(src, src)
    end

    function onEndTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if(getCardRegister(src, cid, 0) == 1) then
            local slotid = getSlotIdFromCARD(player,src)
            destroySelf(player,"SLOT_PLAYERMOB" .. slotid)
        else
            editCardRegister(src, cid, 0, 1, 0, null)
        end
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()
        destroyCharacterAction(player, src,true)

        local grav = getPlayerDeck(player, "DECK_GRAV")
        local hand = getPlayerDeck(player, "DECK_HAND")

        local target = makeTargetFromCARD(src)
        moveCards(grav,hand,"TAKE_CARDID","PUT_BOTTOM",target)
        destroyList(target)

        local d = drawCard(player)
        if d then
            levelUpScout(player)
        end
    end

}
