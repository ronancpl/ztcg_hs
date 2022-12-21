ZTCG_CARD
{

    "NAME" "Bain"
    "IMAGE" "S3C046_Bain.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Dog"
    "COST" "730"

    TYPE_MOB
    {
        "LEVEL" "90"
        "ATTCK" "60"
        "HP" "80"
        "TEXT" "Flame Bark -- When you play Bain, do +40 damage to one of your opponent's monsters. If this damage destroys that monster, Bain gets +40 attack this turn."
    }

    LVL_ACTION
    {
        "LEVEL" "70"
        "ATTRB" "2"
        "TEXT" "Smash -- Do 30 damage to a monster."
    }

    function onThinkMob(player)
        local src = getSourceCARD()
        attack(player, src, 40, "ATKRES_DONT_HIT_CHAR", "ATKSRC_MOB", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")

        if lastAttackKilled(player) then
            newBuff(src,src,40,0,0,1)
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        attack(player, chr, 30, "ATKRES_DONT_HIT_CHAR", "ATKSRC_CHA", "ZTCG_NIL", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

}
