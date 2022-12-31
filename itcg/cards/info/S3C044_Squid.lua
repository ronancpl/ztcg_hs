ZTCG_CARD
{

    "NAME" "Squid"
    "IMAGE" "S3C044_Squid.png"
    "TYPE" "MOB"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Water-Fish Beast"
    "COST" "740"

    TYPE_MOB
    {
        "LEVEL" "94"
        "ATTCK" "80"
        "HP" "90"
        "TEXT" "Toxic Ink Cloud -- Whenever your opponent does a character action, do 10 damage to that character. This damage can't be prevented."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Rogue's Revenge -- If you have 3 or more Thief cards under your character, destroy a non-Boss monster."
    }

    function afterOpponentApplyCharacterAction(player)
        if getGameValue(0) > 0 then
            local card = getSourceCARD()
            attack(player, card, 10, "ATKRES_DONT_HIT_MOBS", "ATKSRC_MOB", "ZTCG_DONTCARE", "STRIKE_NORMAL", "DISABLE_PREVENT", "IS_STARTER")
        end
    end

    function onLevelActionTrigger(player)
        if(not matchRequirements(player, 0, 3, "ELEM_THIEF")) then return end
        destroyMonster(player)
    end

}
