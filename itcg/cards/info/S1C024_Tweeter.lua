ZTCG_CARD
{

    "NAME" "Tweeter"
    "IMAGE" "S1C024_Tweeter.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Flying Bird"
    "COST" "630"

    TYPE_MOB
    {
        "LEVEL" "39"
        "ATTCK" "20"
        "HP" "40"
        "TEXT" "Revenge -- Whenever your opponent plays a monster, item, or tactic, do 20 damage to his or her character."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "2"
        "TEXT" "Tricky Shot -- Do 20 damage to a character or monster. "
    }

    function onOpponentPlayCard(player)
        local target = getTargetCARD()
        if hasSharedFlagsCARD(target,"FLAG_TYPE", "TYPE_MOB | TYPE_EQP | TYPE_ACT") then
            local src = getSourceCARD()
            attack(player, src, 20, "ATKRES_DONT_HIT_MOBS", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

}
