ZTCG_CARD
{

    "NAME" "Mithril Mutae"
    "IMAGE" "S5C070_MithrilMutae.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Mechanical Guardian"
    "COST" "740"

    TYPE_MOB
    {
        "LEVEL" "47"
        "ATTCK" "20"
        "HP" "40"
        "TEXT" "Armored 20 -- Whenever Mithril Mutae would be damaged, prevent 20 of that damage."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "3"
        "TEXT" "Spawn X -- Spawn a monster of your level or less."
    }

    function onThinkMob(player)
        local src = getSourceCARD()
        incrementBuffEffect(player,src)
        newBuff(src,src,0,0,20,1)
    end

    function undoBuffs(player)
        local src = getSourceCARD()
        removeBuff(src,src,0,0,20)
    end

    function applyBuffs(player)
        local src = getSourceCARD()
        newBuff(src,src,0,0,20,1)
    end

    function onActivateCharacterAction(player)
        local str = "Spawn X"

        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",level)
    end

}
