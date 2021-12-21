ZTCG_CARD
{

    "NAME" "Buffy"
    "IMAGE" "S1C052_Buffy.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Undead Clown"
    "COST" "750"

    TYPE_MOB
    {
        "LEVEL" "61"
        "ATTCK" "40"
        "HP" "40"
        "TEXT" "Shriek -- When you play Buffy, destroy a card under a character."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "1"
        "TEXT" "Sneak 20 -- Play a card of level 20 or less. "
    }

    function onThinkMob(player)
        local cards, list_sz = getListFromCharacterActions(not player, true)
        if list_sz > 0 then
            local card = menuCards(player,cards,"Select a card to remove from the opponent's character actions.","CARDLIST_PEEK")
            if card ~= 0 then
                destroyCharacterAction(player, getCARD(card))
            end
        end

        destroyList(cards)
    end

    function onActivateCharacterAction(player)
        local str = "Sneak 20"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", 20)
    end

}
