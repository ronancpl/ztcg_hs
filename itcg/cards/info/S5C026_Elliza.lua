ZTCG_CARD
{

    "NAME" "Elliza"
    "IMAGE" "S5C026_Elliza.png"
    "TYPE" "BOSS"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Boss"
    "COST" "950"

    TYPE_BOS
    {
        "HP" "150"
        "ATTCK" "50"
        "LEVEL" "83"
        LVL_ACTION
        {
            "LEVEL" "0"
            "ATTRB" "0"
            "TEXT" "Soul Drain -- Whenever Elliza does damage, it gets that much +HP. It can't go over its starting HP with Soul Drain."
        }
    }

    function onExecuteAttack(player)
        local src = getSourceCARD()
        local hp = getGameValue(0)

        refreshHP(player,src,hp)
    end

}
