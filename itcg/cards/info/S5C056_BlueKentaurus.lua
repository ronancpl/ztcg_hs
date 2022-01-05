ZTCG_CARD
{

    "NAME" "Blue Kentaurus"
    "IMAGE" "S5C056_BlueKentaurus.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Ice Centaur Beast"
    "COST" "820"

    TYPE_MOB
    {
        "LEVEL" "88"
        "ATTCK" "80"
        "HP" "80"
        "TEXT" "Numbing Frost -- Whenever Blue Kentaurus would take 60 or more damage all at once, that turn ends."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "3"
        "TEXT" "Spawn / Equip 100 -- Play a monster or item of level 100 or less."
    }

    function onBlockResultDamage(player)
        local dmg = getGameValue(0)
        if dmg >= 60 then
            updateGameValue(0,0)
            finishTurn(player)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 100"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 100)
    end

}
