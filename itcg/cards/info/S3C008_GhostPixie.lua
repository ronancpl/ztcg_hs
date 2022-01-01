ZTCG_CARD
{

    "NAME" "Ghost Pixie"
    "IMAGE" "S3C008_GhostPixie.png"
    "TYPE" "MOB"
    "ELEMENT" "Bowman"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Monster - Flying Spook"
    "COST" "710"

    TYPE_MOB
    {
        "LEVEL" "65"
        "ATTCK" "50"
        "HP" "40"
        "TEXT" "Phantom -- When you play Ghost Pixie, choose a card type (character, monster, tactic, or item). Cards of the chosen type can't damage Ghost Pixie."
    }

    LVL_ACTION
    {
        "LEVEL" "ZTCG_MAXVALUE"
        "ATTRB" "0"
        "TEXT" "Revive -- Return a monster of level 30 or less from your discard pile to your hand."
    }

    function onThinkMob(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        local cardType = selectCardType(player)
        editCardRegister(src, cid, 0, cardType, 0, nil)
    end

    function preventTargetMob(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if hasFlag("ZTCG_ATKSRC", "ATKSRC_CHA") and getCardRegister(src, cid, 0) == 1 then
            return 1
        elseif hasFlag("ZTCG_ATKSRC", "ATKSRC_MOB") and getCardRegister(src, cid, 0) == 2 then
            return 1
        elseif hasFlag("ZTCG_ATKSRC", "ATKSRC_EQP") and getCardRegister(src, cid, 0) == 3 then
            return 1
        elseif hasFlag("ZTCG_ATKSRC", "ATKSRC_ACT") and getCardRegister(src, cid, 0) == 4 then
            return 1
        else
            return 0
        end
    end

    function onLevelActionTrigger(player)
        recoverCard(player, "DECK_HAND", "RECOVER_MOB", "LESSER", 30)
    end

}
