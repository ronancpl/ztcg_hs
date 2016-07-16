ZTCG_CARD
{
    "NAME" "Knight"
    "IMAGE" "knight.png"
    "INFO" "Light - Character"  -- Lua-like line comments can be used at these card descriptor files.
    "TYPE" "CHAR"
    "ELEMENT" "LIGHT"
    "RARITY" "1"
    "COST" "777"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "0"
            "TEXT" "Mission - Draw Card"
        }

        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "0"
            "TEXT" "Slash - Do 20 damage to a character or monster."
        }

        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "0"
            "TEXT" "Graal Blessings - Grant all LIGHT mobs with +10 ATK and +20 HP."
        }

        "HP" "240"
    }

    function onActivateCharacterAction1(player)
        -- every character should have a draw card effect.
        drawCard(player);
    end

    function onActivateCharacterAction2(player)
        local deck = getPlayerDeck(player, "DECK_HAND")
        local card_list = getDataFromDeck(deck)

        local board_card = getCARD(card_list)
        print("Card", getNameFromCARD(board_card), "on slot ", getSlotIdFromCARD(player,board_card))

        local aa = getSourceCARD()
        print("Card", getNameFromCARD(aa), "on slot ", getSlotIdFromCARD(player,aa))
    end

    function onActivateCharacterAction3(player)
        sendPlayerAway(player,"IS_PLAYER",4)
        sendPlayerAway(player,"IS_ADVSRY",2)
    end

    --struct CARD *card = getCardPointer(int pos)

}
