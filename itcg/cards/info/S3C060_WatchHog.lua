ZTCG_CARD
{

    "NAME" "Watch Hog"
    "IMAGE" "S3C060_WatchHog.png"
    "TYPE" "EQUIP"
    "ELEMENT" "Warrior"
    "RARITY" "RARITY_SELDOM"
    "INFO" "Item - Boar Mount"
    "COST" "720"

    TYPE_EQP
    {
        "LEVEL" "70"
        "TEXT" "Once a turn, you may prevent all damage from a character action, monster attack, or tactic."
    }

    LVL_ACTION
    {
        "LEVEL" "60"
        "ATTRB" "1"
        "TEXT" "Spawn 70 -- Play a monster of level 70 or less."
    }

    function onStartTurn(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src,cid,0,0,0,nil)
    end

    function onThinkEquipment(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        editCardRegister(src,cid,0,0,0,nil)
    end

    function onBlockResultDamage(player)
        local src = getSourceCARD()
        local cid = getCardIdFromCARD(src)

        if getCardRegister(src,cid,0) ~= 0 then return end
        local dmg = getGameValue(0)
        if not (makePrompt(player,"Use " .. getNameFromCARD(src) .. "?","Prevent one damage instance per turn... Prevent %d damage.",dmg,"ZTCG_NIL","OK","Cancel")) then return end

        editCardRegister(src,cid,0,1,0,nil)
        updateGameValue(0, 0)   -- block damage
    end

    function onActivateCharacterAction(player)
        local str = "Spawn 70"
        summon(player,"PLAY_NORMALSUMMON","ELEM_ANY",70)
    end

}
