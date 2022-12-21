ZTCG_CARD
{

    "NAME" "Kumbi Throwing Star"
    "IMAGE" "S1C062_KumbiThrowingStar.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Weapon"
    "COST" "630"

    TYPE_EQP
    {
        "LEVEL" "30"
        "TEXT" "Whenever one of you opponent's character actions damages you, do 20 damage to that character."
    }

    LVL_ACTION
    {
        "LEVEL" "10"
        "ATTRB" "1"
        "TEXT" "Equip 20 -- Play an item of level 20 or less. "
    }

    function onReceiveAttackCard(player)
        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") then
            local src = getSourceCARD()
            attack(player, src, 20, "ATKRES_DONT_HIT_MOBS", "ATKSRC_EQP", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
        end
    end

    function onActivateCharacterAction(player)
        equip(player,"PLAY_NORMALEQUIP","ELEM_ANY",20)
    end


}
