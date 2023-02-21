ZTCG_SPRITE
{
    "SPR_SOURCE" "ZPsprites.png"    -- this preamble (source, count) must ALWAYS come before the first definition of a SPRITE block
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
        setNewEffectDuration(10000)
        setNewEffectSpriteDuration(500)

        setNewEffectTint(255,255,255,255) -- RGBA

        setNewEffectPosition(600,300)
        setNewEffectMovement(0,0)
        setNewEffectRandomMove(5,5)
        setNewEffectRandomStep(20,20)

        setNewEffectScale(4,4)

        setNewEffectRotationCenter(0,0)
        setNewEffectRotationAngle(0)

        setNewEffectFlags(0)
        setNewEffectDrawType("DRAW_SCALED")
        setNewEffectBlendingFlags("BLEND_ADD","BLEND_ALPHA","BLEND_ONE")

        -- deploy new effect after loading the effect's flags
        createEffect("sprite2")
    end
}
