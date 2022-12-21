ZTCG_CARD
{

    "NAME" "Metus"
    "IMAGE" "S5C014_Metus.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Zakum Weapon"
    "COST" "800"

    TYPE_EQP
    {
        "LEVEL" "90"
        "TEXT" "Whenever you would do an action on a card under your character, you may instead treat it as if it says 60BB Tricky Shot -- Do 20 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "No Mercy 20 -- Do 20 damage to a character or monster. If that damage destroys a monster, do this action again."
    }

    function onInterceptCharacterAction(player)
        if(matchRequirements(player, 60, 2, "ELEM_BOWMAN")) then
            local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")

            local res = attack(player, chr, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
            if res then
                return 1       -- ignore character action
            end
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")

        local res = true
        while res do
            attack(player, chr, 20, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")

            if not lastAttackKilled(player) then
                res = false
            end
        end
    end

}
