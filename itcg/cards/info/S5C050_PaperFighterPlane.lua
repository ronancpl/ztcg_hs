ZTCG_CARD
{

    "NAME" "Paper Fighter Plane"
    "IMAGE" "S5C050_PaperFighterPlane.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Weapon"
    "COST" "650"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "Whenever you play a card, do 10 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "1"
        "TEXT" "Sneak 20 -- Play a card of level 20 or less."
    }

    function onPlayCard(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local str = "Sneak 20"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", 20)
    end

}
