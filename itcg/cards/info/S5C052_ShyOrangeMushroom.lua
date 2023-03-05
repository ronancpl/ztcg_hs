ZTCG_CARD
{

    "NAME" "Shy Orange Mushroom"
    "IMAGE" "S5C052_ShyOrangeMushroom.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Mushroom"
    "COST" "620"

    TYPE_MOB
    {
        "LEVEL" "8"
        "ATTCK" "30"
        "HP" "30"
        "TEXT" "Run Away -- When your opponent plays a monster or item, destroy Shy Orange Mushroom."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Spy -- Draw a card. Then discard a card from your hand."
    }

    function onOpponentPlayEquipment(player)
        local src = getSourceCARD()

        local slotid = getSlotIdFromCARD(player,src)
        destroyCard(player,"SLOT_PLAYERMOB" .. slotid)
    end

    function onOpponentPlayMob(player)
        local src = getSourceCARD()

        local slotid = getSlotIdFromCARD(player,src)
        destroyCard(player,"SLOT_PLAYERMOB" .. slotid)
    end

    function onLevelActionTrigger(player)
        drawCard(player)
        discardCard(player)
    end

}
