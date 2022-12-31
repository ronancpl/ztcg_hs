ZTCG_CARD
{

    "NAME" "Exploding Meso Bags"
    "IMAGE" "S5C042_ExplodingMesoBags.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Bag"
    "COST" "800"

    TYPE_EQP
    {
        "LEVEL" "30"
        "TEXT" "When your turn starts, you may destroy one of your items. If you do, do its level in damage, rounded up to the nearest 10, to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "3"
        "TEXT" "Crafty -- Play a Thief card of your level or less."
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        if getSlotIdFromCARD(player,src) < 0 then return end

        local equips, not_empty = makeFilteredTableList(player,"ONLY_PLAYER",0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP","ELEM_ANY","ZTCG_NIL")
        if not_empty then
            local menuCard = menuCards(player,equips,"Select an equip to destroy for its level in attack.","CARDLIST_PEEK")
            if menuCard ~= 0 then
                local slotid = getSlotIdFromCARD(player,getCARD(menuCard)) - 7
                destroySelf(player,"SLOT_PLAYEREQP" .. slotid)

                local dmg = getCurrentLevelFromCARD(player, getCARD(menuCard))
                attack(player, src, dmg, "ATKRES_NIL", "ATKSRC_ACT", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
            end
        end

        destroyList(equips)
    end

    function onActivateCharacterAction(player)
        local str = "Crafty"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_THIEF", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", level)
    end

}
