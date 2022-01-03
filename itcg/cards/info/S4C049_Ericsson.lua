ZTCG_CARD
{

    "NAME" "Ericsson"
    "IMAGE" "S4C049_Ericsson.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Human NPC"
    "COST" "680"

    TYPE_MOB
    {
        "LEVEL" "35"
        "ATTCK" "30"
        "HP" "30"
        "TEXT" "NPC Quest -- Ericsson or another of your monsters is destroyed. Reward -- Do 30 damage to a monster or character."
    }

    LVL_ACTION
    {
        "LEVEL" "80"
        "ATTRB" "1"
        "TEXT" "Spawn 100 -- Play a monster of level 100 or less."
    }

    function onAttackMobDestroyed(player)
        local src = getSourceCARD()
        attack(player,src,30,"ATKRES_NIL", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "PREVENT_ANY", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 100"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",100)
    end

}
