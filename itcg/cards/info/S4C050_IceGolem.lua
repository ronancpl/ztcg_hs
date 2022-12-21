ZTCG_CARD
{

    "NAME" "Ice Golem"
    "IMAGE" "S4C050_IceGolem.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Ice Guardian"
    "COST" "650"

    TYPE_MOB
    {
        "LEVEL" "60"
        "ATTCK" "40"
        "HP" "60"
        "TEXT" "Shield 30 -- Ice Golem prevents 30 damage to your character instead of 10."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "1"
        "TEXT" "Whack -- Do 10 damage to a monster."
    }

    function onCalcDefenseCard(player)
        local def_card = getCardPointer(1)
        if(hasSharedFlagsCARD(def_card, "FLAG_TYPE", "TYPE_CHAR")) then
            local src = getSourceCARD()
            local cardid = getCardIdFromCARD(src)

            local dmgPrevent = getGameValue(0) + 20
            updateGameValue(0, dmgPrevent)
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 10, "ATKRES_DONT_HIT_CHAR", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
