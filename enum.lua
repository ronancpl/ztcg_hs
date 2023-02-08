ztcg_enum =
{
    -- feel free to add your new enumerators at the END of this list, at the assigned mod area.

    -- ###############################
    -- ## DO NOT MODIFY THESE ENUMS ##
    -- ###############################

    {"ZTCG_CARD" , 0},
    {"ZTCG_SPRITE"},

    {"SPR_SOURCE", 1},
    {"SPR_NAME"},
    {"SPR_COUNT"},
    {"SPR_AUTO_DX"},
    {"SPR_AUTO_DY"},
    {"SPR_ITEM_X"},
    {"SPR_ITEM_Y"},
    {"SPR_ITEM_DX"},
    {"SPR_ITEM_DY"},

    -- Drawing modes
    {"DRAW_SOURCE", 1},
    {"DRAW_SCALED"},
	{"DRAW_TINTED"},
	{"DRAW_ROTATED"},
	{"DRAW_COMPLEX"},

	-- Drawing "Flag" operations
	{"FLIP_NONE", 0},
	{"FLIP_HORIZONTAL"},
	{"FLIP_VERTICAL"},
	{"FLIP_HORIZONTAL_VERTICAL"},

	-- Blend operations
    {"BLEND_ADD", 0},
    {"BLEND_SRC_MINUS_DEST"},
	{"BLEND_DEST_MINUS_SRC"},

	-- Blend modes
	{"BLEND_ZERO", 0},
    {"BLEND_ONE"},
	{"BLEND_ALPHA"},
	{"BLEND_INVERSE_ALPHA"},
	{"BLEND_SRC_COLOR"},
	{"BLEND_DEST_COLOR"},
	{"BLEND_INVERSE_SRC_COLOR"},
	{"BLEND_INVERSE_DEST_COLOR"},

    {"MOB", 0},
    {"EQUIP"},
    {"ACTION"},
    {"FIELD"},
    {"CHAR"},
    {"JRBOSS"},
    {"BOSS"},

    -- ZTCG_RARITY
    {"RARITY_UNIQUE", 1},
    {"RARITY_SELDOM", 3},
    {"RARITY_COMMON", 7},

    -- ZTCG_TRUESTRIKE
    {"STRIKE_NORMAL", 0},
    {"STRIKE_TRUE"},

    -- ZTCG_TYPE
    {"TYPE_MOB", 0},
    {"TYPE_EQP"},
    {"TYPE_ACT"},
    {"TYPE_FLD"},
    {"TYPE_CHAR"},
    {"TYPE_JRB"},
    {"TYPE_BOS"},
    {"TYPE_ANYMOB"},    -- a FLAG, NOT a card-type
    {"TYPE_ANY"},       -- a FLAG, NOT a card-type
    {"LVL_ACTION"},

    {"EARTH", 0},
    {"WIND"},
    {"FIRE"},
    {"WATER"},
    {"DARK"},
    {"LIGHT"},

    {"Warrior", 0},
    {"Magician"},
    {"Bowman"},
    {"Thief"},
    {"Jobless"},

    -- ZTCG_ELEMENT
    {"ELEM_EARTH", 0},
    {"ELEM_WIND"},
    {"ELEM_FIRE"},
    {"ELEM_WATER"},
    {"ELEM_DARK"},
    {"ELEM_LIGHT"},
    {"ELEM_ANY"},       -- a FLAG, NOT a card-element

    -- ZTCG_ELEMENT (iTCG)
    {"ELEM_WARRIOR", 0},
    {"ELEM_MAGE"},
    {"ELEM_BOWMAN"},
    {"ELEM_THIEF"},
    {"ELEM_JOBLESS"},

    -- ZTCG_CALL
    {"CALL_ACTION", 0},
    {"CALL_CHAR_ACTION1"},
    {"CALL_CHAR_ACTION2"},
    {"CALL_CHAR_ACTION3"},

    -- ZTCG_COLORID
    {"COLOR_BLUE", 0},
    {"COLOR_RED"},
    {"COLOR_GREEN"},
    {"COLOR_GOLD"},
    {"COLOR_SILVER"},
    {"COLOR_WHITE"},
    {"COLOR_BLACK"},

    -- ZTCG_COMPARATOR
    {"LESSER", 0},
    {"GREATER"},

    -- ZTCG_PREVENTTYPE --
    {"PREVENT_ANY", 0},
    {"PREVENT_CHARONLY"},

    -- ZTCG_PLAYERMODE
    {"ONLY_ADVSRY", 1},
    {"ONLY_PLAYER"},
    {"ANY_PLAYER"},

    -- ZTCG_RECOVERTYPE
    {"RECOVER_ANY", -1},
    {"RECOVER_MOB"},
    {"RECOVER_EQP"},
    {"RECOVER_ACT"},
    {"RECOVER_FLD"},
    {"RECOVER_TOP"},

    -- ZTCG_ATKSRC
    {"ATKSRC_MOB", 0},
    {"ATKSRC_CHA"},
    {"ATKSRC_ACT"},
    {"ATKSRC_EQP"},
    {"ATKSRC_NIL"},

    -- ZTCG_ATKRES
    {"ATKRES_NIL", 0},
    {"ATKRES_DONT_HIT_CHAR"},
    {"ATKRES_DONT_HIT_MOBS"},
    {"ATKRES_FIXED_SLOT"},
    {"ATKRES_FIXED_SLOT_DAMAGE"},
    {"ATKRES_FIXED_DAMAGE"},
    {"ATKRES_NO_TARGET"},

    -- ZTCG_FIXEDTARGET
    {"SLOT_CHAR", 0},
    {"SLOT_MOB1"},
    {"SLOT_MOB2"},
    {"SLOT_MOB3"},
    {"SLOT_MOB4"},
    {"SLOT_MOB5"},
    {"SLOT_MOB6"},
    {"SLOT_MOB7"},

    -- ZTCG_PREVENT
    {"DISABLE_PREVENT", 0},
    {"ENABLE_PREVENT"},

    -- ZTCG_COUNTER
    {"IS_STARTER", 0},
    {"IS_COUNTER"},

    -- ZTCG_GLOBALMODE
    {"GLOBAL_HITCHAR", 0},
    {"GLOBAL_HITMOBS"},

    -- ZTCG_PEEK
    {"CARDLIST_HIDE", 0},
    {"CARDLIST_PEEK"},

    -- ZTCG_DECKORIENT
    {"DECK_TOP", 0},
    {"DECK_BOTTOM"},

    -- ZTCG_DECKMOVE
    {"TAKE_BYNAME", 0},
    {"TAKE_CARDID"},
    {"TAKE_NEXT"},
    {"PUT_TOP"},
    {"PUT_BOTTOM"},

    -- ZTCG_TRYPLAY
    {"IS_TRY_PREPARE", 0},
    {"IS_TRY_TABLE"},

    -- ZTCG_SCOUTMODE
    {"SCOUT_NORMAL", 0},
    {"SCOUT_SUMMON"},

    -- ZTCG_SUMMONMODE
    {"PLAY_NORMALSUMMON", 0},
    {"PLAY_SCOUTSUMMON"},
    {"PLAY_FORCESUMMON"},

    -- ZTCG_EQUIPMODE
    {"PLAY_NORMALEQUIP", 0},
    {"PLAY_GEARUPEQUIP"},
    {"PLAY_SCOUTEQUIP"},

    -- ZTCG_LOCATEMODE
    {"PLAY_NORMALFIELD", 0},
    {"PLAY_FIRSTCARDFIELD"},    --NOTE: this only plays a field if the first card of the hand is a FIELD-type.

    -- ZTCG_PLAYCARDMODE
    {"PLAY_MOB", 0},
    {"PLAY_EQUIP"},
    {"PLAY_ACTION"},
    {"PLAY_FIELD"},

    -- ZTCG_AURAMODE
    {"GLOBALAURA_PASS_PLAYER", 1},
    {"GLOBALAURA_PASS_ADVSRY"},
    {"GLOBALAURA_BOTH_PLAYERS"},

    -- ZTCG_DECKTYPE
    {"DECK_HAND", 0},
    {"DECK_DECK"},
    {"DECK_GRAV"},
    {"DECK_CARD"},

    -- ZTCG_TABLESLOTID
    {"SLOT_PLAYERCHAR", 0},
    {"SLOT_PLAYERMOB1"},
    {"SLOT_PLAYERMOB2"},
    {"SLOT_PLAYERMOB3"},
    {"SLOT_PLAYERMOB4"},
    {"SLOT_PLAYERMOB5"},
    {"SLOT_PLAYERMOB6"},
    {"SLOT_PLAYERMOB7"},
    {"SLOT_PLAYEREQP1"},
    {"SLOT_PLAYEREQP2"},
    {"SLOT_PLAYEREQP3"},
    {"SLOT_PLAYEREQP4"},
    {"SLOT_PLAYEREQP5"},
    {"SLOT_PLAYEREQP6"},
    {"SLOT_PLAYEREQP7"},
    {"SLOT_PLAYERFLD"},
    {"SLOT_ADVSRYCHAR"},
    {"SLOT_ADVSRYMOB1"},
    {"SLOT_ADVSRYMOB2"},
    {"SLOT_ADVSRYMOB3"},
    {"SLOT_ADVSRYMOB4"},
    {"SLOT_ADVSRYMOB5"},
    {"SLOT_ADVSRYMOB6"},
    {"SLOT_ADVSRYMOB7"},
    {"SLOT_ADVSRYEQP1"},
    {"SLOT_ADVSRYEQP2"},
    {"SLOT_ADVSRYEQP3"},
    {"SLOT_ADVSRYEQP4"},
    {"SLOT_ADVSRYEQP5"},
    {"SLOT_ADVSRYEQP6"},
    {"SLOT_ADVSRYEQP7"},
    {"SLOT_ADVSRYFLD"},

    -- ZTCG_TARGETTYPE --
    {"ATTACKED_CHAR", 0},
    {"ATTACKED_MOB"},

    -- ZTCG_SBOXTYPE --
    {"SBOX_MOB", 0},
    {"SBOX_CHAR"},
    {"SBOX_EQUIP"},

    -- ZTCG_FILTER --
    {"NO_FILTER", 0},
    {"USE_FILTER"},

    -- ZTCG_GAMEHUBTYPE --
    {"IS_P2", 0},
    {"IS_P1"},

    -- ZTCG_PLAYERTYPE --
    {"IS_ADVSRY", 0},
    {"IS_PLAYER"},

    -- ZTCG_ATTACKSTATE --
    {"THINK_ATTACK", 0},
    {"APPLY_ATTACK"},

    -- ZTCG_REMOVETYPE --
    {"IS_DESTROYED", 0},
    {"IS_DISCARDED"},

    -- ZTCG_BLOCKAURA --
    {"AURA_STUN", 0},
    {"AURA_SILENCE"},
    {"AURA_HIJACK"},
    {"AURA_AWAY"},

    -- ZTCG_BUFFMODE --
    {"BUFF_ANY", 0},
    {"BUFF_OTHER"},

    -- ZTCG_FLAGTYPE --
    {"FLAG_TYPE", 0},
    {"FLAG_ELEM"},

    -- ZTCG FLAGS index --
    {"ZTCG_COMPARATOR", 0},
    {"ZTCG_PLAYERMODE"},
    {"ZTCG_RECOVERTYPE"},
    {"ZTCG_ATKSRC"},
    {"ZTCG_ATKRES"},
    {"ZTCG_FIXEDTARGET"},
    {"ZTCG_PREVENT"},
    {"ZTCG_COUNTER"},
    {"ZTCG_GLOBALMODE"},
    {"ZTCG_PEEK"},
    {"ZTCG_DECKORIENT"},
    {"ZTCG_DECKMOVE"},
    {"ZTCG_TRYPLAY"},
    {"ZTCG_SCOUTMODE"},
    {"ZTCG_SUMMONMODE"},
    {"ZTCG_EQUIPMODE"},
    {"ZTCG_LOCATEMODE"},
    {"ZTCG_PLAYCARDMODE"},
    {"ZTCG_AURAMODE"},
    {"ZTCG_DECKTYPE"},
    {"ZTCG_TARGETTYPE"},
    {"ZTCG_SBOXTYPE"},
    {"ZTCG_FILTER"},
    {"ZTCG_GAMEHUBTYPE"},
    {"ZTCG_PLAYERTYPE"},
    {"ZTCG_ATTACKSTATE"},
    {"ZTCG_REMOVETYPE"},
    {"ZTCG_BLOCKAURA"},
    {"ZTCG_FLAGTYPE"},

    -- ZTCG_POINTCUTID --
    {"preventTargetCharacter", 1},
    {"preventTargetMob"},
    {"preventTargetEquip"},
    {"preventSelfTargetCharacter"},
    {"preventSelfTargetMob"},
    {"preventSelfTargetEquip"},
    {"preventIntercomeTargetCharacter"},
    {"preventIntercomeTargetMob"},
    {"preventIntercomeTargetEquip"},
    {"onPlayActionCancel"},
    {"onOpponentPlayActionCancel"},
    {"onPlayEquipCancel"},
    {"onOpponentPlayEquipCancel"},
    {"onPlayFieldCancel"},
    {"onOpponentPlayFieldCancel"},
    {"onPlayMobCancel"},
    {"onOpponentPlayMobCancel"},
    {"onGetTargeted"},
    {"onEquipBuff"},
    {"onEquipBuffWithCharge"},
    {"onEquipRefreshCharges"},
    {"onEquipBlockDamage"},
    {"onBlockResultDamage"},
    {"onOpponentBlockResultDamage"},
    {"undoBuffs"},
    {"applyBuffs"},
    {"onSelectMenu"},
    {"onSelectMenuCard"},
    {"onOpponentSelectMenuCard"},
    {"onRefresh"},
    {"onRefreshCard"},
    {"onOpponentRefreshCard"},
    {"onInterceptRefreshCard"},
    {"onInterceptOpponentRefreshCard"},
    {"onPickCardOrder"},
    {"onOpponentPickCardOrder"},
    {"onRecover"},
    {"onRecoverCard"},
    {"onOpponentRecoverCard"},
    {"onThrowCoin"},
    {"onOpponentThrowCoin"},
    {"onThrowCoinFixed"},
    {"onOpponentThrowCoinFixed"},
    {"onThrowDie"},
    {"onOpponentThrowDie"},
    {"onPlayRps"},
    {"onPrompt"},
    {"onOpponentPrompt"},
    {"onInterceptDrawCard"},
    {"onOpponentInterceptDrawCard"},
    {"onDraw"},
    {"onDrawCard"},
    {"onOpponentDrawCard"},
    {"onMoveToDiscardPile"},
    {"onCardMovedToDiscardPile"},
    {"onOpponentCardMovedToDiscardPile"},
    {"onDestroy"},
    {"onCardDestroyed"},
    {"onOpponentCardDestroyed"},
    {"onDiscard"},
    {"onDiscardCard"},
    {"onOpponentDiscardCard"},
    {"onReveal"},
    {"onRevealCard"},
    {"onOpponentRevealCard"},
    {"onRandomDiscard"},
    {"onRandomDiscardCard"},
    {"onOpponentRandomDiscardCard"},
    {"onPeek"},
    {"onPeekCard"},
    {"onOpponentPeekCard"},
    {"onReceiveStun"},
    {"onReceiveStunCard"},
    {"onOpponentReceiveStunCard"},
    {"onReceiveHijack"},
    {"onReceiveHijackCard"},
    {"onOpponentReceiveHijackCard"},
    {"onReceiveAway"},
    {"onReceiveAwayCard"},
    {"onOpponentReceiveAwayCard"},
    {"onReceiveSilence"},
    {"onReceiveSilenceCard"},
    {"onOpponentReceiveSilenceCard"},
    {"onEquipmentDestroyed"},
    {"onDestroyOpponentEquipment"},
    {"onDestroyedEquipment"},
    {"onCalcAttack"},
    {"onCalcAttackCard"},
    {"onOpponentCalcAttackCard"},
    {"onCalcDefense"},
    {"onCalcDefenseCard"},
    {"onOpponentCalcDefenseCard"},
    {"onStartAttack"},
    {"onOpponentStartAttack"},
    {"onExecuteNormalAttack"},
    {"onReceiveNormalAttack"},
    {"onReceiveAttackAndDestroyed"},
    {"onAttackOpponentMobDestroyed"},
    {"onAttackMobDestroyed"},
    {"onAttackOpponentEquipDestroyed"},
    {"onAttackEquipDestroyed"},
    {"onAttackOpponentCharacterDestroyed"},
    {"onAttackCharacterDestroyed"},
    {"onExecuteAttackAndInterceptDestroyed"},
    {"onReceiveAttackAndInterceptDestroyed"},
    {"onReceiveAttackAndSentToDiscardPile"},
    {"onMobSentToDiscardPile"},
    {"onOpponentMobSentToDiscardPile"},
    {"onEquipSentToDiscardPile"},
    {"onOpponentEquipSentToDiscardPile"},
    {"onLaunchAttack"},
    {"onInterceptAttack"},
    {"onApplyCounterAttack"},
    {"onExecuteAttackAndSurvived"},
    {"onReceiveAttackAndSurvived"},
    {"onExecuteAttack"},
    {"onReceiveAttack"},
    {"onExecuteAttackCard"},
    {"onReceiveAttackCard"},
    {"onExecuteAttackViewHand"},
    {"onExecuteAttackViewDeck"},
    {"onExecuteAttackViewGraveyard"},
    {"onReceiveAttackViewHand"},
    {"onReceiveAttackViewDeck"},
    {"onReceiveAttackViewGraveyard"},
    {"onCalcNextAttack"},
    {"onExecuteNextAttack"},
    {"onPlayCard"},
    {"onOpponentPlayCard"},
    {"onPlayCardViewHand"},
    {"onPlayCardViewDeck"},
    {"onPlayCardViewGraveyard"},
    {"onOpponentPlayCardViewHand"},
    {"onOpponentPlayCardViewDeck"},
    {"onOpponentPlayCardViewGraveyard"},
    {"onTakeFromHand"},
    {"onTakeFromDeck"},
    {"onTakeFromGraveyard"},
    {"onPutIntoHand"},
    {"onPutIntoDeck"},
    {"onPutIntoGraveyard"},
    {"onTakeCardFromHand"},
    {"onTakeCardFromDeck"},
    {"onTakeCardFromGraveyard"},
    {"onPutCardIntoHand"},
    {"onPutCardIntoDeck"},
    {"onPutCardIntoGraveyard"},
    {"onOpponentTakeCardFromHand"},
    {"onOpponentTakeCardFromDeck"},
    {"onOpponentTakeCardFromGraveyard"},
    {"onOpponentPutCardIntoHand"},
    {"onOpponentPutCardIntoDeck"},
    {"onOpponentPutCardIntoGraveyard"},
    {"onTryPlay"},
    {"onTryPlayAction"},
    {"onOpponentTryPlayAction"},
    {"onInitAction"},
    {"onInterceptPlayAction"},
    {"onInterceptOpponentPlayAction"},
    {"onThinkAction"},
    {"onPlayAction"},
    {"onOpponentPlayAction"},
    {"afterThinkAction"},
    {"onTryPlayEquipment"},
    {"onOpponentTryPlayEquipment"},
    {"onInitEquipment"},
    {"onInterceptPlayEquipment"},
    {"onInterceptOpponentPlayEquipment"},
    {"onThinkEquipment"},
    {"onPlayEquipment"},
    {"onOpponentPlayEquipment"},
    {"afterThinkEquipment"},
    {"onDestroyField"},
    {"onOpponentDestroyField"},
    {"onTryPlayField"},
    {"onOpponentTryPlayField"},
    {"onInitField"},
    {"onInterceptPlayField"},
    {"onInterceptOpponentPlayField"},
    {"onThinkField"},
    {"onPlayField"},
    {"onOpponentPlayField"},
    {"afterThinkField"},
    {"onTryPlayMob"},
    {"onOpponentTryPlayMob"},
    {"onInitMob"},
    {"onInterceptPlayMob"},
    {"onInterceptOpponentPlayMob"},
    {"onThinkMob"},
    {"onPlayMob"},
    {"onOpponentPlayMob"},
    {"afterThinkMob"},
    {"onPrepareStartTurn"},
    {"onOpponentPrepareStartTurn"},
    {"onStartTurn"},
    {"onOpponentStartTurn"},
    {"onStartTurnViewHand"},
    {"onStartTurnViewDeck"},
    {"onStartTurnViewGraveyard"},
    {"onOpponentStartTurnViewHand"},
    {"onOpponentStartTurnViewDeck"},
    {"onOpponentStartTurnViewGraveyard"},
    {"onStartCharacterActions"},
    {"onOpponentStartCharacterActions"},
    {"onRecoverStats"},
    {"onReactivateCardLevelDrop"},
    {"onReactivateCardEffects"},
    {"onOpponentReactivateCardEffects"},
    {"onStartCharacterActions2"},
    {"onOpponentStartCharacterActions2"},
    {"onEndTurn"},
    {"onOpponentEndTurn"},
    {"onInterceptCharacterAction"},
    {"onOpponentInterceptCharacterAction"},
    {"onLevelActionTrigger"},
    {"onLevelUp"},
    {"onOpponentLevelUp"},
    {"afterLevelUp"},
    {"afterOpponentLevelUp"},
    {"afterApplyCharacterAction"},
    {"afterOpponentApplyCharacterAction"},
    {"afterCharacterActions"},
    {"afterOpponentCharacterActions"},
    {"doRepeatLevelActionTrigger"},
    {"onActivateMobEffect"},
    {"onRecoverMobStats"},
    {"onActivateCharacterAction1"},
    {"onActivateCharacterAction2"},
    {"onActivateCharacterAction3"},
    {"onActivateCharacterAction"},
    {"onCheckPreventAttack"},

    -- ZTCG_CARDID --
    {"LINK", 1},
    {"GREAT_DEKUS_BLESS"},
    {"GOHMA"},
    {"GORON_TUNIC"},
    {"DARK_LINK"},
    {"DESERT_COLOSSUS"},
    {"LIKELIKE"},
    {"IMPA"},
    {"TWINROVA"},
    {"PIERRE"},
    {"BLUE_POTION"},
    {"FLARE_DANCER"},
    {"ADULT_WALLET"},
    {"GORON_BRACELET"},
    {"KOKIRI_FOREST"},
    {"GOLDEN_SCALE"},
    {"MASTER_SWORD"},
    {"GERUDO_GUARD"},
    {"BOMBCHU"},
    {"PRINCESS_ZELDA"},
    {"LIZALFOS"},
    {"HOOKSHOT"},
    {"YOUNG_LINK"},
    {"GANON"},
    {"SPIRIT_MEDALLION"},
    {"GORON_RUBY"},
    {"BONGOBONGO"},
    {"GUAY"},
    {"MOBLIN"},
    {"BAZAAR_SELLER"},
    {"KING_ZORA"},
    {"NABOORU"},
    {"ANUBIS"},
    {"DEAD_HAND"},
    {"DEATH_MT_CRATER"},
    {"HYRULE_CASTLE"},
    {"LAKE_HYLIA"},
    {"RAURU"},
    {"PHANTOM_GANON"},
    {"BIGOCTO"},
    {"TAILPASARAN"},
    {"GERUDO_FORTRESS"},
    {"CURSED_VILLAGER"},
    {"POE_SISTERS"},
    {"HYLIAN_SHIELD"},
    {"DEKU_SEEDS_BAG"},
    {"BLESS_OF_TRIFORCE"},
    {"SKULLTULAS_AMBUSH"},
    {"HEART_PIECE"},
    {"MILK_BOTTLE"},
    {"STINGER"},
    {"ZORAS_SAPPHIRE"},
    {"PEAHAT"},
    {"GOLD_SKULLTULA"},
    {"LARVA_GOHMA"},
    {"MAGIC_BEANS"},
    {"SMALL_KEY"},
    {"GREAT_DEKU_TREES_KNOWLEDGE"},
    {"BOMB_RAIN"},
    {"KAKARIKO_GRAVEYARD"},
    {"MIDO"},
    {"CUCCO_LADY"},
    {"FAIRYS_AID"},
    {"TRIPLE_SHOT"},
    {"DEKU_NUT"},
    {"DARK_PATHWAY"},
    {"MAGIC_JAR"},
    {"GIVE_AWAY"},
    {"ICE_ARROW"},
    {"PLAY_OCARINA"},
    {"OPEN_CHEST"},
    {"CRYSTAL_SWITCH"},
    {"RAZE"},
    {"DINS_FIRE"},
    {"MOUNTAIN_CLIMBING"},
    {"HORSE_RIDING"},
    {"_1_TON_ROCK_LIFTING"},
    {"OCTOROK"},
    {"JOELLE"},
    {"TORCH_SLUG"},
    {"SPIKE"},
    {"BOMB_BAG"},
    {"FAIRY_SLINGSHOT"},
    {"COMPASS"},
    {"GUILLOTINE"},
    {"SKULLWALLTULA"},
    {"BABY_DODONGO"},
    {"FABULOUS_FIVE_FROGGISH_TENORS"},
    {"LEEVER"},
    {"RED_TEKTITE"},
    {"BLUE_TEKTITE"},
    {"GRANNY"},
    {"WOLFOS"},
    {"SHABOM"},
    {"SILVER_GAUNTLETS"},
    {"WORLDS_FINEST_EYE_DROPS"},
    {"OCARINA_OF_TIME"},
    {"GOSSIP_STONE"},
    {"GANONS_CASTLE"},
    {"DUNGEON_MAP"},
    {"GERUDOS_MEMBERSHIP_CARD"},
    {"SHADOW_MERGE"},
    {"GOLDEN_GAUNTLETS"},
    {"MASK_OF_TRUTH"},
    {"WARP"},
    {"GIANT_LEEVER"},
    {"BIG_POE"},
    {"SKULL_MASK"},
    {"GANONDORF"},
    {"CHEST"},
    {"SKULL_KID"},
    {"PRINCESS_RUTO"},
    {"LIGHT_MEDALLION"},
    {"FIRE_ARROW"},
    {"JUMP_QUEST_WATER"},
    {"IRON_BOOTS"},
    {"MIRROR_SHIELD"},
    {"WHITE_WOLFOS"},
    {"WHIRLING_SCYTHES"},
    {"DARUNIA"},
    {"SUNSET"},
    {"CHANNELED_STRIKE"},
    {"PURPLE_RUPEE"},
    {"REDEAD"},
    {"BEAMOS"},
    {"IRON_KNUCKLES"},
    {"DODONGO"},
    {"FREEZARD"},
    {"BUSINESS_SCRUB"},
    {"JUMP_QUEST_WIND"},
    {"UNDERGROUND_SHELTER"},
    {"HOVER_BOOTS"},
    {"EPONA"},
    {"CLAIM_CHECK"},
    {"PURPLE_POE_REMNANT"},
    {"GREEN_POE_REMNANT"},
    {"FIRE_TEMPLE"},
    {"BIGGER_BOMB_BAG"},
    {"BOMB"},
    {"MALON"},
    {"BOOMERANG"},
    {"TRICKY_SHOT"},
    {"KOKIRI_TUNIC"},
    {"STALFOS"},
    {"BIG_DEKU_BABA"},
    {"FAIRY_FOUNTAIN"},
    {"MYSTIC_SPELL"},
    {"GREAT_FAIRYS_BLESS"},
    {"KEESE"},
    {"FAIRY_BOW"},
    {"GIANTS_KNIFE"},
    {"BARI"},
    {"BIRI"},
    {"PARASITIC_TENTACLE"},
    {"GIANT_STALCHILD"},
    {"DEKU_SHIELD"},
    {"ARMOS_STATUE"},
    {"SKULLTULA"},
    {"JUMP_QUEST_FIRE"},
    {"HOOKSHOT_CLIMBING"},
    {"VOLCANIC_OVERHEAT"},
    {"ICE_CAVERN"},
    {"VOLVAGIA"},
    {"DIMENSIONAL_RIFT"},
    {"CONCEAL"},
    {"LIGHT_ARROW"},
    {"MEGATON_HAMMER"},
    {"LAKE_SCIENTIST"},
    {"KOKIRI_SWORD"},
    {"POACHERS_SAW"},
    {"BIOELETRIC_CUBE"},
    {"ZORAS_FOUNTAIN"},
    {"ZORA_TUNIC"},
    {"GIANT_QUIVER"},
    {"FLYING_CARPET"},
    {"GORON"},
    {"CLUB_MOBLIN"},
    {"ICE_KEESE"},
    {"FIRE_KEESE"},
    {"WALLMASTER"},
    {"MAD_SCRUB"},
    {"BIGGORONS_SWORD"},
    {"HYRULE_FIELD"},
    {"BARINADE"},
    {"CUCCO"},
    {"POE"},
    {"TIME_WARP"},
    {"JUMP_QUEST_DARK"},
    {"FERRY_TO_THE_OTHER_WORLD"},
    {"SHELL_BLADE"},
    {"DINOLFOS"},
    {"KING_DODONGO"},
    {"MORPHA"},
    {"BIG_GUAY"},
    {"TEMPLE_OF_TIME"},
    {"DEKU_STICK"},
    {"MARKSMANSHIP"},
    {"POE_COLLECTOR"},
    {"STALCHILD"},
    {"SHEIK"},
    -- {"NEW_CARDS"},
    -- new cards created can be listed here.

    {"ZTCG_MAXVALUE", 999},
    {"ZTCG_DONTCARE", -1},
    {"ZTCG_NIL"},

    -- ###############################
    -- ## DO NOT MODIFY THESE ENUMS ##
    -- ###############################


    -- \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/

    -- you can insert new enums here, usable in your own files

    {"ZTCG_DUMMY", -1},
    {"ZTCG_ZERO"},      -- if not specified, value is of the next integer

    -- /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\

    {"ZTCG_UNDEFINED" , -1}
}
