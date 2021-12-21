ZTCG_CARD
{

    "NAME" "Serpent's Tongue"
    "IMAGE" "S1C088_SerpentsTongue.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Weapon"
    "COST" "540"

    TYPE_EQP
    {
        "LEVEL" "50"
        "TEXT" "Whenever one of your monsters destroys a monster, you get +30 HP."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Crush -- Do 20 damage to a monster. "
    }

    function onAttackOpponentMobDestroyed(player)
        local atkr = getCardPointer(0)
        if hasSharedFlagsCARD(atkr,"FLAG_TYPE","TYPE_MOB") then
            local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            refreshHP(player,card,30)
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_DONT_HIT_CHAR", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end


}
