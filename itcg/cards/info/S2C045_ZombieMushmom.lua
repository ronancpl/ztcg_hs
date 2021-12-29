ZTCG_CARD
{

    "NAME" "Zombie Mushmom"
    "IMAGE" "S2C045_ZombieMushmom.png"
    "TYPE" "BOSS"
    "ELEMENT" "Thief"
    "RARITY" "RARITY_UNIQUE"
    "INFO" "Monster - Boss"
    "COST" "710"

    TYPE_BOS
    {
        "HP" "140"
        "ATTCK" "50"
        "LEVEL" "76"
        LVL_ACTION
        {
            "LEVEL" "0"
            "ATTRB" "0"
            "TEXT" "Rise From the Grave -- When Zombie Mushmom is destroyed, play rock-paper-scissors with your opponent. If you win, return it to play with 70 HP."
        }
    }

    function onReceiveAttackAndInterceptDestroyed(player)
        if playRps(player) then
            local src = getSourceCARD()

            editCardHP(src,70)
            updateGameValue(0, 0)
        end
    end


}
