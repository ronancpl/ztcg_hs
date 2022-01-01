ZTCG_CARD
{

    "NAME" "Stone Golem"
    "IMAGE" "S1C092_StoneGolem.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Guardian"
    "COST" "830"

    TYPE_MOB
    {
        "LEVEL" "55"
        "ATTCK" "40"
        "HP" "70"
        "TEXT" "Relentless 40 -- Whenever Stone Golem destroys a monster, do 40 damage to your opponent's character."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Scout -- Reveal the top card of your deck. If it's a monster card, put it into your hand. Otherwise put it back. "
    }

    function onAttackOpponentMobDestroyed(player)
        local src = getSourceCARD()
        if src == getCardPointer(0) and getSlotIdFromCARD(player, src) > -1 then
            attack(player, src, 40, "ATKRES_DONT_HIT_MOBS", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end
    end

    function onLevelActionTrigger(player)
        scoutMob(player,"SCOUT_NORMAL","ELEM_ANY")
    end

}
