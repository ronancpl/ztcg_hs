ZTCG_CARD
{

    "NAME" "8 Arms of Zakum"
    "IMAGE" "S5C073_ArmsofZakum.png"
    "TYPE" "ACTION"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Zakum Spell"
    "COST" "700"

    TYPE_ACT
    {
        "LEVEL" "70"
        "TEXT" "Do 80 damage to a character or monster. You get +80 HP. If you have Zakum, remove all damage from it."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "0"
        "TEXT" "Think Fast / Equip 100 -- Play a tactic or item of level 100 or less."
    }

    function onThinkAction(player)
        local src = getSourceCARD()
        attack(player, src, 80, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        refreshHP(player,chr,80)

        local clist = makeFilteredTableList(player, "ONLY_PLAYER", 0, "ZTCG_DONTCARE", "ZTCG_DONTCARE", "TYPE_ANY", "ELEM_ANY", "Zakum")
        while not isEmptyList(clist) do
            local card
            clist, card = takeNextCardsFromList(clist,1)

            local cardp = getCARD(card)
            refreshHP(player,cardp,"ZTCG_MAXVALUE")

            destroyList(card)
        end

        destroyList(clist)
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 100"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 100)
    end

}
