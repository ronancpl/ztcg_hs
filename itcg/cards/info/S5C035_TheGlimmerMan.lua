ZTCG_CARD
{

    "NAME" "The Glimmer Man"
    "IMAGE" "S5C035_TheGlimmerMan.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Alien NPC"
    "COST" "760"

    TYPE_MOB
    {
        "LEVEL" "60"
        "ATTCK" "30"
        "HP" "70"
        "TEXT" "NPC Quest -- Play a Weapon or Armor from your hand. Reward -- Search your deck for a Weapon or Armor card and play it. Then shuffle your deck."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 80 -- Play a monster or item of level 80 or less."
    }

    function onPlayEquipment(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        if getCardRegister(src,cardid,0) ~= 0 then return end

        local target = getTargetCARD()
        if isInfoCARD(target, "Weapon") or isInfoCARD(target, "Armor") then
            local deck = getPlayerDeck(player, "DECK_DECK")
            local deck_list = getListFromDeck(deck)

            local hand = getPlayerDeck(player, "DECK_HAND")

            local card_list1 = makeFilteredList(player,deck_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP", "ELEM_ANY", "Weapon")
            local card_list2 = makeFilteredList(player,deck_list,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_EQP", "ELEM_ANY", "Armor")
            card_list1 = appendLists(card_list1,card_list2)

            local card = menuCards(player,card_list1,"Select a card to equip.","CARDLIST_PEEK")
            if card ~= 0 then
                moveCards(player,deck,hand,"TAKE_CARDID","PUT_BOTTOM",card)

                editCardRegister(src,cardid,0,1,0,nil)
                equip(player,"PLAY_SCOUTEQUIP", "ELEM_ANY","ZTCG_MAXVALUE")
                editCardRegister(src,cardid,0,0,0,nil)
            end

            destroyList(card_list2)
            destroyList(card_list1)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 80"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 80)
    end

}
