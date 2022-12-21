ZTCG_CARD
{

    "NAME" "Fire Tusk"
    "IMAGE" "S3C050_FireTusk.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Elephant"
    "COST" "820"

    TYPE_MOB
    {
        "LEVEL" "36"
        "ATTCK" "30"
        "HP" "30"
        "TEXT" "Relentless 10 -- Whenever Fire Tusk destroys a monster, do 10 damage to your opponent's character."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "2"
        "TEXT" "Spawn / Equip 120 -- Play a monster or item of level 120 or less."
    }

    function onAttackOpponentMobDestroyed(player)
        local src = getSourceCARD()
        if src == getCardPointer(0) and getSlotIdFromCARD(player, src) > -1 then
            attack(player, src, 10, "ATKRES_DONT_HIT_MOBS", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 120"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 120)
    end

}
