ZTCG_CARD
{

    "NAME" "Brown Woodsman Boots"
    "IMAGE" "S5C002_BrownWoodsmanBoots.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Armor"
    "COST" "650"

    TYPE_EQP
    {
        "LEVEL" "15"
        "TEXT" "When your turn starts, you may choose an action on a card under your character. When you would do that action this turn, do it twice instead."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "2"
        "TEXT" "Think Fast / Equip 20 -- Play a tactic or item of level 20 or less."
    }

    function onStartTurn(player)
        doTwiceCharacterAction(player,true)
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 70"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 70)
    end

}
