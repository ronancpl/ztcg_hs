ZTCG_CARD
{

    "NAME" "Jr. Pepe"
    "IMAGE" "S2C052_JrPepe.png"
    "TYPE" "MOB"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Ice Bird"
    "COST" "620"

    TYPE_MOB
    {
        "LEVEL" "35"
        "ATTCK" "10"
        "HP" "50"
        "TEXT" "Ice Slide -- Whenever Jr. Pepe is damaged, prevent all other damage to it this turn."
    }

    LVL_ACTION
    {
        "LEVEL" "50"
        "ATTRB" "3"
        "TEXT" "Spawn X -- Play a monster of your level or less. "
    }

    function onStartTurn(player)
        editCardRegister(src,cardid,0,0,0,nil)
    end

    function onReceiveNormalAttack(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        editCardRegister(src,cardid,0,1,0,nil)
    end

    function preventTargetMob(player)
        local src = getSourceCARD()
        local cardid = getCardIdFromCARD(src)

        if getCardRegister(src,cardid,0) ~= 0 then
            return 1
        else
            return 0
        end
    end

    function onActivateCharacterAction(player)
        local chr = getOnBoardCARD(player, "SLOT_PLAYERCHAR")
        local level = getCurrentLevelFromCARD(player,chr)

        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",level)
    end

}
