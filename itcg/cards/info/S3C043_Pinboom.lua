ZTCG_CARD
{

    "NAME" "Pinboom"
    "IMAGE" "S3C043_Pinboom.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_COMMON"
    "INFO" "Monster - Water Flora"
    "COST" "700"

    TYPE_MOB
    {
        "LEVEL" "22"
        "ATTCK" "0"
        "HP" "10"
        "TEXT" "Rooted -- Pinboom can't attack characters. Spike Burst -- When Pinboom is destroyed, do 40 damage to a character or monster."
    }

    LVL_ACTION
    {
        "LEVEL" "40"
        "ATTRB" "1"
        "TEXT" "Spawn / Equip 30 -- Play a monster or item of level 30 or less."
    }

    function preventSelfTargetCharacter(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if getCardRegister(src,cid,0) == 0 then
            return 1
        else
            return 0
        end
    end

    function onReceiveAttackAndInterceptDestroyed(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)
        editCardRegister(src,cid,0,1,0,nil)

        local card = getSourceCARD()
        attack(player, card, 40, "ATKRES_NIL", "ATKSRC_MOB", "ZTCG_DONTCARE", "STRIKE_NORMAL", "ENABLE_PREVENT", "IS_STARTER")
    end

    function onActivateCharacterAction(player)
        local str = "Spawn / Equip 30"
        playCard(player, str, "ELEM_ANY", "PLAY_MOB | PLAY_EQUIP", 30)
    end

}
