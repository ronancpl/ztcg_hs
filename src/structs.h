#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

struct QteAtaques {
    struct CARD *origem;    //pode ser NULO, somente se for TURNO dando o efeito!
    short int quantidade;

    struct QteAtaques *prox;
};

struct VariaveisMONSTER {
    struct QteAtaques *lista_qte_ataques;
    short int qte_ataques;
    short int damage_multiplier;
    bool spawn_bool;

    short int twinrova_cont;
    short int lizalfos_cont;
    short int dead_hand_cont;
    short int pierre_cont;
    short int bomb_bag_bonus_dmg_cont;
    short int white_wolfos_dmg_cont;
    //bool twinrova_bool;
    bool spike_bool;
    bool baby_dodongo_bool;
    bool giant_leever_bool;

    bool big_poe_bool;
    bool dead_hand_bool;
    bool milk_bottle_bool;
    bool skull_kid_bool;
    bool bazaar_seller_bool;

    bool rage_buff_bool;
    short int bless_of_triforce_buff_cont;  //no inicio do turno, o contador eh decrementado de acordo com a qte de instancias de BOTriforce usado pelo jogador.
};

struct VariaveisTACTIC {
    short int turn_next_attack_bonus;   //zerado a cada inicio de turno, permite BONUS NO PROXIMO ATAQUE do character.

    short int dark_pathway_cont;    //passes
    short int gerudos_membership_card_cont;

    short int char_withdrawal_cont;
    short int iron_boots_cont;

    short int channeled_strike_cont;
    short int channeled_strike_charged_cont;

    short int great_dekus_bless_cont;
    short int great_fairys_bless_cont;
    short int spirit_medallion_cont;
    short int light_medallion_cont;
    short int bless_of_triforce_cont;
    short int fairys_aid_cont;
    short int fairy_fountain_cont;
    int horse_riding_cont;
    short int horse_riding_turn_cont;
    int _1trl_no_gauntlet_cont;
    int _1trl_gauntlet_cont;
    short int shadow_merge_spawn_cont;
    short int underground_shelter_cont;

    short int buff_cont;
    short int rauru_cont;
    short int blue_potion_cont;
    short int assistance_cont;
    short int skullwalltula_cont;

    bool flood_buff_bool;
    bool tidal_strike_bool;
    bool gerudo_guard_bool;
    bool mido_bool;
    bool ganondorf_bool;
    bool princess_ruto_bool;
    bool giant_leever_call_bool;
};

struct VariaveisEQUIP {
    int mirror_shield_dmg;
    int mirror_shield_cont;
    int bomb_dmg;

    int master_sword_cont;
    int fairy_slingshot_cont;
    int skull_mask_cont;
    int boomerang_cont;
    int silver_gauntlets_cont;
    int golden_gauntlets_cont;
    int bomb_cont;
    bool magic_beans_bool;
    bool compass_bool;
    bool ocarina_of_time_bool;
    bool mask_of_truth_bool;
    bool claim_check_bool;
    bool bigger_bomb_bag_bool;
    bool bigger_bomb_bag_overriding_bool;

    int stocked_status;
};

struct Coordenadas {
    int x;
    int y;

    struct Coordenadas *prox;
};

struct ProfCard {   //int pois carregar tods as cartas demanda muita memoria! Logo o melhor eh carregar os cards na execucao...
    int card;
    struct ProfCard *prox;
};

struct ProfShopCard {
    int card;
    int preco;
    int quantidade;

    struct ProfShopCard *prox;
};

struct PROFILE {
    char *nome;

    int main_character;
    char *nome_main_char;

    int level;
    int exp;
    long int moeda;
    int qte_deck;
    int MAX_deck;   //max de cards que o deck suporta no momento...
    struct ProfCard *char_deck;
    struct ProfCard *deck;
    struct ProfCard *side_deck;    //Os cards existentes de um profile estarao definidos em uma lista encadeada!
    struct ProfShopCard *trade_deck;

    struct PROFILE *prox;
};

/* card types */

typedef struct char_action* Acao;
struct char_action {
    struct CARD *card;  //representa o card adicionado ao levelup do character!
    char *acao;
    int atrib;
    int nivel;
    Acao ant;
    Acao prox;

    bool goron_bracelet_bool;
};

typedef struct card_associado* CardAssociado;
struct card_associado {
    struct Deck *deck;  //representa o card adicionado ao levelup do character!
    CardAssociado prox;
};

struct character {
	int MaxHP;
    Acao inicio;
};

struct monster {
    int level;
	int attack;
    int MaxHP;
	char *acao;
};

struct equipment {
    int level;
    char *acao;
};

struct tactic {
    int level;
    char *acao;
};

struct field {
    char *acao;
};

struct jrboss {
    int level;
    int attack;
    int MaxHP;
    struct char_action *acao;
};

struct boss {
    int level;
    int attack;
    int MaxHP;
    Acao acao;
};

/* Estruturas básicas */

struct DotInstance {
    int dot;
    short turns_left;
    struct CARD *source;

    struct DotInstance *prox;
};

struct BuffInstance {
    int atk;
    int def;
    int hp;

    short turns_left;
    struct CARD *source;

    struct BuffInstance *prox;
};

struct Card {     //todas as estruturas abaixo representam cards do jogo...
    struct character *character;
    struct monster *monster;
    struct equipment *equip;
    struct tactic *tactic;
    struct field *field;
    struct jrboss *jrboss;
    struct boss *boss;

    Acao lv_acao;

    ALLEGRO_BITMAP *bmp;
    char **lista_texto; //MAX 50 linhas.
    char *nome;
    char *elemento;
    char *tipo;         //se eh monstro, equip, tactic...
    char *str_concat;   //"elemento / tipo / subtipo / localizacao".
    int RARIDADE;
    int colecao;        //id do card
    int indice_texto;
    int preco;          //Valor-base do card.
};

struct CARD {
    bool id_dono;
    struct Card *origem;
    int PosicaoX;       //posicao da carta no display do jogo.
    int PosicaoY;

    int attack;
    int HP;
    int MaxHP;
    int level_drop;

    int turn_cooldown;  //qte de turnos que o monstro deixa de atacar.
    int turn_silenced;  //qte de turnos que o monstro deixa de usar habilidades.

    CardAssociado cards_associados;    //linkar um conjunto de cards a este card (ex.: Deku Seeds Bag)
    int qte_associado;

    struct VariaveisMONSTER *var_monster;   //cada carta possui suas proprias variaveis.
    struct VariaveisEQUIP *var_equip;

    struct DotInstance *dot_list;
    struct BuffInstance *buff_list;
};

typedef struct Deck* ProxCard;

struct Deck {
    struct CARD *card;
    ProxCard prox;
};

struct ListaCards {
    struct Card *card;
    unsigned int contador;

    struct ListaCards *prox;
};

struct Lista {
    int quantidade;
    struct Deck* inicio;
};

struct Mesa {   //se trata das copias das cartas, nao as originais...
    struct CARD *monstro1;
    struct CARD *monstro2;
    struct CARD *monstro3;
    struct CARD *monstro4;
    struct CARD *monstro5;
    struct CARD *monstro6;
    struct CARD *monstro7;
    struct CARD *equip1;
    struct CARD *equip2;
    struct CARD *equip3;
    struct CARD *equip4;
    struct CARD *equip5;
    struct CARD *equip6;
    struct CARD *equip7;
    struct CARD *field;
    struct CARD *character;

};

struct InstanceSchedule {
    int turns_left;
    char *instance_id;

    struct InstanceSchedule *prox;
};

struct Player {
    bool id;
    char *nome_prof;
    int level_prof;
    int exp_prof;

    struct Lista *hand;
    struct Lista *deck;
    struct Lista *graveyard;
    struct Mesa *mesa;
    struct char_action *character_actions;
    int *HP;
    int *MaxHP;
    int level;
    int field_cont;
    short int earth_ic;
    short int wind_ic;
    short int light_ic;
    short int dark_ic;
    short int fire_ic;
    short int water_ic;

    int prevent_damage; //a capacidade que o char tem de prevenir danos.
    int prevent_any_damage; //a capacidade que char & mobs tem de prevenir danos.

    bool global_silence;    //usado pelo c. villager
    short int mobs_played;
    short int equips_played;

    short int turn_away;

    struct InstanceSchedule *schedule;
    struct Deck *end_turn_tactics;
    struct VariaveisTACTIC *var_tactic;
    int bombchu_cont;
};

struct Rupee_bitmaps {
    ALLEGRO_BITMAP *rupee1;
    ALLEGRO_BITMAP *rupee2;
    ALLEGRO_BITMAP *rupee3;
    ALLEGRO_BITMAP *rupee4;
    ALLEGRO_BITMAP *rupee5;
};

struct StatusBox_bitmaps {
    ALLEGRO_BITMAP *container_bg;

    ALLEGRO_BITMAP *HPpool_icon;
    ALLEGRO_BITMAP *offense_icon;
    ALLEGRO_BITMAP *defense_icon;
    ALLEGRO_BITMAP *map_icon;
    ALLEGRO_BITMAP *stun_icon;
    ALLEGRO_BITMAP *prevent_icon;
    ALLEGRO_BITMAP *dot_icon;
    ALLEGRO_BITMAP *silence_icon;
    ALLEGRO_BITMAP *warp_icon;

    ALLEGRO_BITMAP *earth_icon;
    ALLEGRO_BITMAP *wind_icon;
    ALLEGRO_BITMAP *light_icon;
    ALLEGRO_BITMAP *dark_icon;
    ALLEGRO_BITMAP *fire_icon;
    ALLEGRO_BITMAP *water_icon;

    ALLEGRO_BITMAP *hp0;
    ALLEGRO_BITMAP *hp1;
    ALLEGRO_BITMAP *hp2;
    ALLEGRO_BITMAP *hp3;
    ALLEGRO_BITMAP *hp4;

    ALLEGRO_BITMAP *dmg1;
    ALLEGRO_BITMAP *dmg2;
    ALLEGRO_BITMAP *dmg3;
    ALLEGRO_BITMAP *dmg4;
};

#endif // STRUCTS_H_INCLUDED
