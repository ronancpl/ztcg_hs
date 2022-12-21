ZTCG_CARD
{

    "NAME" "Jr. Cellion"
    "IMAGE" "S5C068_JrCellion.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Fire Kitty"
    "COST" "680"

    TYPE_MOB
    {
        "LEVEL" "33"
        "ATTCK" "30"
        "HP" "30"
        "TEXT" "Fire Pounce -- Whenever Jr. Cellion attacks a Water monster or an Ice monster, it gets +40 attack until end of turn."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "1"
        "TEXT" "Think Fast / Equip 40 -- Play a tactic or item of level 40 or less."
    }

    function onLaunchAttack(player)
        local src = getSourceCARD()
        local atkr = getCardPointer(0)

        if isSameCARD(src,atkr) then
            local def_card = getCardPointer(1)
            if isInfoCARD(def_card, "Water") or isInfoCARD(def_card, "Ice") then
                local src = getSourceCARD()
                newBuff(src,src,40,0,0,1)
            end
        end
    end

    function onActivateCharacterAction(player)
        local str = "Think Fast / Equip 40"
        playCard(player, str, "ELEM_ANY", "PLAY_EQUIP | PLAY_ACTION", 40)
    end

}
