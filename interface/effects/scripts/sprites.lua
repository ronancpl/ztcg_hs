ZTCG_SPRITE
{
    "SPR_SOURCE" "ZPsprites.jpg"    -- this preamble (source, count) must ALWAYS come before the first definition of a SPRITE block
    "SPR_NAME" "sprite"
    "SPR_COUNT" "8"

    "SPR_AUTO_DX" "16"
    "SPR_AUTO_DY" "0"

    SPRITE {                        -- at least ONE SPRITE block needs to be instantiated
        "SPR_ITEM_X" "0"
        "SPR_ITEM_Y" "16"

        "SPR_ITEM_DX" "16"
        "SPR_ITEM_DY" "16"
    }

    function onEffectStart()
        setEffectDuration(1000)

        setEffectTint(255,255,255,255) -- RGBA

        setEffectPosition(600,300)
        setEffectMovement(0,0)
        setEffectRandomMove(5,5)
        setEffectRandomStep(20,20)

        setEffectScale(4,4)

        setEffectRotationCenter(0,0)
        setEffectRotationAngle(0)

        setEffectFlags(0)
        setEffectDrawType("DRAW_SCALED")
        setEffectBlendingFlags("BLEND_ADD","BLEND_ALPHA","BLEND_ONE")

        -- deploy new effect after loading the effect's flags
        createEffect("sprite2")
    end
}
