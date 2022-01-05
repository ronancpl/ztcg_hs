ZTCG_CARD
{

    "NAME" "Alien Armada"
    "IMAGE" "S5C019_AlienArmada.png"
    "TYPE" "MOB"
    "ELEMENT" "Magician"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Alien Upgrade"
    "COST" "900"

    TYPE_MOB
    {
        "LEVEL" "42"
        "ATTCK" "50"
        "HP" "50"
        "TEXT" "Alien Upgrade -- Put on one of your Alien monsters. Collective Genius -- Whenever one of your Aliens attacks, draw a card."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Quest -- Draw a card."
    }

    function onLaunchAttack(player)
        local atkr = getCardPointer(0)
        if isInfoCARD(atkr, "Alien") then
            drawCard(player)
        end
    end

    function onLevelActionTrigger(player)
        drawCard(player)
    end


}
