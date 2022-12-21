ZTCG_CARD
{

    "NAME" "Zakum Helmet"
    "IMAGE" "S5C089_ZakumHelmet.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Zakum Armor"
    "COST" "750"

    TYPE_EQP
    {
        "LEVEL" "50"
        "TEXT" "Whenever damage would be done to your character, flip a coin. If you win, prevent that damage. As long as you have Zakum Helmet, you can't play another Zakum Helmet."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "0"
        "TEXT" "Sell Loot -- Discard this card. Draw 3 cards."
    }

    function onInterceptAttack(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")

        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(chr, cid, 0, 10, 0, nil)
    end

    function onBlockResultDamage(player)
        local def_card = getCardPointer(1)
        if not hasSharedFlagsCARD(def_card, "FLAG_TYPE", "TYPE_CHAR") then return end

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")

        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if getCardRegister(chr, cid, 0) > 0 then
            editCardRegister(chr, cid, 0, 0, 0, nil)

            if throwCoin(player) then
                updateGameValue(0,0)
            end
        end
    end

    function onActivateCharacterAction(player)
        local src = getSourceCARD()

        if(not makePrompt(player,true,"Use Sell Loot?","Discard this action. Draw 3 cards.","ZTCG_NIL","ZTCG_NIL","OK","Cancel")) then return end

        destroyCharacterAction(player,src,true)

        for i = 1, 3, 1 do
            drawCard(player)
        end
    end

}
