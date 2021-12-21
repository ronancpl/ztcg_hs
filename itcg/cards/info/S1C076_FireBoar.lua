ZTCG_CARD
{

    "NAME" "Fire Boar"
    "IMAGE" "S1C076_FireBoar.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Fire Boar"
    "COST" "480"

    TYPE_MOB
    {
        "LEVEL" "32"
        "ATTCK" "10"
        "HP" "50"
        "TEXT" "Fierce -- Fire Boar attacks twice each turn."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "2"
        "TEXT" "Spawn 40 -- Play a monster of level 40 or less. "
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

    function onActivateCharacterAction(player)
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",40)
    end

}
