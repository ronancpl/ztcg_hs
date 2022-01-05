ZTCG_CARD
{

    "NAME" "Opachu"
    "IMAGE" "S5C085_Opachu.png"
    "TYPE" "MOB"
    "ELEMENT" "Jobless"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Zakum Guardian"
    "COST" "650"

    TYPE_MOB
    {
        "LEVEL" "70"
        "ATTCK" "40"
        "HP" "60"
        "TEXT" "Punish Intruders -- Whenever damage is done to Opachu, do that much damage to your opponent's character."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "0"
        "TEXT" "Spawn / Think Fast 50 -- Play a monster of level 50 or less."
    }

    function onReceiveNormalAttack(player)
        local src = getSourceCARD()
        local dmg = getGameValue(0)
        attack(player, src, dmg, "ATKRES_DONT_HIT_MOBS", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Think Fast 50"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_ACTION", 50)
    end

}
