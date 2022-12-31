ZTCG_CARD
{

    "NAME" "Brave Fairy"
    "IMAGE" "S2C003_BraveFairy.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Flying Fairy"
    "COST" "550"

    TYPE_MOB
    {
        "LEVEL" "30"
        "ATTCK" "30"
        "HP" "10"
        "TEXT" "Rescue -- Whenever your opponent levels up, you may return a monster of level 30 or less from your discard pile to your hand."
    }

    LVL_ACTION
    {
        "LEVEL" "20"
        "ATTRB" "2"
        "TEXT" "Double Spawn 20 -- Play up to 2 monsters of level 20 or less. "
    }

    function onOpponentLevelUp(player)
        recoverCard(player, "DECK_HAND", "RECOVER_MOB", "LESSER", 30)
    end

    function onActivateCharacterAction(player)
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",20)
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",20)
    end

}
