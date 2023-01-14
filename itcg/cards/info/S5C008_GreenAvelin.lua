ZTCG_CARD
{

    "NAME" "Green Avelin"
    "IMAGE" "S5C008_GreenAvelin.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Armor"
    "COST" "700"

    TYPE_EQP
    {
        "LEVEL" "10"
        "TEXT" "Whenever you level up with a lightning-bolt ability, do that ability an extra time."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Trigger Happy -- Do a lightning-bolt ability under your character other than a Trigger Happy."
    }

    function doRepeatLevelActionTrigger(player)
        return 2
    end

    function onLevelActionTrigger(player)
        doRepeatCharacterActionTrigger(player,true,1)
    end

}
