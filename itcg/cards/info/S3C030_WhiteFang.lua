ZTCG_CARD
{

    "NAME" "White Fang"
    "IMAGE" "S3C030_WhiteFang.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Wolf"
    "COST" "730"

    TYPE_MOB
    {
        "LEVEL" "58"
        "ATTCK" "40"
        "HP" "40"
        "TEXT" "Pet Defender -- White Fang gets +30 attack and +30 HP as long as you have a Pet."
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "1"
        "TEXT" "Spawn / Equip 20 -- Play a monster or item of level 20 or less."
    }

    function undoBuffs(player)
        if not isPetOnPlayerTable(player) then return end

        local src = getSourceCARD()
        removeTargetBonus(player,src,src,30,30,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
    end

    function applyBuffs(player)
        if not isPetOnPlayerTable(player) then return end

        local src = getSourceCARD()
        applyTargetBonus(PLAYER,src,src,30,30,0,0,"ZTCG_DONTCARE","ZTCG_DONTCARE","TYPE_ANYMOB","ELEM_ANY","ZTCG_NIL")
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 20"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 20)
    end

}
