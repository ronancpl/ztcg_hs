ZTCG_CARD
{

    "NAME" "Beetle"
    "IMAGE" "S3C048_Beetle.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Pest"
    "COST" "650"

    TYPE_MOB
    {
        "LEVEL" "72"
        "ATTCK" "50"
        "HP" "60"
        "TEXT" "Chitin -- Whenever Beetle would be damaged, prevent 10 of that damage."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "1"
        "TEXT" "Spawn 30 -- Play a monster of level 30 or less."
    }

    function onThinkMob(player)
        local src = getSourceCARD()
        incrementBuffEffect(player,src)
        newBuff(src,src,0,0,10,1)
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        removeBuff(src,src,0,0,10)
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        newBuff(src,src,0,0,10,1)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 30"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",30)
    end
}
