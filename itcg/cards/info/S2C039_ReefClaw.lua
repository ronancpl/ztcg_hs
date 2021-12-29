ZTCG_CARD
{

    "NAME" "Reef Claw"
    "IMAGE" "S2C039_ReefClaw.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Item - Weapon"
    "COST" "550"

    TYPE_EQP
    {
        "LEVEL" "40"
        "TEXT" "Whenever your opponent levels up, do 10 damage to his or her character."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Thief Prowess -- Play a Thief card of your level or less. "
    }

    function onOpponentLevelUp(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_DONT_HIT_MOBS", "ATKSRC_EQP", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onLevelActionTrigger(player)
        local str = "Thief Prowess"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)
        playCard(player, str, "ELEM_THIEF", "PLAY_MOB | PLAY_EQUIP | PLAY_ACTION | PLAY_FIELD", level)
    end

}
