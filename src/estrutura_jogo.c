#ifndef ESTRUTURA_JOGO_C_INCLUDED
#define ESTRUTURA_JOGO_C_INCLUDED

int ConverteNomeParaId(char *nome,struct COLECAO *colecao) {
    int card;

    if(strcmp(nome,"Link") == 0) card = colecao->link->colecao;
    else if(strcmp(nome,"Great Dekus Bless") == 0) card = colecao->great_dekus_bless->colecao;
    else if(strcmp(nome,"GOHMA, Parasitic Armored Arachnid") == 0) card = colecao->gohma->colecao;
    else if(strcmp(nome,"Goron Tunic") == 0) card = colecao->goron_tunic->colecao;
    else if(strcmp(nome,"Dark Link") == 0) card = colecao->dark_link->colecao;
    else if(strcmp(nome,"Desert Colossus") == 0) card = colecao->desert_colossus->colecao;
    else if(strcmp(nome,"Like-Like") == 0) card = colecao->likelike->colecao;
    else if(strcmp(nome,"Impa") == 0) card = colecao->impa->colecao;
    else if(strcmp(nome,"TWINROVA, Sorceress Sisters") == 0) card = colecao->twinrova->colecao;
    else if(strcmp(nome,"Pierre, the Scarecrow") == 0) card = colecao->pierre->colecao;
    else if(strcmp(nome,"Blue Potion") == 0) card = colecao->blue_potion->colecao;
    else if(strcmp(nome,"Flare Dancer") == 0) card = colecao->flare_dancer->colecao;
    else if(strcmp(nome,"Adult Wallet") == 0) card = colecao->adult_wallet->colecao;
    else if(strcmp(nome,"Goron Bracelet") == 0) card = colecao->goron_bracelet->colecao;
    else if(strcmp(nome,"Kokiri Forest") == 0) card = colecao->kokiri_forest->colecao;
    else if(strcmp(nome,"Golden Scale") == 0) card = colecao->golden_scale->colecao;
    else if(strcmp(nome,"Master Sword") == 0) card = colecao->master_sword->colecao;
    else if(strcmp(nome,"Gerudo Guard") == 0) card = colecao->gerudo_guard->colecao;
    else if(strcmp(nome,"Bombchu") == 0) card = colecao->bombchu->colecao;
    else if(strcmp(nome,"Princess Zelda") == 0) card = colecao->princess_zelda->colecao;
    else if(strcmp(nome,"Lizalfos") == 0) card = colecao->lizalfos->colecao;
    else if(strcmp(nome,"Hookshot") == 0) card = colecao->hookshot->colecao;
    else if(strcmp(nome,"Young Link") == 0) card = colecao->young_link->colecao;
    else if(strcmp(nome,"GANON") == 0) card = colecao->ganon->colecao;
    else if(strcmp(nome,"Spirit Medallion") == 0) card = colecao->spirit_medallion->colecao;
    else if(strcmp(nome,"Goron Ruby") == 0) card = colecao->goron_ruby->colecao;
    else if(strcmp(nome,"BONGO-BONGO, Phantom Shadow Beast") == 0) card = colecao->bongobongo->colecao;
    else if(strcmp(nome,"Guay") == 0) card = colecao->guay->colecao;
    else if(strcmp(nome,"Moblin") == 0) card = colecao->moblin->colecao;
    else if(strcmp(nome,"Bazaar Seller") == 0) card = colecao->bazaar_seller->colecao;
    else if(strcmp(nome,"King Zora") == 0) card = colecao->king_zora->colecao;
    else if(strcmp(nome,"Nabooru") == 0) card = colecao->nabooru->colecao;
    else if(strcmp(nome,"Anubis") == 0) card = colecao->anubis->colecao;
    else if(strcmp(nome,"Dead Hand") == 0) card = colecao->dead_hand->colecao;
    else if(strcmp(nome,"Death Mt. Crater") == 0) card = colecao->death_mt_crater->colecao;
    else if(strcmp(nome,"Hyrule Castle") == 0) card = colecao->hyrule_castle->colecao;
    else if(strcmp(nome,"Lake Hylia") == 0) card = colecao->lake_hylia->colecao;
    else if(strcmp(nome,"Rauru") == 0) card = colecao->rauru->colecao;
    else if(strcmp(nome,"PHANTOM GANON, Evil Spirit from Beyond") == 0) card = colecao->phantom_ganon->colecao;
    else if(strcmp(nome,"Bigocto") == 0) card = colecao->bigocto->colecao;
    else if(strcmp(nome,"Tailpasaran") == 0) card = colecao->tailpasaran->colecao;
    else if(strcmp(nome,"Gerudos Fortress") == 0) card = colecao->gerudo_fortress->colecao;
    else if(strcmp(nome,"Cursed Villager") == 0) card = colecao->cursed_villager->colecao;
    else if(strcmp(nome,"Poe Sisters") == 0) card = colecao->poe_sisters->colecao;
    else if(strcmp(nome,"Hylian Shield") == 0) card = colecao->hylian_shield->colecao;
    else if(strcmp(nome,"Deku Seeds Bag") == 0) card = colecao->deku_seeds_bag->colecao;
    else if(strcmp(nome,"Bless of Triforce") == 0) card = colecao->bless_of_triforce->colecao;
    else if(strcmp(nome,"Skulltulas Ambush") == 0) card = colecao->skulltulas_ambush->colecao;
    else if(strcmp(nome,"Heart Piece") == 0) card = colecao->heart_piece->colecao;
    else if(strcmp(nome,"Milk Bottle") == 0) card = colecao->milk_bottle->colecao;
    else if(strcmp(nome,"Stinger") == 0) card = colecao->stinger->colecao;
    else if(strcmp(nome,"Zoras Sapphire") == 0) card = colecao->zoras_sapphire->colecao;
    else if(strcmp(nome,"Peahat") == 0) card = colecao->peahat->colecao;
    else if(strcmp(nome,"Gold Skulltula") == 0) card = colecao->gold_skulltula->colecao;
    else if(strcmp(nome,"Larva Gohma") == 0) card = colecao->larva_gohma->colecao;
    else if(strcmp(nome,"Magic Beans") == 0) card = colecao->magic_beans->colecao;
    else if(strcmp(nome,"Small Key") == 0) card = colecao->small_key->colecao;
    else if(strcmp(nome,"Great Deku Trees Knowledge") == 0) card = colecao->great_deku_trees_knowledge->colecao;
    else if(strcmp(nome,"Bomb Rain") == 0) card = colecao->bomb_rain->colecao;
    else if(strcmp(nome,"Kakariko Graveyard") == 0) card = colecao->kakariko_graveyard->colecao;
    else if(strcmp(nome,"Mido") == 0) card = colecao->mido->colecao;
    else if(strcmp(nome,"Cucco Lady") == 0) card = colecao->cucco_lady->colecao;
    else if(strcmp(nome,"Fairys Aid") == 0) card = colecao->fairys_aid->colecao;
    else if(strcmp(nome,"Triple Shot") == 0) card = colecao->triple_shot->colecao;
    else if(strcmp(nome,"Deku Nut") == 0) card = colecao->deku_nut->colecao;
    else if(strcmp(nome,"Dark Pathway") == 0) card = colecao->dark_pathway->colecao;
    else if(strcmp(nome,"Magic Jar") == 0) card = colecao->magic_jar->colecao;
    else if(strcmp(nome,"Give Away") == 0) card = colecao->give_away->colecao;
    else if(strcmp(nome,"Ice Arrow") == 0) card = colecao->ice_arrow->colecao;
    else if(strcmp(nome,"Play Ocarina") == 0) card = colecao->play_ocarina->colecao;
    else if(strcmp(nome,"Open Chest") == 0) card = colecao->open_chest->colecao;
    else if(strcmp(nome,"Crystal Switch") == 0) card = colecao->crystal_switch->colecao;
    else if(strcmp(nome,"Raze") == 0) card = colecao->raze->colecao;
    else if(strcmp(nome,"Dins Fire") == 0) card = colecao->dins_fire->colecao;
    else if(strcmp(nome,"Mountain Climbing") == 0) card = colecao->mountain_climbing->colecao;
    else if(strcmp(nome,"Horse Riding") == 0) card = colecao->horse_riding->colecao;
    else if(strcmp(nome,"1 Ton Rock Lifting") == 0) card = colecao->_1_ton_rock_lifting->colecao;
    else if(strcmp(nome,"Octorok") == 0) card = colecao->octorok->colecao;
    else if(strcmp(nome,"Joelle") == 0) card = colecao->joelle->colecao;
    else if(strcmp(nome,"Torch Slug") == 0) card = colecao->torch_slug->colecao;
    else if(strcmp(nome,"Spike") == 0) card = colecao->spike->colecao;
    else if(strcmp(nome,"Bomb Bag") == 0) card = colecao->bomb_bag->colecao;
    else if(strcmp(nome,"Fairy Slingshot") == 0) card = colecao->fairy_slingshot->colecao;
    else if(strcmp(nome,"Compass") == 0) card = colecao->compass->colecao;
    else if(strcmp(nome,"Guillotine") == 0) card = colecao->guillotine->colecao;
    else if(strcmp(nome,"Skullwalltula") == 0) card = colecao->skullwalltula->colecao;
    else if(strcmp(nome,"Baby Dodongo") == 0) card = colecao->baby_dodongo->colecao;
    else if(strcmp(nome,"Fabulous Five Froggish Tenors") == 0) card = colecao->fabulous_five_froggish_tenors->colecao;
    else if(strcmp(nome,"Leever") == 0) card = colecao->leever->colecao;
    else if(strcmp(nome,"Red Tektite") == 0) card = colecao->red_tektite->colecao;
    else if(strcmp(nome,"Blue Tektite") == 0) card = colecao->blue_tektite->colecao;
    else if(strcmp(nome,"Granny") == 0) card = colecao->granny->colecao;
    else if(strcmp(nome,"Wolfos") == 0) card = colecao->wolfos->colecao;
    else if(strcmp(nome,"Shabom") == 0) card = colecao->shabom->colecao;
    else if(strcmp(nome,"Silver Gauntlets") == 0) card = colecao->silver_gauntlets->colecao;
    else if(strcmp(nome,"Worlds Finest Eye Drops") == 0) card = colecao->worlds_finest_eye_drops->colecao;
    else if(strcmp(nome,"Ocarina of Time") == 0) card = colecao->ocarina_of_time->colecao;
    else if(strcmp(nome,"Gossip Stone") == 0) card = colecao->gossip_stone->colecao;
    else if(strcmp(nome,"Ganons Castle") == 0) card = colecao->ganons_castle->colecao;
    else if(strcmp(nome,"Dungeon Map") == 0) card = colecao->dungeon_map->colecao;
    else if(strcmp(nome,"Gerudos Membership Card") == 0) card = colecao->gerudos_membership_card->colecao;
    else if(strcmp(nome,"Shadow Merge") == 0) card = colecao->shadow_merge->colecao;
    else if(strcmp(nome,"Golden Gauntlets") == 0) card = colecao->golden_gauntlets->colecao;
    else if(strcmp(nome,"Mask of Truth") == 0) card = colecao->mask_of_truth->colecao;
    else if(strcmp(nome,"Warp") == 0) card = colecao->warp->colecao;
    else if(strcmp(nome,"Giant Leever") == 0) card = colecao->giant_leever->colecao;
    else if(strcmp(nome,"Big Poe") == 0) card = colecao->big_poe->colecao;
    else if(strcmp(nome,"Skull Mask") == 0) card = colecao->skull_mask->colecao;
    else if(strcmp(nome,"Ganondorf") == 0) card = colecao->ganondorf->colecao;
    else if(strcmp(nome,"Chest") == 0) card = colecao->chest->colecao;
    else if(strcmp(nome,"Skull Kid") == 0) card = colecao->skull_kid->colecao;
    else if(strcmp(nome,"Princess Ruto") == 0) card = colecao->princess_ruto->colecao;
    else if(strcmp(nome,"Light Medallion") == 0) card = colecao->light_medallion->colecao;
    else if(strcmp(nome,"Fire Arrow") == 0) card = colecao->fire_arrow->colecao;
    else if(strcmp(nome,"Jump Quest (Water)") == 0) card = colecao->jump_quest_water->colecao;
    else if(strcmp(nome,"Iron Boots") == 0) card = colecao->iron_boots->colecao;
    else if(strcmp(nome,"Mirror Shield") == 0) card = colecao->mirror_shield->colecao;
    else if(strcmp(nome,"White Wolfos") == 0) card = colecao->white_wolfos->colecao;
    else if(strcmp(nome,"Whirling Scythes") == 0) card = colecao->whirling_scythes->colecao;
    else if(strcmp(nome,"Darunia") == 0) card = colecao->darunia->colecao;
    else if(strcmp(nome,"Sunset") == 0) card = colecao->sunset->colecao;
    else if(strcmp(nome,"Channeled Strike") == 0) card = colecao->channeled_strike->colecao;
    else if(strcmp(nome,"Purple Rupee") == 0) card = colecao->purple_rupee->colecao;
    else if(strcmp(nome,"ReDead") == 0) card = colecao->redead->colecao;
    else if(strcmp(nome,"Beamos") == 0) card = colecao->beamos->colecao;
    else if(strcmp(nome,"Iron Knuckles") == 0) card = colecao->iron_knuckles->colecao;
    else if(strcmp(nome,"Dodongo") == 0) card = colecao->dodongo->colecao;
    else if(strcmp(nome,"Freezard") == 0) card = colecao->freezard->colecao;
    else if(strcmp(nome,"Business Scrub") == 0) card = colecao->business_scrub->colecao;
    else if(strcmp(nome,"Jump Quest (Wind)") == 0) card = colecao->jump_quest_wind->colecao;
    else if(strcmp(nome,"Underground Shelter") == 0) card = colecao->underground_shelter->colecao;
    else if(strcmp(nome,"Hover Boots") == 0) card = colecao->hover_boots->colecao;
    else if(strcmp(nome,"Epona") == 0) card = colecao->epona->colecao;
    else if(strcmp(nome,"Claim Check") == 0) card = colecao->claim_check->colecao;
    else if(strcmp(nome,"Purple Poe Remnant") == 0) card = colecao->purple_poe_remnant->colecao;
    else if(strcmp(nome,"Green Poe Remnant") == 0) card = colecao->green_poe_remnant->colecao;
    else if(strcmp(nome,"Fire Temple") == 0) card = colecao->fire_temple->colecao;
    else if(strcmp(nome,"Bigger Bomb Bag") == 0) card = colecao->bigger_bomb_bag->colecao;
    else if(strcmp(nome,"Bomb") == 0) card = colecao->bomb->colecao;
    else if(strcmp(nome,"Malon") == 0) card = colecao->malon->colecao;
    else if(strcmp(nome,"Boomerang") == 0) card = colecao->boomerang->colecao;
    else if(strcmp(nome,"Tricky Shot") == 0) card = colecao->tricky_shot->colecao;
    else if(strcmp(nome,"Kokiri Tunic") == 0) card = colecao->kokiri_tunic->colecao;
    else if(strcmp(nome,"Stalfos") == 0) card = colecao->stalfos->colecao;
    else if(strcmp(nome,"Big Deku Baba") == 0) card = colecao->big_deku_baba->colecao;
    else if(strcmp(nome,"Fairy Fountain") == 0) card = colecao->fairy_fountain->colecao;
    else if(strcmp(nome,"Mystic Spell") == 0) card = colecao->mystic_spell->colecao;
    else if(strcmp(nome,"Great Fairys Bless") == 0) card = colecao->great_fairys_bless->colecao;
    else if(strcmp(nome,"Keese") == 0) card = colecao->keese->colecao;
    else if(strcmp(nome,"Fairy Bow") == 0) card = colecao->fairy_bow->colecao;
    else if(strcmp(nome,"Giants Knife") == 0) card = colecao->giants_knife->colecao;
    else if(strcmp(nome,"Bari") == 0) card = colecao->bari->colecao;
    else if(strcmp(nome,"Biri") == 0) card = colecao->biri->colecao;

    else {
        card = -1;
        printf("_PARSE ERROR: '%s'\n",nome);
        system("pause");
    }

    return(card);
}

void CarregaCard(int id,struct Card **card_carregado,struct COLECAO *colecao) {
    struct Card *card = NULL;

    //ponto de funcao #16

    if(id == LINK) card = colecao->link;
    else if(id == GREAT_DEKUS_BLESS) card = colecao->great_dekus_bless;
    else if(id == GOHMA) card = colecao->gohma;
    else if(id == GORON_TUNIC) card = colecao->goron_tunic;
    else if(id == DARK_LINK) card = colecao->dark_link;
    else if(id == DESERT_COLOSSUS) card = colecao->desert_colossus;
    else if(id == LIKELIKE) card = colecao->likelike;
    else if(id == IMPA) card = colecao->impa;
    else if(id == TWINROVA) card = colecao->twinrova;
    else if(id == PIERRE) card = colecao->pierre;
    else if(id == BLUE_POTION) card = colecao->blue_potion;
    else if(id == FLARE_DANCER) card = colecao->flare_dancer;
    else if(id == ADULT_WALLET) card = colecao->adult_wallet;
    else if(id == GORON_BRACELET) card = colecao->goron_bracelet;
    else if(id == KOKIRI_FOREST) card = colecao->kokiri_forest;
    else if(id == GOLDEN_SCALE) card = colecao->golden_scale;
    else if(id == MASTER_SWORD) card = colecao->master_sword;
    else if(id == GERUDO_GUARD) card = colecao->gerudo_guard;
    else if(id == BOMBCHU) card = colecao->bombchu;
    else if(id == PRINCESS_ZELDA) card = colecao->princess_zelda;
    else if(id == LIZALFOS) card = colecao->lizalfos;
    else if(id == HOOKSHOT) card = colecao->hookshot;
    else if(id == YOUNG_LINK) card = colecao->young_link;
    else if(id == GANON) card = colecao->ganon;
    else if(id == SPIRIT_MEDALLION) card = colecao->spirit_medallion;
    else if(id == GORON_RUBY) card = colecao->goron_ruby;
    else if(id == BONGOBONGO) card = colecao->bongobongo;
    else if(id == GUAY) card = colecao->guay;
    else if(id == MOBLIN) card = colecao->moblin;
    else if(id == BAZAAR_SELLER) card = colecao->bazaar_seller;
    else if(id == KING_ZORA) card = colecao->king_zora;
    else if(id == NABOORU) card = colecao->nabooru;
    else if(id == ANUBIS) card = colecao->anubis;
    else if(id == DEAD_HAND) card = colecao->dead_hand;
    else if(id == DEATH_MT_CRATER) card = colecao->death_mt_crater;
    else if(id == HYRULE_CASTLE) card = colecao->hyrule_castle;
    else if(id == LAKE_HYLIA) card = colecao->lake_hylia;
    else if(id == RAURU) card = colecao->rauru;
    else if(id == PHANTOM_GANON) card = colecao->phantom_ganon;
    else if(id == BIGOCTO) card = colecao->bigocto;
    else if(id == TAILPASARAN) card = colecao->tailpasaran;
    else if(id == GERUDO_FORTRESS) card = colecao->gerudo_fortress;
    else if(id == CURSED_VILLAGER) card = colecao->cursed_villager;
    else if(id == POE_SISTERS) card = colecao->poe_sisters;
    else if(id == HYLIAN_SHIELD) card = colecao->hylian_shield;
    else if(id == DEKU_SEEDS_BAG) card = colecao->deku_seeds_bag;
    else if(id == BLESS_OF_TRIFORCE) card = colecao->bless_of_triforce;
    else if(id == SKULLTULAS_AMBUSH) card = colecao->skulltulas_ambush;
    else if(id == HEART_PIECE) card = colecao->heart_piece;
    else if(id == MILK_BOTTLE) card = colecao->milk_bottle;
    else if(id == STINGER) card = colecao->stinger;
    else if(id == ZORAS_SAPPHIRE) card = colecao->zoras_sapphire;
    else if(id == PEAHAT) card = colecao->peahat;
    else if(id == GOLD_SKULLTULA) card = colecao->gold_skulltula;
    else if(id == LARVA_GOHMA) card = colecao->larva_gohma;
    else if(id == MAGIC_BEANS) card = colecao->magic_beans;
    else if(id == SMALL_KEY) card = colecao->small_key;
    else if(id == GREAT_DEKU_TREES_KNOWLEDGE) card = colecao->great_deku_trees_knowledge;
    else if(id == BOMB_RAIN) card = colecao->bomb_rain;
    else if(id == KAKARIKO_GRAVEYARD) card = colecao->kakariko_graveyard;
    else if(id == MIDO) card = colecao->mido;
    else if(id == CUCCO_LADY) card = colecao->cucco_lady;
    else if(id == FAIRYS_AID) card = colecao->fairys_aid;
    else if(id == TRIPLE_SHOT) card = colecao->triple_shot;
    else if(id == DEKU_NUT) card = colecao->deku_nut;
    else if(id == DARK_PATHWAY) card = colecao->dark_pathway;
    else if(id == MAGIC_JAR) card = colecao->magic_jar;
    else if(id == GIVE_AWAY) card = colecao->give_away;
    else if(id == ICE_ARROW) card = colecao->ice_arrow;
    else if(id == PLAY_OCARINA) card = colecao->play_ocarina;
    else if(id == OPEN_CHEST) card = colecao->open_chest;
    else if(id == CRYSTAL_SWITCH) card = colecao->crystal_switch;
    else if(id == RAZE) card = colecao->raze;
    else if(id == DINS_FIRE) card = colecao->dins_fire;
    else if(id == MOUNTAIN_CLIMBING) card = colecao->mountain_climbing;
    else if(id == HORSE_RIDING) card = colecao->horse_riding;
    else if(id == _1_TON_ROCK_LIFTING) card = colecao->_1_ton_rock_lifting;
    else if(id == OCTOROK) card = colecao->octorok;
    else if(id == JOELLE) card = colecao->joelle;
    else if(id == TORCH_SLUG) card = colecao->torch_slug;
    else if(id == SPIKE) card = colecao->spike;
    else if(id == BOMB_BAG) card = colecao->bomb_bag;
    else if(id == FAIRY_SLINGSHOT) card = colecao->fairy_slingshot;
    else if(id == COMPASS) card = colecao->compass;
    else if(id == GUILLOTINE) card = colecao->guillotine;
    else if(id == SKULLWALLTULA) card = colecao->skullwalltula;
    else if(id == BABY_DODONGO) card = colecao->baby_dodongo;
    else if(id == FABULOUS_FIVE_FROGGISH_TENORS) card = colecao->fabulous_five_froggish_tenors;
    else if(id == LEEVER) card = colecao->leever;
    else if(id == RED_TEKTITE) card = colecao->red_tektite;
    else if(id == BLUE_TEKTITE) card = colecao->blue_tektite;
    else if(id == GRANNY) card = colecao->granny;
    else if(id == WOLFOS) card = colecao->wolfos;
    else if(id == SHABOM) card = colecao->shabom;
    else if(id == SILVER_GAUNTLETS) card = colecao->silver_gauntlets;
    else if(id == WORLDS_FINEST_EYE_DROPS) card = colecao->worlds_finest_eye_drops;
    else if(id == OCARINA_OF_TIME) card = colecao->ocarina_of_time;
    else if(id == GOSSIP_STONE) card = colecao->gossip_stone;
    else if(id == GANONS_CASTLE) card = colecao->ganons_castle;
    else if(id == DUNGEON_MAP) card = colecao->dungeon_map;
    else if(id == GERUDOS_MEMBERSHIP_CARD) card = colecao->gerudos_membership_card;
    else if(id == SHADOW_MERGE) card = colecao->shadow_merge;
    else if(id == GOLDEN_GAUNTLETS) card = colecao->golden_gauntlets;
    else if(id == MASK_OF_TRUTH) card = colecao->mask_of_truth;
    else if(id == WARP) card = colecao->warp;
    else if(id == GIANT_LEEVER) card = colecao->giant_leever;
    else if(id == BIG_POE) card = colecao->big_poe;
    else if(id == SKULL_MASK) card = colecao->skull_mask;
    else if(id == GANONDORF) card = colecao->ganondorf;
    else if(id == CHEST) card = colecao->chest;
    else if(id == SKULL_KID) card = colecao->skull_kid;
    else if(id == PRINCESS_RUTO) card = colecao->princess_ruto;
    else if(id == LIGHT_MEDALLION) card = colecao->light_medallion;
    else if(id == FIRE_ARROW) card = colecao->fire_arrow;
    else if(id == JUMP_QUEST_WATER) card = colecao->jump_quest_water;
    else if(id == IRON_BOOTS) card = colecao->iron_boots;
    else if(id == MIRROR_SHIELD) card = colecao->mirror_shield;
    else if(id == WHITE_WOLFOS) card = colecao->white_wolfos;
    else if(id == WHIRLING_SCYTHES) card = colecao->whirling_scythes;
    else if(id == DARUNIA) card = colecao->darunia;
    else if(id == SUNSET) card = colecao->sunset;
    else if(id == CHANNELED_STRIKE) card = colecao->channeled_strike;
    else if(id == PURPLE_RUPEE) card = colecao->purple_rupee;
    else if(id == REDEAD) card = colecao->redead;
    else if(id == BEAMOS) card = colecao->beamos;
    else if(id == IRON_KNUCKLES) card = colecao->iron_knuckles;
    else if(id == DODONGO) card = colecao->dodongo;
    else if(id == FREEZARD) card = colecao->freezard;
    else if(id == BUSINESS_SCRUB) card = colecao->business_scrub;
    else if(id == JUMP_QUEST_WIND) card = colecao->jump_quest_wind;
    else if(id == UNDERGROUND_SHELTER) card = colecao->underground_shelter;
    else if(id == HOVER_BOOTS) card = colecao->hover_boots;
    else if(id == EPONA) card = colecao->epona;
    else if(id == CLAIM_CHECK) card = colecao->claim_check;
    else if(id == PURPLE_POE_REMNANT) card = colecao->purple_poe_remnant;
    else if(id == GREEN_POE_REMNANT) card = colecao->green_poe_remnant;
    else if(id == FIRE_TEMPLE) card = colecao->fire_temple;
    else if(id == BIGGER_BOMB_BAG) card = colecao->bigger_bomb_bag;
    else if(id == BOMB) card = colecao->bomb;
    else if(id == MALON) card = colecao->malon;
    else if(id == BOOMERANG) card = colecao->boomerang;
    else if(id == TRICKY_SHOT) card = colecao->tricky_shot;
    else if(id == KOKIRI_TUNIC) card = colecao->kokiri_tunic;
    else if(id == STALFOS) card = colecao->stalfos;
    else if(id == BIG_DEKU_BABA) card = colecao->big_deku_baba;
    else if(id == FAIRY_FOUNTAIN) card = colecao->fairy_fountain;
    else if(id == MYSTIC_SPELL) card = colecao->mystic_spell;
    else if(id == GREAT_FAIRYS_BLESS) card = colecao->great_fairys_bless;
    else if(id == KEESE) card = colecao->keese;
    else if(id == FAIRY_BOW) card = colecao->fairy_bow;
    else if(id == GIANTS_KNIFE) card = colecao->giants_knife;
    else if(id == BARI) card = colecao->bari;
    else if(id == BIRI) card = colecao->biri;

//    else if(id == ) card->origem = colecao-;
    //VAI CARREGAR NO JOGOS TODOS OS CARDS QUE TIVEREM O NOME CORRESPONDENTE!
    if(card == NULL) {
        printf("ERRO ID: _%d\n",id);
        system("pause");
    }
    *card_carregado = card;
}

void ImprimeMao(struct Player *jogador) {
    struct Deck *aux,*aux2;

    aux = jogador->hand->inicio;
    if(aux == NULL) return;

    printf("---------- %s DECK ---------------\n",jogador->nome_prof);
    printf("Qte: %d\n",jogador->hand->quantidade);
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        printf("%s\n",aux2->card->origem->nome);
    }
    printf("----- FIM DE DECK ----------------\n");
}

void DefineCharAction(struct char_action *ant,struct char_action *dest,struct CARD *card_origem,struct char_action *origem) {
    dest->acao = origem->acao;
    dest->atrib = origem->atrib;
    dest->nivel = origem->nivel;

    dest->card = card_origem;
    dest->goron_bracelet_bool = false;

    dest->ant = ant;
    dest->prox = (struct char_action *)malloc(sizeof(struct char_action));
    dest->prox->prox = NULL;
}

void LevelUp(struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *lv_prompt,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,struct Player *jogador,struct Player *adversario,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {    //OK
    bool toggle = false;
    struct Coordenadas *lista,*aux,*aux2 = NULL;
    struct char_action *act,*act2 = NULL;
    struct Deck *aux3,*aux4;
    ALLEGRO_BITMAP *temp;

    printf("LEVELUP ");
    lista = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
    lista->prox = NULL;

    AtualizaMesa(true,NULL,-1,2,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
    if(*fim == true) return;

    temp = al_clone_bitmap(al_get_backbuffer(display));
    if(lista->prox == NULL) return;

    printf("1 ");
    while(1) {  //lvlup prompt
        al_clear_to_color(al_map_rgb_f(0, 0, 0));
        al_draw_tinted_bitmap(temp, al_map_rgba_f(0.3, 0.3, 0.3, 0.3),0, 0, 0);
        al_draw_bitmap(lv_prompt,140,225,0);

        al_flip_display();

        VerificaEventos(sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if(*mouse == true && *posX >= 155 && *posX < 365 && *posY >= 300 && *posY < 345) break;
        else if(*mouse2 == true || (*mouse == true && *posX >= 425 && *posX < 635 && *posY >= 300 && *posY < 345)) {
            AtualizaMesa(true,NULL,-1,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
            return;
        }
    }
    printf("2 ");
    al_draw_bitmap(temp,0,0,0);
    al_destroy_bitmap(temp);
    //al_rest(0.2);

    printf("3 ");
    while(1) {
        if(*mouse2 == true) return;
        if(*mouse == true) {
            aux = lista;
            while(aux->prox != NULL) {
                if(*posX >= aux->x && *posX < aux->x + 30 && *posY >= aux->y && *posY < aux->y + 150) {
                    toggle = true;
                    break;
                }

                aux2 = aux;
                aux = aux->prox;
            }
            if(toggle == true) break;
            if(aux2 != NULL && *posX >= aux2->x && *posX < aux2->x + 100 && *posY >= aux2->y && *posY < aux2->y + 150) {
                *posX = aux2->x;
                break;
            }
        }

        AtualizaMesa(true,"Choose a card to level up... (right click to skip)",-1,2,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
        if(*fim == true) return;
    }

    printf("4 ");
    act = jogador->character_actions;
    while(act->prox != NULL) {
        act2 = act;
        act = act->prox;
    }

    aux4 = NULL;
    aux3 = jogador->hand->inicio;
    while(!(*posX >= aux3->card->PosicaoX && *posX < aux3->card->PosicaoX + 30 && *posY >= aux3->card->PosicaoY && *posY < aux3->card->PosicaoY + 150)) {
        aux4 = aux3;
        aux3 = aux3->prox;
    }

    printf("5 ");
    DefineCharAction(act2,act,aux3->card,aux3->card->origem->lv_acao);

    if (strcmp(aux3->card->origem->elemento,"Earth") == 0)        jogador->earth_ic++;
    else if (strcmp(aux3->card->origem->elemento,"Wind") == 0)    jogador->wind_ic++;
    else if (strcmp(aux3->card->origem->elemento,"Fire") == 0)    jogador->fire_ic++;
    else if (strcmp(aux3->card->origem->elemento,"Water") == 0)   jogador->water_ic++;
    else if (strcmp(aux3->card->origem->elemento,"Dark") == 0)    jogador->dark_ic++;
    else jogador->light_ic++;

    printf("6 ");
    if(aux4 != NULL) aux4->prox = aux3->prox;    //retira uma carta da mao do jogador, que foi inserida no character dele!
    else jogador->hand->inicio = aux3->prox;   //aux4 torna-se a nova carta inicial da lista, uma vez utilizada aux3.

    jogador->hand->quantidade--;

    aux = lista;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);

    printf("7 ");
    if(*(jogador->HP) + 20 > *(jogador->MaxHP)) {
        *(jogador->MaxHP) = *(jogador->MaxHP) + 40;
        *(jogador->HP) = *(jogador->HP) + 40;
    }
    else *(jogador->HP) = *(jogador->HP) + 20;
    jogador->level = jogador->level + 10;

    printf("Executa Gatilho...");
    if(act->nivel == 999) ExecutaGatilho(-1,act->acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_menu,pont,fundo_carta,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    printf(" OK!\n");

    free(aux3);
    AtualizaMesa(true,NULL,-1,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
}

void RecuperaEquipStats_DepoisLevelUp(struct CARD **card,struct Card **buffer,bool *fim,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,int *rolagem,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(*fim == true || *card == NULL) return;

    if((*card)->origem->colecao == GORON_BRACELET) goron_bracelet_acao(3,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if((*card)->origem->colecao == CHEST) chest_acao(*card,-1,buffer,fim,ko,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void EfeitoMeio(struct Card **buffer,bool *fim,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,int *rolagem,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool ko = false;
    RecuperaEquipStats_DepoisLevelUp(&(jogador->mesa->equip1),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaEquipStats_DepoisLevelUp(&(jogador->mesa->equip2),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaEquipStats_DepoisLevelUp(&(jogador->mesa->equip3),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaEquipStats_DepoisLevelUp(&(jogador->mesa->equip4),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaEquipStats_DepoisLevelUp(&(jogador->mesa->equip5),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaEquipStats_DepoisLevelUp(&(jogador->mesa->equip6),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RecuperaEquipStats_DepoisLevelUp(&(jogador->mesa->equip7),buffer,fim,&ko,sbox,jogador,adversario,rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

bool AplicaAcao(struct char_action *acao,int cont,struct Card **buffer,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *lock,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *prompt,bool *fim_de_jogo,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *escolhe_tipo,struct VariaveisTACTIC *tactics,ALLEGRO_TIMER *timer,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool ativo = false;

    ativo = DetectaAcao(acao->acao,cont,buffer,jogador->mesa->character,rolagem,sbox,selecao,lock,roll_bar,prompt,fim_de_jogo,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,apontador,escolhe_tipo,jogador->var_tactic,timer,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->var_tactic->princess_ruto_bool == true) {
        princess_ruto_acao(cont,buffer,rolagem,sbox,selecao,lock,roll_bar,prompt,fim_de_jogo,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,apontador,escolhe_tipo,jogador->var_tactic,timer,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        jogador->var_tactic->princess_ruto_bool = false;
    }

    return(ativo);
}

void Equip_CharAction(struct CARD *equip,struct Card **buffer,bool *fim_de_jogo,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *prompt,struct Player *jogador,struct Player *adversario,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_DISPLAY *display,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int val;

    if(equip != NULL) {
        if(equip->origem->colecao == PURPLE_POE_REMNANT) {
            printf("ATTACK: purple poe remnant\n");
            val = TotalMobsEmCampo(jogador,adversario,1);

            if(val > 0) Attack(-1,true,false,buffer,fim_de_jogo,rolagem,ko,0,3,0,sbox,jogador,adversario,equip,NULL,20*val,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }

        else if(equip->origem->colecao == GREEN_POE_REMNANT) {
            printf("ATTACK: green poe remnant\n");
            val = TotalEquipsEmCampo(jogador,adversario,1);

            if(val > 0) Attack(-1,true,false,buffer,fim_de_jogo,rolagem,ko,0,3,0,sbox,jogador,adversario,equip,NULL,10*val,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
    }
}

void CharacterActions(struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *lock,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *prompt,struct Player *jogador,struct Player *adversario,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_DISPLAY *display,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *escolhe_tipo,ALLEGRO_TIMER *timer,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct char_action *acao;
    int cont = 0;
    bool ativo = false,ko;

    acao = jogador->character_actions;
    //comeca as acoes
    printf("\n----------------------\nACOES:::::::\n");
    while(acao->prox != NULL) {
        if(*fim_de_jogo == true) return;

        if(acao->nivel <= jogador->level && ((strcmp(acao->card->origem->elemento,"Earth") == 0 && acao->atrib <= jogador->earth_ic) || (strcmp(acao->card->origem->elemento,"Wind") == 0 && acao->atrib <= jogador->wind_ic) || (strcmp(acao->card->origem->elemento,"Fire") == 0 && acao->atrib <= jogador->fire_ic) || (strcmp(acao->card->origem->elemento,"Water") == 0 && acao->atrib <= jogador->water_ic) || (strcmp(acao->card->origem->elemento,"Light") == 0 && acao->atrib <= jogador->light_ic) || (strcmp(acao->card->origem->elemento,"Dark") == 0 && acao->atrib <= jogador->dark_ic))) {
            printf("%s (%d / %s)\n",acao->acao,acao->atrib,acao->card->origem->elemento);

            ativo = AplicaAcao(acao,cont,buffer,rolagem,sbox,selecao,lock,roll_bar,prompt,fim_de_jogo,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,pont,escolhe_tipo,jogador->var_tactic,timer,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            if(acao->goron_bracelet_bool) {
                printf("GORON BRACELET -> %s (%d / %s)\n",acao->acao,acao->atrib,acao->card->origem->elemento);
                ativo = (AplicaAcao(acao,cont,buffer,rolagem,sbox,selecao,lock,roll_bar,prompt,fim_de_jogo,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,pont,escolhe_tipo,jogador->var_tactic,timer,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer) || ativo);
            }

            if(PossuiIronBoots(jogador) && ativo == true) {
                jogador->var_tactic->iron_boots_cont -= 1;
                printf("DECREMENTOU ACAO :: (%d)\n",jogador->var_tactic->iron_boots_cont);
            }
        }
        acao = acao->prox;
        cont++;
    }
    printf("\nFIM_ACOES...\n");

    for(cont = 0; cont < jogador->var_tactic->channeled_strike_cont; cont++) {
        printf("ATTACK: channeled strike\n");
        Attack(-1,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,jogador->mesa->character,NULL,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    Equip_CharAction(jogador->mesa->equip1,buffer,fim_de_jogo,rolagem,&ko,sbox,selecao,roll_bar,prompt,jogador,adversario,fundo,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    Equip_CharAction(jogador->mesa->equip2,buffer,fim_de_jogo,rolagem,&ko,sbox,selecao,roll_bar,prompt,jogador,adversario,fundo,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    Equip_CharAction(jogador->mesa->equip3,buffer,fim_de_jogo,rolagem,&ko,sbox,selecao,roll_bar,prompt,jogador,adversario,fundo,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    Equip_CharAction(jogador->mesa->equip4,buffer,fim_de_jogo,rolagem,&ko,sbox,selecao,roll_bar,prompt,jogador,adversario,fundo,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    Equip_CharAction(jogador->mesa->equip5,buffer,fim_de_jogo,rolagem,&ko,sbox,selecao,roll_bar,prompt,jogador,adversario,fundo,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    Equip_CharAction(jogador->mesa->equip6,buffer,fim_de_jogo,rolagem,&ko,sbox,selecao,roll_bar,prompt,jogador,adversario,fundo,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    Equip_CharAction(jogador->mesa->equip7,buffer,fim_de_jogo,rolagem,&ko,sbox,selecao,roll_bar,prompt,jogador,adversario,fundo,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    printf("Char. act OK!\n");
}

void MonsterActions(int id_acao,struct Card **buffer,bool *ko,int modo,struct CARD *monstro,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,int *rolagem,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *coin_prompt,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *fim_de_jogo,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(monstro == NULL) return;
    if(*fim_de_jogo == true) return;

    *ko = false;
    //modo: 1-> efeitos de jogador, 2-> adversario
    /*::: PONTO DE FUNCAO #7 ::: */
    if(modo == 1) {
        if(monstro->origem->colecao == PIERRE && monstro->turn_silenced == 0) pierre_acao(fim_de_jogo,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,jogador,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(monstro->origem->colecao == GOHMA && monstro->turn_silenced == 0 && monstro->HP <= 60 && jogador->earth_ic >= 3 && jogador->level >= 60) gohma_acao(buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(monstro->origem->colecao == BIG_POE && monstro->turn_silenced == 0 && monstro->HP <= 50) big_poe_acao(monstro,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(monstro->origem->colecao == TWINROVA && monstro->turn_silenced == 0) twinrova_acao1(id_acao,buffer,fim_de_jogo,monstro,rolagem,ko,sbox,selecao,roll_bar,coin_prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,prompt,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(monstro->origem->colecao == WOLFOS && monstro->turn_silenced == 0) AdicionaNovaQuantidadeAtaque(&(monstro->var_monster->lista_qte_ataques),monstro,2);
        if(monstro->origem->colecao == GANON && monstro->turn_silenced == 0 && jogador->level >= 100 && jogador->dark_ic >= 3) ganon_acao(id_acao,buffer,fim_de_jogo,monstro,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(monstro->origem->colecao == BONGOBONGO && monstro->turn_silenced == 0 && jogador->level >= 70 && jogador->dark_ic >= 2) bongobongo_acao2(id_acao,buffer,fim_de_jogo,rolagem,ko,sbox,jogador,adversario,monstro,display,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,prompt,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(monstro->origem->colecao == DEAD_HAND && monstro->turn_silenced == 0) dead_hand_acao2(id_acao,buffer,monstro,NULL,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(monstro->origem->colecao == PHANTOM_GANON && monstro->turn_silenced == 0) phantom_ganon_acao(buffer,fim_de_jogo,rolagem,ko,sbox,jogador,adversario,monstro,display,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,prompt,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(monstro->origem->colecao == PEAHAT && monstro->turn_silenced == 0 && monstro->HP <= 70) {
            int peahat_cont = jogador->wind_ic;

            while(peahat_cont > 0) {
                Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,0,0,0,sbox,jogador,adversario,monstro,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                peahat_cont--;
            }
        }
        if(monstro->origem->colecao == WHITE_WOLFOS && monstro->turn_silenced == 0) AdicionaNovaQuantidadeAtaque(&(monstro->var_monster->lista_qte_ataques),monstro,3);
    }

    if(monstro->var_monster->spike_bool == false && monstro->turn_cooldown == 0) monstro->turn_cooldown = 1;
}

void MonsterAttacks(int id_acao,struct Card **buffer,bool* fim_de_jogo,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,int *rolagem,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *coin_prompt,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *apontador,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool ko,ataque_disponivel,ehCharacter,ehJogador;
    struct CARD *alvo;

    MonsterActions(id_acao,buffer,&ko,1,jogador->mesa->monstro1,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions(id_acao,buffer,&ko,1,jogador->mesa->monstro2,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions(id_acao,buffer,&ko,1,jogador->mesa->monstro3,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions(id_acao,buffer,&ko,1,jogador->mesa->monstro4,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions(id_acao,buffer,&ko,1,jogador->mesa->monstro5,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions(id_acao,buffer,&ko,1,jogador->mesa->monstro6,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions(id_acao,buffer,&ko,1,jogador->mesa->monstro7,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions(id_acao,buffer,&ko,2,adversario->mesa->monstro1,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions(id_acao,buffer,&ko,2,adversario->mesa->monstro2,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions(id_acao,buffer,&ko,2,adversario->mesa->monstro3,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions(id_acao,buffer,&ko,2,adversario->mesa->monstro4,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions(id_acao,buffer,&ko,2,adversario->mesa->monstro5,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions(id_acao,buffer,&ko,2,adversario->mesa->monstro6,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterActions(id_acao,buffer,&ko,2,adversario->mesa->monstro7,sbox,jogador,adversario,display,rolagem,selecao,roll_bar,apontador,coin_prompt,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,fim_de_jogo,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    //al_rest(0.15);
    printf("\n----------------- HP STATS --------------------------\n");
    if(jogador->mesa->monstro1 != NULL) printf("M1 -> HP: %d / %d\n",jogador->mesa->monstro1->HP,jogador->mesa->monstro1->MaxHP);
    if(jogador->mesa->monstro2 != NULL) printf("M2 -> HP: %d / %d\n",jogador->mesa->monstro2->HP,jogador->mesa->monstro2->MaxHP);
    if(jogador->mesa->monstro3 != NULL) printf("M3 -> HP: %d / %d\n",jogador->mesa->monstro3->HP,jogador->mesa->monstro3->MaxHP);
    if(jogador->mesa->monstro4 != NULL) printf("M4 -> HP: %d / %d\n",jogador->mesa->monstro4->HP,jogador->mesa->monstro4->MaxHP);
    if(jogador->mesa->monstro5 != NULL) printf("M5 -> HP: %d / %d\n",jogador->mesa->monstro5->HP,jogador->mesa->monstro5->MaxHP);
    if(jogador->mesa->monstro6 != NULL) printf("M6 -> HP: %d / %d\n",jogador->mesa->monstro6->HP,jogador->mesa->monstro6->MaxHP);
    if(jogador->mesa->monstro7 != NULL) printf("M7 -> HP: %d / %d\n",jogador->mesa->monstro7->HP,jogador->mesa->monstro7->MaxHP);

    if(adversario->mesa->monstro1 != NULL) printf("AdvM1 -> HP: %d / %d\n",adversario->mesa->monstro1->HP,adversario->mesa->monstro1->MaxHP);
    if(adversario->mesa->monstro2 != NULL) printf("AdvM2 -> HP: %d / %d\n",adversario->mesa->monstro2->HP,adversario->mesa->monstro2->MaxHP);
    if(adversario->mesa->monstro3 != NULL) printf("AdvM3 -> HP: %d / %d\n",adversario->mesa->monstro3->HP,adversario->mesa->monstro3->MaxHP);
    if(adversario->mesa->monstro4 != NULL) printf("AdvM4 -> HP: %d / %d\n",adversario->mesa->monstro4->HP,adversario->mesa->monstro4->MaxHP);
    if(adversario->mesa->monstro5 != NULL) printf("AdvM5 -> HP: %d / %d\n",adversario->mesa->monstro5->HP,adversario->mesa->monstro5->MaxHP);
    if(adversario->mesa->monstro6 != NULL) printf("AdvM6 -> HP: %d / %d\n",adversario->mesa->monstro6->HP,adversario->mesa->monstro6->MaxHP);
    if(adversario->mesa->monstro7 != NULL) printf("AdvM7 -> HP: %d / %d\n",adversario->mesa->monstro7->HP,adversario->mesa->monstro7->MaxHP);
    printf("\n-----------------------------------------------------\n");

    do {
        ataque_disponivel = false;
        alvo = NULL;

        if(*mouse == true) {
            if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro1->var_monster->lista_qte_ataques) && jogador->mesa->monstro1->turn_cooldown == 0 && (jogador->mesa->monstro1->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
                if(*posX >= 300 && *posX < 300 + 50 && *posY >= 270 && *posY < 270 + 75) {
                    SlotMonsterTurn(id_acao,buffer,jogador->mesa->monstro1,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,prompt,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                }
            }

            if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro2->var_monster->lista_qte_ataques) && jogador->mesa->monstro2->turn_cooldown == 0 && (jogador->mesa->monstro2->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
                if(*posX >= 355 && *posX < 355 + 50 && *posY >= 270 && *posY < 270 + 75) {
                    SlotMonsterTurn(id_acao,buffer,jogador->mesa->monstro2,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,prompt,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                }
            }

            if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro3->var_monster->lista_qte_ataques) && jogador->mesa->monstro3->turn_cooldown == 0 && (jogador->mesa->monstro3->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
                if(*posX >= 410 && *posX < 410 + 50 && *posY >= 270 && *posY < 270 + 75) {
                    SlotMonsterTurn(id_acao,buffer,jogador->mesa->monstro3,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,prompt,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                }
            }

            if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro4->var_monster->lista_qte_ataques) && jogador->mesa->monstro4->turn_cooldown == 0 && (jogador->mesa->monstro4->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
                if(*posX >= 465 && *posX < 465 + 50 && *posY >= 270 && *posY < 270 + 75) {
                    SlotMonsterTurn(id_acao,buffer,jogador->mesa->monstro4,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,prompt,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                }
            }

            if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro5->var_monster->lista_qte_ataques) && jogador->mesa->monstro5->turn_cooldown == 0 && (jogador->mesa->monstro5->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
                if(*posX >= 520 && *posX < 520 + 50 && *posY >= 270 && *posY < 270 + 75) {
                    SlotMonsterTurn(id_acao,buffer,jogador->mesa->monstro5,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,prompt,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                }
            }

            if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro6->var_monster->lista_qte_ataques) && jogador->mesa->monstro6->turn_cooldown == 0 && (jogador->mesa->monstro6->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
                if(*posX >= 575 && *posX < 575 + 50 && *posY >= 270 && *posY < 270 + 75) {
                    SlotMonsterTurn(id_acao,buffer,jogador->mesa->monstro6,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,prompt,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                }
            }

            if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro7->var_monster->lista_qte_ataques) && jogador->mesa->monstro7->turn_cooldown == 0 && (jogador->mesa->monstro7->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
                if(*posX >= 630 && *posX < 630 + 50 && *posY >= 270 && *posY < 270 + 75) {
                    SlotMonsterTurn(id_acao,buffer,jogador->mesa->monstro7,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,prompt,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                }
            }
        }

        AtualizaMesa(false,"Select a monster to attack",id_acao,-1,0,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,apontador,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
        if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro1->var_monster->lista_qte_ataques) && jogador->mesa->monstro1->turn_cooldown == 0 && (jogador->mesa->monstro1->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
            al_draw_tinted_rotated_bitmap(sbox->offense_icon,al_map_rgba_f(0.5,0.5,0.5,0.5), 0, 0, 298, 310, -ALLEGRO_PI/4, 0);
            ataque_disponivel = true;
        }

        if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro2->var_monster->lista_qte_ataques) && jogador->mesa->monstro2->turn_cooldown == 0 && (jogador->mesa->monstro2->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
            al_draw_tinted_rotated_bitmap(sbox->offense_icon,al_map_rgba_f(0.5,0.5,0.5,0.5), 0, 0, 353, 310, -ALLEGRO_PI/4, 0);
            ataque_disponivel = true;
        }

        if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro3->var_monster->lista_qte_ataques) && jogador->mesa->monstro3->turn_cooldown == 0 && (jogador->mesa->monstro3->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
            al_draw_tinted_rotated_bitmap(sbox->offense_icon,al_map_rgba_f(0.5,0.5,0.5,0.5), 0, 0, 408, 310, -ALLEGRO_PI/4, 0);
            ataque_disponivel = true;
        }

        if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro4->var_monster->lista_qte_ataques) && jogador->mesa->monstro4->turn_cooldown == 0 && (jogador->mesa->monstro4->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
            al_draw_tinted_rotated_bitmap(sbox->offense_icon,al_map_rgba_f(0.5,0.5,0.5,0.5), 0, 0, 463, 310, -ALLEGRO_PI/4, 0);
            ataque_disponivel = true;
        }

        if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro5->var_monster->lista_qte_ataques) && jogador->mesa->monstro5->turn_cooldown == 0 && (jogador->mesa->monstro5->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
            al_draw_tinted_rotated_bitmap(sbox->offense_icon,al_map_rgba_f(0.5,0.5,0.5,0.5), 0, 0, 518, 310, -ALLEGRO_PI/4, 0);
            ataque_disponivel = true;
        }

        if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro6->var_monster->lista_qte_ataques) && jogador->mesa->monstro6->turn_cooldown == 0 && (jogador->mesa->monstro6->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
            al_draw_tinted_rotated_bitmap(sbox->offense_icon,al_map_rgba_f(0.5,0.5,0.5,0.5), 0, 0, 573, 310, -ALLEGRO_PI/4, 0);
            ataque_disponivel = true;
        }

        if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->var_monster->qte_ataques < RetornaMaiorQuantidadeAtaques(jogador->mesa->monstro7->var_monster->lista_qte_ataques) && jogador->mesa->monstro7->turn_cooldown == 0 && (jogador->mesa->monstro7->var_monster->dead_hand_bool == false || DHneutralizado(adversario))) {
            al_draw_tinted_rotated_bitmap(sbox->offense_icon,al_map_rgba_f(0.5,0.5,0.5,0.5), 0, 0, 628, 310, -ALLEGRO_PI/4, 0);
            ataque_disponivel = true;
        }


        if(*posX >= 245 && *posX < 245 + 50 && *posY >= 110 && *posY < 110 + 75) {
            alvo = jogador->mesa->character;
            ehJogador = true;
        }
        else if(*posX >= 300 && *posX < 300 + 50 && *posY >= 270 && *posY < 270 + 75) {
            alvo = jogador->mesa->monstro1;
            ehJogador = true;
        }
        else if(*posX >= 355 && *posX < 355 + 50 && *posY >= 270 && *posY < 270 + 75) {
            alvo = jogador->mesa->monstro2;
            ehJogador = true;
        }
        else if(*posX >= 410 && *posX < 410 + 50 && *posY >= 270 && *posY < 270 + 75) {
            alvo = jogador->mesa->monstro3;
            ehJogador = true;
        }
        else if(*posX >= 465 && *posX < 465 + 50 && *posY >= 270 && *posY < 270 + 75) {
            alvo = jogador->mesa->monstro4;
            ehJogador = true;
        }
        else if(*posX >= 520 && *posX < 520 + 50 && *posY >= 270 && *posY < 270 + 75) {
            alvo = jogador->mesa->monstro5;
            ehJogador = true;
        }
        else if(*posX >= 575 && *posX < 575 + 50 && *posY >= 270 && *posY < 270 + 75) {
            alvo = jogador->mesa->monstro6;
            ehJogador = true;
        }
        else if(*posX >= 630 && *posX < 630 + 50 && *posY >= 270 && *posY < 270 + 75) {
            alvo = jogador->mesa->monstro7;
            ehJogador = true;
        }

        else if(*posX >= 685 && *posX < 685 + 50 && *posY >= 110 && *posY < 110 + 75) {
            alvo = adversario->mesa->character;
            ehJogador = false;
        }
        else if(*posX >= 300 && *posX < 300 + 50 && *posY >= 190 && *posY < 190 + 75) {
            alvo = adversario->mesa->monstro1;
            ehJogador = false;
        }
        else if(*posX >= 355 && *posX < 355 + 50 && *posY >= 190 && *posY < 190 + 75) {
            alvo = adversario->mesa->monstro2;
            ehJogador = false;
        }
        else if(*posX >= 410 && *posX < 410 + 50 && *posY >= 190 && *posY < 190 + 75) {
            alvo = adversario->mesa->monstro3;
            ehJogador = false;
        }
        else if(*posX >= 465 && *posX < 465 + 50 && *posY >= 190 && *posY < 190 + 75) {
            alvo = adversario->mesa->monstro4;
            ehJogador = false;
        }
        else if(*posX >= 520 && *posX < 520 + 50 && *posY >= 190 && *posY < 190 + 75) {
            alvo = adversario->mesa->monstro5;
            ehJogador = false;
        }
        else if(*posX >= 575 && *posX < 575 + 50 && *posY >= 190 && *posY < 190 + 75) {
            alvo = adversario->mesa->monstro6;
            ehJogador = false;
        }
        else if(*posX >= 630 && *posX < 630 + 50 && *posY >= 190 && *posY < 190 + 75) {
            alvo = adversario->mesa->monstro7;
            ehJogador = false;
        }

        if(alvo != NULL) {
            if(alvo->origem->character != NULL) ehCharacter = true;
            else ehCharacter = false;

            if(ehJogador) StatusBox(ehCharacter,true,NULL,alvo,sbox,*posX,*posY,jogador,adversario,font2,font,color,-1,-1);
            else StatusBox(ehCharacter,false,NULL,alvo,sbox,*posX,*posY,adversario,jogador,font2,font,color,-1,-1);
        }
        al_flip_display();

    } while(ataque_disponivel == true && *mouse2 == false && *fim_de_jogo == false);
}

void TestaEspaco(struct CARD *card) {
    if(card != NULL) printf("%s\n",card->origem->nome);
    else printf("NULL\n");
}

void ImprimeMesa(struct Player *jogador) {
    printf("\n------------------\nLevel: %d\tHP: %d / %d\n\nMESA\n",jogador->level,*(jogador->HP),*(jogador->MaxHP));
    printf("Character: ");
    TestaEspaco(jogador->mesa->character);
    printf("Monsters:\n");
    TestaEspaco(jogador->mesa->monstro1);
    TestaEspaco(jogador->mesa->monstro2);
    TestaEspaco(jogador->mesa->monstro3);
    TestaEspaco(jogador->mesa->monstro4);
    TestaEspaco(jogador->mesa->monstro5);
    TestaEspaco(jogador->mesa->monstro6);
    TestaEspaco(jogador->mesa->monstro7);
    printf("Equips:\n");
    TestaEspaco(jogador->mesa->equip1);
    TestaEspaco(jogador->mesa->equip2);
    TestaEspaco(jogador->mesa->equip3);
    TestaEspaco(jogador->mesa->equip4);
    TestaEspaco(jogador->mesa->equip5);
    TestaEspaco(jogador->mesa->equip6);
    TestaEspaco(jogador->mesa->equip7);
    printf("Field: ");
    TestaEspaco(jogador->mesa->field);

    printf("\n------------------\n\n");
}

void RelatorioEstado(struct Player *jogador) {
    printf("Hand: %d\tDeck: %d\tGrave: %d\n",jogador->hand->quantidade,jogador->deck->quantidade,jogador->graveyard->quantidade);
    ImprimeMesa(jogador);
}

bool Turno(struct Card **buffer,struct Player *jogador,struct Player *adversario,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *lock,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *lv_prompt,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *coin_prompt,ALLEGRO_BITMAP *escolhe_tipo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_TIMER *timer,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int rolagem = 0;
    bool final = false;

    //ImprimeMesa(jogador);
    //RelatorioEstado(jogador);
    printf("\n\n\n--------- NOVO TURNO COMECOU -----------\n");
    //RelatorioEstado(adversario);

    EfeitoInicial(buffer,&final,&rolagem,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicio(buffer,&final,sbox,jogador,adversario,&rolagem,selecao,roll_bar,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);   //INICIA CONTADORES DE ALGUMAS CARTAS, BEM COMO RECUPERACAO DE HP DOS MONSTROS!
    LevelUp(buffer,&final,&rolagem,sbox,prompt,selecao,roll_bar,fundo_menu,fundo,fundo_carta,deck_meio,deck_cheio,pont,display,lv_prompt,font,font2,color,jogador,adversario,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);  //SERA NECESSARIO CORRIGIR TODAS AS FUNCOES!!!
    EfeitoMeio(buffer,&final,sbox,jogador,adversario,&rolagem,prompt,fundo_menu,selecao,roll_bar,fundo_carta,deck_meio,deck_cheio,pont,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    CharacterActions(buffer,&final,&rolagem,sbox,selecao,lock,roll_bar,prompt,jogador,adversario,fundo,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,display,font,font2,color,escolhe_tipo,timer,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    MonsterAttacks(-1,buffer,&final,sbox,jogador,adversario,display,&rolagem,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,coin_prompt,prompt,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    EfeitoFinal(-1,buffer,&final,&rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    //final de monster attacks deve atualizar mesa p/ checar se acabou o jogo.
    return(final);
}

void TestaPlayer(struct Player *jogador) {
    struct Deck *aux;
    struct char_action *aux2;

    printf("CHARACTER: %s\n",jogador->mesa->character->origem->nome);
    printf("DECK:\n");

    aux = jogador->deck->inicio;
    while(aux->prox != NULL) {
        printf("%s\n",aux->card->origem->nome);
        aux = aux->prox;
    }

    printf("HP: %d\n",*(jogador->HP));
    printf("%d\n---------------\n",jogador->level);

    aux2 = jogador->character_actions;
    while (aux2->prox != NULL) {
        printf("%s\n",aux2->acao);
        aux2 = aux2->prox;
    }
}

//VERIFICAR ESTA FUNCAO
struct CARD *CarregaCARD(bool dono,int nome_card,struct COLECAO *colecao) {
    struct CARD *card;

    card = (struct CARD *)calloc(1,sizeof(struct CARD));
    card->id_dono = dono;
    card->level_drop = 0;

    CarregaCard(nome_card,&(card->origem),colecao);

    card->var_equip = NULL;
    card->var_monster = NULL;

    card->cards_associados = (struct card_associado *)calloc(1,sizeof(struct card_associado));
    card->cards_associados->prox = NULL;
    card->qte_associado = 0;

    card->dot_list = (struct DotInstance *)malloc(sizeof(struct DotInstance));
    card->dot_list->prox = NULL;

    card->buff_list = (struct BuffInstance *)malloc(sizeof(struct BuffInstance));
    card->buff_list->prox = NULL;

    if(strcmp(card->origem->tipo,"Monster") == 0 || strcmp(card->origem->tipo,"Jr. Boss") == 0 || strcmp(card->origem->tipo,"Boss") == 0) {
        card->var_monster = (struct VariaveisMONSTER *)calloc(1,sizeof(struct VariaveisMONSTER));
        InicializaListaQteAtaques(card->var_monster);

        card->var_monster->dead_hand_cont = 2;

        if(strcmp(card->origem->tipo,"Monster") == 0) {
            printf("LOADED '%s'\n",card->origem->nome);

            card->attack = card->origem->monster->attack;
            card->MaxHP = card->origem->monster->MaxHP;
            card->HP = card->origem->monster->MaxHP;
        }
        else if(strcmp(card->origem->tipo,"Jr. Boss") == 0) {
            card->attack = card->origem->jrboss->attack;
            card->MaxHP = card->origem->jrboss->MaxHP;
            card->HP = card->origem->jrboss->MaxHP;
        }
        else {
            card->attack = card->origem->boss->attack;
            card->MaxHP = card->origem->boss->MaxHP;
            card->HP = card->origem->boss->MaxHP;
        }

        card->var_monster->bless_of_triforce_buff_cont = 0;
        card->var_monster->spike_bool = true;
        card->var_monster->giant_leever_bool = false;
        card->var_monster->biri_bool = false;
    }
    else if(strcmp(card->origem->tipo,"Equipment") == 0) card->var_equip = (struct VariaveisEQUIP *)calloc(1,sizeof(struct VariaveisEQUIP));
    else if(strcmp(card->origem->tipo,"Character") == 0) {
        card->HP = card->origem->character->MaxHP;
        card->MaxHP = card->origem->character->MaxHP;
    }
    //Definido como cada tipo de card possui uma estrutura propria.
    //Estruturas referentes ao BUFF para character sao inclusos em var. TACTICS.

    return(card);
}

void AtualizaCharacter(int id,struct PROFILE *prof) {
    struct ProfCard *aux;

    aux = prof->char_deck;
    while(aux->prox != NULL) {
        if(aux->card == id) {
            prof->main_character = aux->card;
            break;
        }

        aux = aux->prox;
    }
}

void CarregaCharacter(struct Player *player1,struct PROFILE *profile1,struct COLECAO *colecao) {
    player1->mesa->character = CarregaCARD(player1->id,profile1->main_character,colecao);
    player1->MaxHP = &(player1->mesa->character->MaxHP);
    player1->HP = &(player1->mesa->character->HP);

    player1->character_actions = (struct char_action *)malloc(sizeof(struct char_action));
    DefineCharAction(NULL,player1->character_actions,player1->mesa->character,player1->mesa->character->origem->character->inicio);
    DefineCharAction(NULL,player1->character_actions->prox,player1->mesa->character,player1->mesa->character->origem->character->inicio->prox);
    DefineCharAction(NULL,player1->character_actions->prox->prox,player1->mesa->character,player1->mesa->character->origem->character->inicio->prox->prox);
}

void LeString(char *str,FILE *arq) {
    fgets(str,100,arq);
    str[strlen(str) - 1] = 0;
}

void IniciaDados(FILE *arq,struct COLECAO *colecao,struct PROFILE *profile1,struct Player **jogador,bool st,bool toggle) {
    struct ProfCard *aux;
    struct Deck *card;
    struct Player *player1;
    struct char_action *aux2;
    int i,id;
    char *str = (char *)calloc(101,sizeof(char));

    player1 = (struct Player *)calloc(1,sizeof(struct Player));
    player1->id = toggle;
    player1->nome_prof = profile1->nome;
    player1->level_prof = profile1->level;
    player1->exp_prof = profile1->exp;

    player1->schedule = (struct InstanceSchedule *)malloc(sizeof(struct InstanceSchedule));
    player1->schedule->prox = NULL;

    player1->end_turn_tactics = (struct Deck *)malloc(sizeof(struct Deck));
    player1->end_turn_tactics->prox = NULL;

    player1->var_tactic = (struct VariaveisTACTIC *)malloc(sizeof(struct VariaveisTACTIC));
    player1->var_tactic->channeled_strike_cont = 0;
    player1->var_tactic->bless_of_triforce_cont = 0;
    player1->var_tactic->fairys_aid_cont = 0;
    player1->var_tactic->fairy_fountain_cont = 0;
    player1->var_tactic->horse_riding_turn_cont = 0;
    player1->var_tactic->giant_leever_call_bool = false;
    player1->var_tactic->biri_call_bool = false;
    player1->prevent_damage = 0;
    player1->prevent_any_damage = 0;
    player1->turn_away = 0;
    player1->bombchu_cont = 0;

    player1->mesa = (struct Mesa *)malloc(sizeof(struct Mesa));
    player1->mesa->equip1 = NULL;
    player1->mesa->equip2 = NULL;
    player1->mesa->equip3 = NULL;
    player1->mesa->equip4 = NULL;
    player1->mesa->equip5 = NULL;
    player1->mesa->equip6 = NULL;
    player1->mesa->equip7 = NULL;
    player1->mesa->monstro1 = NULL;
    player1->mesa->monstro2 = NULL;
    player1->mesa->monstro3 = NULL;
    player1->mesa->monstro4 = NULL;
    player1->mesa->monstro5 = NULL;
    player1->mesa->monstro6 = NULL;
    player1->mesa->monstro7 = NULL;
    player1->mesa->field = NULL;

    player1->graveyard = (struct Lista *)malloc(sizeof(struct Lista));
    player1->graveyard->inicio = (struct Deck *)malloc(sizeof(struct Deck));
    player1->graveyard->inicio->prox = NULL;
    player1->graveyard->quantidade = 0;

    player1->hand = (struct Lista *)malloc(sizeof(struct Lista));
    player1->hand->inicio = (struct Deck *)malloc(sizeof(struct Deck));
    player1->hand->inicio->prox = NULL;
    player1->hand->quantidade = 0;

    player1->deck = (struct Lista *)malloc(sizeof(struct Lista));
    player1->deck->inicio = (struct Deck *)malloc(sizeof(struct Deck));
    player1->deck->inicio->prox = NULL;
    aux = profile1->deck;
    card = player1->deck->inicio;   //inicia o deck do jogador.
    player1->deck->quantidade = 0;

    while(aux->prox != NULL) {
        card->card = CarregaCARD(player1->id,aux->card,colecao);
        card->prox = (struct Deck *)malloc(sizeof(struct Deck));
        card = card->prox;
        card->prox = NULL;

        aux = aux->prox;
        (player1->deck->quantidade)++;
    }
    EmbaralhaDeck(player1->deck->inicio,player1->deck->quantidade);

    player1->graveyard = (struct Lista *)malloc(sizeof(struct Lista));
    player1->graveyard->inicio = (struct Deck *)malloc(sizeof(struct Deck));
    player1->graveyard->inicio->prox = NULL;
    player1->graveyard->quantidade = 0;
    player1->level = 0;
    player1->hand = (struct Lista *)malloc(sizeof(struct Lista));
    player1->hand->quantidade = 0;
    player1->hand->inicio = (struct Deck *)malloc(sizeof(struct Deck));
    player1->hand->inicio->prox = NULL;

    player1->earth_ic = 0;
    player1->wind_ic  = 0;
    player1->fire_ic  = 0;
    player1->water_ic = 0;
    player1->dark_ic  = 0;
    player1->light_ic = 0;

    player1->global_silence = false;

    //-------- Finaliza inicializacao dos dados -------------
    if(arq != NULL) {
        printf("\n\n");
        LeString(str,arq); //Card character, no caso substitui o main_char atual pelo character descrito.
        id = ConverteNomeParaId(str,colecao);
        AtualizaCharacter(id,profile1);
        CarregaCharacter(player1,profile1,colecao);
        printf("1 ");

        LeString(str,arq);
        player1->mesa->character->HP = atoi(str);

        LeString(str,arq);
        player1->mesa->character->MaxHP = atoi(str);

        printf("2 ");
        fgets(str,100,arq); //Pula o identificador: HAND, a partir do proximo comeca a busca.
        LeString(str,arq);
        while(strcmp(str,"GRAVEYARD") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            ColocaNovoCardNoDeck(&(player1->hand),card);

            LeString(str,arq);
        }
        printf("3 ");

        LeString(str,arq);
        while(strcmp(str,"LVL_CARDS") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            ColocaNovoCardNoDeck(&(player1->graveyard),card);

            LeString(str,arq);
        }
        printf("4 ");

        LeString(str,arq);
        aux2 = player1->character_actions->prox->prox;

        while(strcmp(str,"EQUIPS") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                DefineCharAction(aux2,aux2->prox,card->card,card->card->origem->lv_acao);
                player1->level += 10;

                if(!strcmp(card->card->origem->elemento,"Earth")) (player1->earth_ic)++;
                else if(!strcmp(card->card->origem->elemento,"Wind")) (player1->wind_ic)++;
                else if(!strcmp(card->card->origem->elemento,"Fire")) (player1->fire_ic)++;
                else if(!strcmp(card->card->origem->elemento,"Water")) (player1->water_ic)++;
                else if(!strcmp(card->card->origem->elemento,"Dark")) (player1->dark_ic)++;
                else (player1->light_ic)++;

                aux2 = aux2->prox;
                free(card);
            }

            LeString(str,arq);
        }

        printf("5 ");

        LeString(str,arq);
        if(strcmp(str,"MONSTERS") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->equip1 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        if(strcmp(str,"MONSTERS") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->equip2 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        if(strcmp(str,"MONSTERS") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->equip3 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        if(strcmp(str,"MONSTERS") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->equip4 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        if(strcmp(str,"MONSTERS") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->equip5 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        if(strcmp(str,"MONSTERS") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,(&player1->deck));
            if(card != NULL) {
                player1->mesa->equip6 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        if(strcmp(str,"MONSTERS") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->equip7 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        printf("6 ");

        LeString(str,arq);
        if(strcmp(str,"FIELD") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->monstro1 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        if(strcmp(str,"FIELD") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->monstro2 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        if(strcmp(str,"FIELD") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->monstro3 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        if(strcmp(str,"FIELD") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->monstro4 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        if(strcmp(str,"FIELD") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->monstro5 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        if(strcmp(str,"FIELD") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->monstro6 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        if(strcmp(str,"FIELD") != 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->monstro7 = card->card;
                free(card);
            }

            LeString(str,arq);
        }

        printf("7 ");

        LeString(str,arq);
        if(strcmp(str,"CHARACTER") != 0 && strlen(str) > 0) {
            id = ConverteNomeParaId(str,colecao);
            card = RetiraCardPorNome(id,&(player1->deck));
            if(card != NULL) {
                player1->mesa->field = card->card;
                free(card);
            }

            LeString(str,arq);
        }
        printf("OK!\n");
    }

    else {
        CarregaCharacter(player1,profile1,colecao);

        i = 5;
        while(i > 0) {
            DrawCard_inicial(player1);
            i--;
        }
        if(st == toggle) DrawCard_inicial(player1);
    }

    free(str);
    *jogador = player1;
}

void LiberaDados(struct Player *jogador) {
    int i = 0;
    struct Deck *aux,*aux2;
    struct char_action *aux3,*aux4;

    if(jogador->mesa->equip1 != NULL) LiberaCARD(jogador->mesa->equip1);
    if(jogador->mesa->equip2 != NULL) LiberaCARD(jogador->mesa->equip2);
    if(jogador->mesa->equip3 != NULL) LiberaCARD(jogador->mesa->equip3);
    if(jogador->mesa->equip4 != NULL) LiberaCARD(jogador->mesa->equip4);
    if(jogador->mesa->equip5 != NULL) LiberaCARD(jogador->mesa->equip5);
    if(jogador->mesa->equip6 != NULL) LiberaCARD(jogador->mesa->equip6);
    if(jogador->mesa->equip7 != NULL) LiberaCARD(jogador->mesa->equip7);
    if(jogador->mesa->monstro1 != NULL) LiberaCARD(jogador->mesa->monstro1);
    if(jogador->mesa->monstro2 != NULL) LiberaCARD(jogador->mesa->monstro2);
    if(jogador->mesa->monstro3 != NULL) LiberaCARD(jogador->mesa->monstro3);
    if(jogador->mesa->monstro4 != NULL) LiberaCARD(jogador->mesa->monstro4);
    if(jogador->mesa->monstro5 != NULL) LiberaCARD(jogador->mesa->monstro5);
    if(jogador->mesa->monstro6 != NULL) LiberaCARD(jogador->mesa->monstro6);
    if(jogador->mesa->monstro7 != NULL) LiberaCARD(jogador->mesa->monstro7);
    if(jogador->mesa->field != NULL) LiberaCARD(jogador->mesa->field);

    LiberaCARD(jogador->mesa->character);
    free(jogador->mesa);

    //char_actions
    i = 0;
    aux3 = jogador->character_actions;
    while(i < 3) {
        aux4 = aux3;
        aux3 = aux3->prox;
        free(aux4);
        i++;
    }

    while(aux3->prox != NULL) {
        aux4 = aux3;
        aux3 = aux3->prox;

        LiberaCARD(aux4->card);
        free(aux4);
    }
    free(aux3);

    aux = jogador->hand->inicio;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;

        LiberaCARD(aux2->card);
        free(aux2);
    }
    free(aux);
    free(jogador->hand);

    aux = jogador->deck->inicio;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;

        LiberaCARD(aux2->card);
        free(aux2);
    }
    free(aux);
    free(jogador->deck);

    aux = jogador->graveyard->inicio;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;

        LiberaCARD(aux2->card);
        free(aux2);
    }
    free(aux);
    free(jogador->graveyard);

    free(jogador->var_tactic);
    LiberaInstancias(jogador);
    LiberaEOTTactics(jogador->end_turn_tactics);

    free(jogador);
}
//OBS.: chamando esta funcao ira requerer os profiles ja carregados.

void Jogo(struct COLECAO *colecao,struct PROFILE *profile1,struct PROFILE *profile2,ALLEGRO_DISPLAY *display,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *pont,ALLEGRO_BITMAP *lv_prompt,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *coin_prompt,ALLEGRO_BITMAP *escolhe_tipo,ALLEGRO_BITMAP *lock,ALLEGRO_FONT *font,ALLEGRO_FONT *ssize,ALLEGRO_FONT *gsize,ALLEGRO_COLOR color,bool save_state,ALLEGRO_TIMER *timer,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool st,fim_jogo = false;
    int turno = 0, i, rolagem = 0,dist_player1,dist_player2;
    struct Player *player1,*player2;
    struct Card *buffer = NULL;
    char nome_arq[101], str[101];
    const char *nome = "savestate",*final_frase = "Player  WINS!",*comeca_frase = "'s TURN!";
    FILE *arq = NULL;

    al_set_target_backbuffer(display);
    srand(time(NULL));

    st = rand() % 2;    //comeco de jogo: 0 -> Player2  /   1 -> Player1
    printf("Inicia Dados... ");

    if(save_state == true) {
        nome_arq[0] = 0;
        strcat(nome_arq,"save_states/");
        strcat(nome_arq,nome);
        strcat(nome_arq,".sav");

        arq = fopen(nome_arq,"r+t");
    }
    fgets(str,100,arq);

    dist_player1 = (al_get_text_width(gsize,profile1->nome) + al_get_text_width(gsize,comeca_frase)) / 2;
    dist_player2 = (al_get_text_width(gsize,profile2->nome) + al_get_text_width(gsize,comeca_frase)) / 2;

    IniciaDados(arq,colecao,profile1,&player1,st,true);
    IniciaDados(arq,colecao,profile2,&player2,st,false);
    if(arq != NULL) fclose(arq);

    TestaPlayer(player1);
    TestaPlayer(player2);
    printf("OK!\n");

    al_draw_bitmap(fundo,0,0,0);
    EfeitoInicial(&buffer,&fim_jogo,&i,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,player1,player2,display,fundo,font,ssize,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicial(&buffer,&fim_jogo,&i,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,prompt,sbox,player2,player1,display,fundo,font,ssize,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicio(&buffer,&fim_jogo,sbox,player1,player2,&i,selecao,roll_bar,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,display,fundo,font,ssize,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    EfeitoInicio(&buffer,&fim_jogo,sbox,player2,player1,&i,selecao,roll_bar,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,display,fundo,font,ssize,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    while(fim_jogo != true) {
        turno++;

        al_set_timer_count(timer, 0);
        al_start_timer(timer);
        while(al_get_timer_count(timer) < 2000) {
            if(turno % 2 == st) {
                AtualizaMesa(false,NULL,-1,-1,0,&buffer,&fim_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,player2,player1,display,font,ssize,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,&rolagem,NULL,-1,-1,0,-1,NULL,NULL);
                al_draw_scaled_bitmap(selecao,0,0,240,360,240,275,400,50,0);
                al_draw_textf(gsize,color,440 - dist_player2,285,0,"%s's TURN!",profile2->nome);
            }
            else {
                AtualizaMesa(false,NULL,-1,-1,0,&buffer,&fim_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,player1,player2,display,font,ssize,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,&rolagem,NULL,-1,-1,0,-1,NULL,NULL);
                al_draw_scaled_bitmap(selecao,0,0,240,360,240,275,400,50,0);
                al_draw_textf(gsize,color,440 - dist_player1,285,0,"%s's TURN!",profile1->nome);
            }

            al_flip_display();
        }
        al_stop_timer(timer);

        if(turno % 2 == st) {
            //ImprimeMao(player2);
            fim_jogo = Turno(&buffer,player2,player1,sbox,selecao,lock,roll_bar,fundo,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,display,lv_prompt,prompt,coin_prompt,escolhe_tipo,font,ssize,color,timer,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            //ImprimeMao(player2);
        }
        else {
            //ImprimeMao(player1);
            fim_jogo = Turno(&buffer,player1,player2,sbox,selecao,lock,roll_bar,fundo,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,display,lv_prompt,prompt,coin_prompt,escolhe_tipo,font,ssize,color,timer,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            //ImprimeMao(player1);
        }
    }
    if(*(player1->HP) == 0) {
        dist_player2 = (al_get_text_width(gsize,profile2->nome) + al_get_text_width(gsize,final_frase)) / 2;

        al_draw_scaled_bitmap(selecao,0,0,240,360,240,275,400,50,0);
        al_draw_textf(gsize,color,440 - dist_player2,280,0,"Player %s WINS!",profile2->nome);
        al_flip_display();
        al_rest(3.0);
    }
    else {
        dist_player1 = (al_get_text_width(gsize,profile1->nome) + al_get_text_width(gsize,final_frase)) / 2;

        al_draw_scaled_bitmap(selecao,0,0,240,360,240,275,400,50,0);
        al_draw_textf(gsize,color,440 - dist_player1,280,0,"Player %s WINS!",profile1->nome);
        al_flip_display();
        al_rest(3.0);
    }
    //falta contabilizar dados dos profiles...

    printf("Libera Dados... ");
    LiberaDados(player1);
    LiberaDados(player2);
    printf("OK!\n");
}

#endif // ESTRUTURA_JOGO_C_INCLUDED
