ZTCG_CARD
{

    "NAME" "Black Magic Shoes"
    "IMAGE" "S2C019_BlackMagicShoes.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Item - Armor"
    "COST" "570"

    TYPE_EQP
    {
        "LEVEL" "30"
        "TEXT" "When your turn starts, you may choose an action on a card under your character. When you would do that action this turn, do it twice instead."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 70 -- Play a monster or item of level 70 or less. "
    }

    function onStartTurn(player)
        doTwiceCharacterAction(player,true)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 70"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 70)
    end

}
