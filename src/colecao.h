#ifndef COLECAO_H_INCLUDED
#define COLECAO_H_INCLUDED

struct COLECAO {
    struct Card *link;
    struct Card *great_dekus_bless;
    struct Card *gohma;
    struct Card *goron_tunic;
    struct Card *dark_link;
    struct Card *desert_colossus;
    struct Card *likelike;
    struct Card *impa;
    struct Card *twinrova;
    struct Card *pierre;
    struct Card *blue_potion;
    struct Card *flare_dancer;
    struct Card *adult_wallet;
    struct Card *goron_bracelet;
    struct Card *kokiri_forest;
    struct Card *golden_scale;
    struct Card *master_sword;
    struct Card *gerudo_guard;
    struct Card *bombchu;
    struct Card *princess_zelda;
    struct Card *lizalfos;
    struct Card *hookshot;
    struct Card *young_link;
    struct Card *ganon;
    struct Card *spirit_medallion;
    struct Card *goron_ruby;
    struct Card *bongobongo;
    struct Card *guay;
    struct Card *moblin;
    struct Card *bazaar_seller;
    struct Card *king_zora;
    struct Card *nabooru;
    struct Card *anubis;
    struct Card *dead_hand;
    struct Card *death_mt_crater;
    struct Card *hyrule_castle;
    struct Card *lake_hylia;
    struct Card *rauru;
    struct Card *phantom_ganon;
    struct Card *bigocto;
    struct Card *tailpasaran;
    struct Card *gerudo_fortress;
    struct Card *cursed_villager;
    struct Card *poe_sisters;
    struct Card *hylian_shield;
    struct Card *deku_seeds_bag;
    struct Card *bless_of_triforce;
    struct Card *skulltulas_ambush;
    struct Card *heart_piece;
    struct Card *milk_bottle;
    struct Card *stinger;
    struct Card *zoras_sapphire;
    struct Card *peahat;
    struct Card *gold_skulltula;
    struct Card *larva_gohma;
    struct Card *magic_beans;
    struct Card *small_key;
    struct Card *great_deku_trees_knowledge;
    struct Card *bomb_rain;
    struct Card *kakariko_graveyard;
    struct Card *mido;
    struct Card *cucco_lady;
    struct Card *fairys_aid;
    struct Card *triple_shot;
    struct Card *deku_nut;
    struct Card *dark_pathway;
    struct Card *magic_jar;
    struct Card *give_away;
    struct Card *ice_arrow;
    struct Card *play_ocarina;
    struct Card *open_chest;
    struct Card *crystal_switch;
    struct Card *raze;
    struct Card *dins_fire;
    struct Card *mountain_climbing;
    struct Card *horse_riding;
    struct Card *_1_ton_rock_lifting;
    struct Card *octorok;
    struct Card *joelle;
    struct Card *torch_slug;
    struct Card *spike;
    struct Card *bomb_bag;
    struct Card *fairy_slingshot;
    struct Card *compass;
    struct Card *guillotine;
    struct Card *skullwalltula;
    struct Card *baby_dodongo;
    struct Card *fabulous_five_froggish_tenors;
    struct Card *leever;
    struct Card *red_tektite;
    struct Card *blue_tektite;
    struct Card *granny;
    struct Card *wolfos;
    struct Card *shabom;
    struct Card *silver_gauntlets;
    struct Card *worlds_finest_eye_drops;
    struct Card *ocarina_of_time;
    struct Card *gossip_stone;
    struct Card *ganons_castle;
    struct Card *dungeon_map;
    struct Card *gerudos_membership_card;
    struct Card *shadow_merge;
    struct Card *golden_gauntlets;
    struct Card *mask_of_truth;
    struct Card *warp;
    struct Card *giant_leever;
    struct Card *big_poe;
    struct Card *skull_mask;
    struct Card *ganondorf;
    struct Card *chest;
    struct Card *skull_kid;
    struct Card *princess_ruto;
    struct Card *light_medallion;
    struct Card *fire_arrow;
    struct Card *jump_quest_water;
    struct Card *iron_boots;
    struct Card *mirror_shield;
    struct Card *white_wolfos;
    struct Card *whirling_scythes;
    struct Card *darunia;
    struct Card *sunset;
    struct Card *channeled_strike;
    struct Card *purple_rupee;
    struct Card *redead;
    struct Card *beamos;
    struct Card *iron_knuckles;
    struct Card *dodongo;
    struct Card *freezard;
    struct Card *business_scrub;
    struct Card *jump_quest_wind;
    struct Card *underground_shelter;
    struct Card *hover_boots;
    struct Card *epona;
    struct Card *claim_check;
    struct Card *purple_poe_remnant;
    struct Card *green_poe_remnant;
    struct Card *fire_temple;
    struct Card *bigger_bomb_bag;
    struct Card *bomb;
    struct Card *malon;
    struct Card *boomerang;
    struct Card *tricky_shot;
    struct Card *kokiri_tunic;
    struct Card *stalfos;
    struct Card *big_deku_baba;
    struct Card *fairy_fountain;
    struct Card *mystic_spell;
    struct Card *great_fairys_bless;
    struct Card *keese;

    int quantidade;
};

enum {
    LINK = 1,
    GREAT_DEKUS_BLESS,
    GOHMA,
    GORON_TUNIC,
    DARK_LINK,
    DESERT_COLOSSUS,
    LIKELIKE,
    IMPA,
    TWINROVA,
    PIERRE,
    BLUE_POTION,
    FLARE_DANCER,
    ADULT_WALLET,
    GORON_BRACELET,
    KOKIRI_FOREST,
    GOLDEN_SCALE,
    MASTER_SWORD,
    GERUDO_GUARD,
    BOMBCHU,
    PRINCESS_ZELDA,
    LIZALFOS,
    HOOKSHOT,
    YOUNG_LINK,
    GANON,
    SPIRIT_MEDALLION,
    GORON_RUBY,
    BONGOBONGO,
    GUAY,
    MOBLIN,
    BAZAAR_SELLER,
    KING_ZORA,
    NABOORU,
    ANUBIS,
    DEAD_HAND,
    DEATH_MT_CRATER,
    HYRULE_CASTLE,
    LAKE_HYLIA,
    RAURU,
    PHANTOM_GANON,
    BIGOCTO,
    TAILPASARAN,
    GERUDO_FORTRESS,
    CURSED_VILLAGER,
    POE_SISTERS,
    HYLIAN_SHIELD,
    DEKU_SEEDS_BAG,
    BLESS_OF_TRIFORCE,
    SKULLTULAS_AMBUSH,
    HEART_PIECE,
    MILK_BOTTLE,
    STINGER,
    ZORAS_SAPPHIRE,
    PEAHAT,
    GOLD_SKULLTULA,
    LARVA_GOHMA,
    MAGIC_BEANS,
    SMALL_KEY,
    GREAT_DEKU_TREES_KNOWLEDGE,
    BOMB_RAIN,
    KAKARIKO_GRAVEYARD,
    MIDO,
    CUCCO_LADY,
    FAIRYS_AID,
    TRIPLE_SHOT,
    DEKU_NUT,
    DARK_PATHWAY,
    MAGIC_JAR,
    GIVE_AWAY,
    ICE_ARROW,
    PLAY_OCARINA,
    OPEN_CHEST,
    CRYSTAL_SWITCH,
    RAZE,
    DINS_FIRE,
    MOUNTAIN_CLIMBING,
    HORSE_RIDING,
    _1_TON_ROCK_LIFTING,
    OCTOROK,
    JOELLE,
    TORCH_SLUG,
    SPIKE,
    BOMB_BAG,
    FAIRY_SLINGSHOT,
    COMPASS,
    GUILLOTINE,
    SKULLWALLTULA,
    BABY_DODONGO,
    FABULOUS_FIVE_FROGGISH_TENORS,
    LEEVER,
    RED_TEKTITE,
    BLUE_TEKTITE,
    GRANNY,
    WOLFOS,
    SHABOM,
    SILVER_GAUNTLETS,
    WORLDS_FINEST_EYE_DROPS,
    OCARINA_OF_TIME,
    GOSSIP_STONE,
    GANONS_CASTLE,
    DUNGEON_MAP,
    GERUDOS_MEMBERSHIP_CARD,
    SHADOW_MERGE,
    GOLDEN_GAUNTLETS,
    MASK_OF_TRUTH,
    WARP,
    GIANT_LEEVER,
    BIG_POE,
    SKULL_MASK,
    GANONDORF,
    CHEST,
    SKULL_KID,
    PRINCESS_RUTO,
    LIGHT_MEDALLION,
    FIRE_ARROW,
    JUMP_QUEST_WATER,
    IRON_BOOTS,
    MIRROR_SHIELD,
    WHITE_WOLFOS,
    WHIRLING_SCYTHES,
    DARUNIA,
    SUNSET,
    CHANNELED_STRIKE,
    PURPLE_RUPEE,
    REDEAD,
    BEAMOS,
    IRON_KNUCKLES,
    DODONGO,
    FREEZARD,
    BUSINESS_SCRUB,
    JUMP_QUEST_WIND,
    UNDERGROUND_SHELTER,
    HOVER_BOOTS,
    EPONA,
    CLAIM_CHECK,
    PURPLE_POE_REMNANT,
    GREEN_POE_REMNANT,
    FIRE_TEMPLE,
    BIGGER_BOMB_BAG,
    BOMB,
    MALON,
    BOOMERANG,
    TRICKY_SHOT,
    KOKIRI_TUNIC,
    STALFOS,
    BIG_DEKU_BABA,
    FAIRY_FOUNTAIN,
    MYSTIC_SPELL,
    GREAT_FAIRYS_BLESS,
    KEESE,

    UNDEFINED
};

#endif // COLECAO_H_INCLUDED
