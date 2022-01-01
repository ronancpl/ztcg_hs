ZTCG_CARD
{

    "NAME" "Blood Larceny"
    "IMAGE" "S3C032_BloodLarceny.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Armor"
    "COST" "750"

    TYPE_EQP
    {
        "LEVEL" "80"
        "TEXT" "When your opponent's turn ends, flip two coins. If you win both flips, take another turn after this one."
    }

    LVL_ACTION
    {
        "LEVEL" "90"
        "ATTRB" "3"
        "TEXT" "Equip Unlimited -- Play an item."
    }

    function onOpponentEndTurn(player)
        if throwCoin(player) and throwCoin(player) then
            doubleTurn(player)
        end
    end

    function onActivateCharacterAction(player)
        local str = "Equip Unlimited"
        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY","ZTCG_MAXVALUE")
    end

}
