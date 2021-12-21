ZTCG_CARD
{

    "NAME" "Officer Skeleton"
    "IMAGE" "S1C081_OfficerSkeleton.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Undead Soldier"
    "COST" "550"

    TYPE_MOB
    {
        "LEVEL" "63"
        "ATTCK" "50"
        "HP" "60"
        "TEXT" "Bone Rattle -- Whenever one of your monsters destroys a monster, do 20 damage to your opponent's character."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "2"
        "TEXT" "Buff -- Monsters that attack this turn each get +10 attack until the end of the turn. "
    }

    function onAttackOpponentMobDestroyed(player)
        local src = getSourceCARD()
        attack(player, src, 20, "ATKRES_DONT_HIT_MOBS", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    local function onCalcAttackCard(player)
        local src = getSourceCARD()
        local atkr = getCardPointer(0)
        if hasSharedFlagsCARD(atkr,"FLAG_TYPE", "TYPE_MOB") then
            removeBuff(atkr,src,10,0,0,0)
            newBuff(atkr,src,10,0,0,0)
        end
    end

}
