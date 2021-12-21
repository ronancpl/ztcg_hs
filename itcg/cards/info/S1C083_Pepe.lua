ZTCG_CARD
{

    "NAME" "Pepe"
    "IMAGE" "S1C083_Pepe.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - King Ice Bird"
    "COST" "600"

    TYPE_MOB
    {
        "LEVEL" "60"
        "ATTCK" "40"
        "HP" "70"
        "TEXT" "Relentless 10 -- Whenever Pepe destroys a monster, do 10 damage to your opponent's character."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "1"
        "TEXT" "Spawn / Think Fast 70 -- Play a monster or tactic of level 70 or less. "
    }

    function onAttackOpponentMobDestroyed(player)
        local src = getSourceCARD()
        print(getNameFromCARD(getCardPointer(1)))
        if src == getCardPointer(0) then
            attack(player, src, 10, "ATKRES_DONT_HIT_MOBS", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 70"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 70)
    end

}
