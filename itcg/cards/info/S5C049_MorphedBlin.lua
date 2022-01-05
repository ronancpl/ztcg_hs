ZTCG_CARD
{

    "NAME" "Morphed Blin"
    "IMAGE" "S5C049_MorphedBlin.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Fire Stone Goblin"
    "COST" "740"

    TYPE_MOB
    {
        "LEVEL" "60"
        "ATTCK" "40"
        "HP" "60"
        "TEXT" "Boulder Drop -- When your opponent's turn ends, do 40 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "2"
        "TEXT" "Sneak 90 -- Play a card of level 90 or less."
    }

    function onOpponentEndTurn(player)
        local src = getSourceCARD()
        attack(player, src, 40, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local str = "Sneak 90"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", 90)
    end

}
