ZTCG_CARD
{

    "NAME" "Cube Slime"
    "IMAGE" "S5C057_CubeSlime.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Goo"
    "COST" "610"

    TYPE_MOB
    {
        "LEVEL" "32"
        "ATTCK" "20"
        "HP" "30"
        "TEXT" "Gelatinous -- Whenever Cube Slime attacks, clash with your opponent. If you win, you may destroy an item. (To clash, each player reveals the top card of their deck, then puts it on top or bottom. Whoever revealed the highest-level card wins.)"
    }

    LVL_ACTION
    {
        "LEVEL" "30"
        "ATTRB" "2"
        "TEXT" "Celebrate -- If you leveled up this turn, get +20 HP."
    }

    function onExecuteAttack(player)
        local eqps = getEquipsOnTable(player,"ONLY_ADVSRY")
        if eqps > 0 and playClash(player) then
            destroyEquipment(player)
        end
    end

    function onActivateCharacterAction(player)
        if isLevelUpTurn(player) then
            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
            refreshHP(player,chr,20)
        end
    end

}
