ZTCG_CARD
{

    "NAME" "Ryden"
    "IMAGE" "S3C015_Ryden.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Weapon"
    "COST" "780"

    TYPE_EQP
    {
        "LEVEL" "30"
        "TEXT" "When your turn ends, for each monster you have of level 30 or less, do 10 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Critical Shot -- Flip a coin. If you win, do damage equal to your level to a character or monster."
    }

    function onEndTurn(player)
        local list, not_empty = makeFilteredTableList(player, "ONLY_PLAYER", 0, 0, 30, "TYPE_ANYMOB", "ELEM_ANY", "ZTCG_NIL")

        local len = getListLength(list)
        for i = 1, len, 1 do
            local src = getSourceCARD()
            attack(player,src,10,"ATKRES_NIL", "ATKSRC_EQP", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end

        destroyList(list)
    end

    function onLevelActionTrigger(player)
        local res = throwCoin(player)
        if res then
            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            local level = getCurrentLevelFromCARD(player,chr)
            attack(player, chr, level, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

}
