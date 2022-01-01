ZTCG_CARD
{

    "NAME" "Yeti and Pepe"
    "IMAGE" "S1C096_YetiandPepe.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Ice-Bird Beast"
    "COST" "810"

    TYPE_MOB
    {
        "LEVEL" "78"
        "ATTCK" "50"
        "HP" "80"
        "TEXT" "Fierce -- Yeti and Pepe attack twice each turn. Relentless 20 -- Whenever Yeti and Pepe destroys a monster, do 20 damage to your opponent's character."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "3"
        "TEXT" "Spawn / Equip 100 -- Play a monster or item of level 100 or less. "
    }

    function onThinkMob(player)
        local src = getSourceCARD()
        addExtraMobAttack(src,src,2)
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        addExtraMobAttack(src, src, 2)
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        removeExtraMobAttack(src, src)
    end

    function onAttackOpponentMobDestroyed(player)
        local src = getSourceCARD()
        if src == getCardPointer(0) and getSlotIdFromCARD(player, src) > -1 then
            attack(player, src, 20, "ATKRES_DONT_HIT_MOBS", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 100"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 100)
    end

}
