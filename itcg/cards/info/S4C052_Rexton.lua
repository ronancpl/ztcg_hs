ZTCG_CARD
{

    "NAME" "Rexton"
    "IMAGE" "S4C052_Rexton.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Fire Beast"
    "COST" "780"

    TYPE_MOB
    {
        "LEVEL" "95"
        "ATTCK" "80"
        "HP" "80"
        "TEXT" "Fire Snort -- When you play Rexton, it gets +40 attack until the end of turn."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Gusto -- For the next non-Boss monster you play this turn, get +HP equal to that monster's HP."
    }

    function onThinkMob(player)
        local src = getSourceCARD()
        incrementBuffEffect(player,src)
        newBuff(src,src,40,0,0,1)
    end

    function onPlayMob(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        if getCardRegister(src,cardid,0) == 1 then
            local card = getTargetCARD()
            if not isBossCARD(card) then
                local hp = getMaxHpFromCARD(card)
                local card = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
                refreshHP(player,card,hp)

                editCardRegister(src,cardid,0,0,0,nil)
            end
        end
    end

    function onLevelActionTrigger(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)
        editCardRegister(src,cardid,0,1,0,nil)

        insertCardTurnAction(player)
    end

}
