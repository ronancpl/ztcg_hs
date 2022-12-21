ZTCG_CARD
{

    "NAME" "Michi"
    "IMAGE" "S4C040_Michi.png"
    "TYPE" "CHAR"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Character - Assassin"
    "COST" "800"

    TYPE_CHAR
    {
        LVL_ACTION
        {
            "LEVEL" "10"
            "ATTRB" "1"
            "TEXT" "Stab -- Do 10 damage to a character or monster."
        }
        LVL_ACTION
        {
            "LEVEL" "20"
            "ATTRB" "0"
            "TEXT" "Quest -- Draw a card."
        }
        LVL_ACTION
        {
            "LEVEL" "40"
            "ATTRB" "2"
            "TEXT" "Maxed Luck -- Flip a coin. If you win, choose an action under your character. When you would do that action this turn, you may do it 3 times instead."
        }
        "HP" "200"
    }

    function onActivateCharacterAction1(player)
        local src = getSourceCARD()
        attack(player, src, 10, "ATKRES_NIL", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction2(player)
        drawCard(player)
    end

    function onActivateCharacterAction3(player)
        if hasCharacterActions(player,true) then
            if throwCoin(player) then
                doRepeatCharacterAction(player,true,3)
            end
        end
    end

}
