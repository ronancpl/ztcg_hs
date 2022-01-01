ZTCG_CARD
{

    "NAME" "Destroy All Monsters"
    "IMAGE" "S3C036_DestroyAllMonsters.png"
    "TYPE" "ACTION"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Tactic - Strategy"
    "COST" "730"

    TYPE_ACT
    {
        "LEVEL" "60"
        "TEXT" "Destroy all monsters."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Super Spy -- Draw 2 cards. Then discard all but 2 cards from your hand."
    }

    function onThinkAction(player)
        destroySelf(player,"SLOT_PLAYERMOB1")
        destroySelf(player,"SLOT_PLAYERMOB2")
        destroySelf(player,"SLOT_PLAYERMOB3")
        destroySelf(player,"SLOT_PLAYERMOB4")
        destroySelf(player,"SLOT_PLAYERMOB5")
        destroySelf(player,"SLOT_PLAYERMOB6")
        destroySelf(player,"SLOT_PLAYERMOB7")

        destroySelf(player,"SLOT_ADVSRYMOB1")
        destroySelf(player,"SLOT_ADVSRYMOB2")
        destroySelf(player,"SLOT_ADVSRYMOB3")
        destroySelf(player,"SLOT_ADVSRYMOB4")
        destroySelf(player,"SLOT_ADVSRYMOB5")
        destroySelf(player,"SLOT_ADVSRYMOB6")
        destroySelf(player,"SLOT_ADVSRYMOB7")
    end

    function onLevelActionTrigger(player)
        drawCard(player)
        drawCard(player)

        local deckHand = getPlayerDeck(player, "DECK_HAND")
        local cards, qty = getListFromDeck(deckHand)
        for i = 1, qty - 2, 1 do
            discardCard(player)
        end
    end

}
