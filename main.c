#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>   //so esta sendo usado para a FUNCAO POTENCIA! Se nao houver outras utilizacoes da biblioteca, SUBSTITUI POR FUNCAO UNICA!!!
#include <time.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#define MOUSE_AUTOREP_SEG 0.5
#define KEYB_AUTOREP_SEG 0.5

#include "src/card.c"

/*
    FUNCAO -> ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_COLOR color

    OBS.: NO FINAL DA IMPLEMENTACAO DO JOGO, PROCURAR POR POSSIVEIS LOCAIS ONDE FUNCOES FALTAM PARAMETROS!!!
    COMEMORACAO DE FIM DE JOGO PRECISA SER MELHORADA!
 */
void Teste(struct PROFILE *prof) {
    struct PROFILE *aux;
    struct ProfCard *aux2;

    aux = prof;
    while(aux->prox != NULL) {
        printf("\n---------------------\n%s\n",aux->nome);
        printf("%d %d %ld %d %d\n",aux->level,aux->exp,aux->moeda,aux->qte_deck,aux->MAX_deck);

        printf("CHAR_DECK----------\n");
        aux2 = aux->char_deck;
        while(aux2->prox != NULL) {
            printf("%d\n",aux2->card);
            aux2 = aux2->prox;
        }
        printf("MAIN_DECK----------\n");

        aux2 = aux->deck;
        while(aux2->prox != NULL) {
            printf("%d\n",aux2->card);
            aux2 = aux2->prox;
        }
        printf("SIDE_DECK----------\n");

        aux2 = aux->side_deck;
        while(aux2->prox != NULL) {
            printf("%d\n",aux2->card);
            aux2 = aux2->prox;
        }

        aux = aux->prox;
    }
    printf("\n");
}

struct Rupee_bitmaps* CarregaRupeeBitmap() {
    struct Rupee_bitmaps *rbmap;

    rbmap = (struct Rupee_bitmaps *)malloc(sizeof(struct Rupee_bitmaps));

    rbmap->rupee1 = al_load_bitmap("data/rupee1.png");
    rbmap->rupee2 = al_load_bitmap("data/rupee2.png");
    rbmap->rupee3 = al_load_bitmap("data/rupee3.png");
    rbmap->rupee4 = al_load_bitmap("data/rupee4.png");
    rbmap->rupee5 = al_load_bitmap("data/rupee5.png");

    return(rbmap);
}

struct StatusBox_bitmaps* CarregaStatusBox() {
    struct StatusBox_bitmaps *box;

    box = (struct StatusBox_bitmaps *)malloc(sizeof(struct StatusBox_bitmaps));

    box->container_bg = al_load_bitmap("interface/statusbox/background.png");
    box->defense_icon = al_load_bitmap("interface/statusbox/defense.png");
    box->offense_icon = al_load_bitmap("interface/statusbox/offense.png");

    box->dmg1 = al_load_bitmap("interface/statusbox/dmg1.png");
    box->dmg2 = al_load_bitmap("interface/statusbox/dmg2.png");
    box->dmg3 = al_load_bitmap("interface/statusbox/dmg3.png");
    box->dmg4 = al_load_bitmap("interface/statusbox/dmg4.png");

    box->hp0 = al_load_bitmap("interface/statusbox/hp0.png");
    box->hp1 = al_load_bitmap("interface/statusbox/hp1.png");
    box->hp2 = al_load_bitmap("interface/statusbox/hp2.png");
    box->hp3 = al_load_bitmap("interface/statusbox/hp3.png");
    box->hp4 = al_load_bitmap("interface/statusbox/hp4.png");

    box->HPpool_icon = al_load_bitmap("interface/statusbox/health.png");
    box->map_icon = al_load_bitmap("interface/statusbox/map.png");
    box->dot_icon = al_load_bitmap("interface/statusbox/dot.png");
    box->prevent_icon = al_load_bitmap("interface/statusbox/dodge.png");
    box->stun_icon = al_load_bitmap("interface/statusbox/stun.png");
    box->silence_icon = al_load_bitmap("interface/statusbox/silence.png");
    box->warp_icon = al_load_bitmap("interface/statusbox/warp.png");

    box->earth_icon = al_load_bitmap("interface/statusbox/earth.png");
    box->wind_icon = al_load_bitmap("interface/statusbox/wind.png");
    box->light_icon = al_load_bitmap("interface/statusbox/light.png");
    box->dark_icon = al_load_bitmap("interface/statusbox/dark.png");
    box->fire_icon = al_load_bitmap("interface/statusbox/fire.png");
    box->water_icon = al_load_bitmap("interface/statusbox/water.png");

    return(box);
}

void DescarregaRupeeBitmap(struct Rupee_bitmaps *rbmap) {
    al_destroy_bitmap(rbmap->rupee1);
    al_destroy_bitmap(rbmap->rupee2);
    al_destroy_bitmap(rbmap->rupee3);
    al_destroy_bitmap(rbmap->rupee4);
    al_destroy_bitmap(rbmap->rupee5);

    free(rbmap);
}

void DescarregaStatusBox(struct StatusBox_bitmaps *box) {
    al_destroy_bitmap(box->container_bg);
    al_destroy_bitmap(box->defense_icon);
    al_destroy_bitmap(box->offense_icon);

    al_destroy_bitmap(box->dmg1);
    al_destroy_bitmap(box->dmg2);
    al_destroy_bitmap(box->dmg3);
    al_destroy_bitmap(box->dmg4);

    al_destroy_bitmap(box->hp0);
    al_destroy_bitmap(box->hp1);
    al_destroy_bitmap(box->hp2);
    al_destroy_bitmap(box->hp3);
    al_destroy_bitmap(box->hp4);

    al_destroy_bitmap(box->HPpool_icon);
    al_destroy_bitmap(box->map_icon);
    al_destroy_bitmap(box->dot_icon);
    al_destroy_bitmap(box->prevent_icon);
    al_destroy_bitmap(box->stun_icon);
    al_destroy_bitmap(box->silence_icon);
    al_destroy_bitmap(box->warp_icon);

    al_destroy_bitmap(box->earth_icon);
    al_destroy_bitmap(box->wind_icon);
    al_destroy_bitmap(box->light_icon);
    al_destroy_bitmap(box->dark_icon);
    al_destroy_bitmap(box->fire_icon);
    al_destroy_bitmap(box->water_icon);

    free(box);
}

int MenuInicial() {
    bool sair = false,mouse,mouse2,mouse_lado,keyb,allegro,img_addon,txt,save_state = true,repete_keychar = false;
    int mouseX=0,mouseY=0,deltaZ=0,*total_cards,keychar=0;

    struct ListaCards **lista;
    struct COLECAO *colecao;
    struct PROFILE *profiles,*profile1,*profile2;
    struct StatusBox_bitmaps *statusBox;
    struct Rupee_bitmaps *rbmap;

    ALLEGRO_TIMER *timer,*mouse_press_timer,*keyb_press_timer;
    ALLEGRO_DISPLAY *janela;
    ALLEGRO_BITMAP **estilo_deck,**cor_retangulo,*fundo_jogo,*menu_cards,*prompt,*level_prompt,*deck_meio,*deck_cheio,*botao,*fundo_card,*icon,*menu,*pont,*cursor,*iniciar_jogo,*player1,*player2,*dados,*lista_cards,*roll_bar,*select_card,*criar_prof,*administrar_prof,*deletar_prof,*selecionar_prof,*escolher_tipo,*lock;
    ALLEGRO_FONT *texto,*texto2,*texto3,*texto4,*texto5;
    ALLEGRO_COLOR cor_texto;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_MOUSE_CURSOR *seta;

    printf("Iniciando Allegro ");
    allegro = al_init();
    if(allegro == true) {
        img_addon = al_init_image_addon();
        al_init_font_addon();
        txt = al_init_ttf_addon();

        if(img_addon == true && txt == true) {
            //al_set_new_display_flags(ALLEGRO_FULLSCREEN);
            janela = al_create_display(800,600);
            printf("OK!\n");
            printf("Carregando bitmaps ");
            cor_retangulo = (ALLEGRO_BITMAP **)malloc(3*sizeof(ALLEGRO_BITMAP *));
            estilo_deck = (ALLEGRO_BITMAP **)malloc(9*sizeof(ALLEGRO_BITMAP *));

            icon = al_load_bitmap("data/icon.jpg");
            pont = al_load_bitmap("data/ponteiro.png");
            cursor = al_load_bitmap("data/cursor.png");
            botao = al_load_bitmap("data/botao_azul.jpg");
            roll_bar = al_load_bitmap("data/barra_rolagem.jpg");
            cor_retangulo[0] = al_load_bitmap("data/ret_vermelho.jpg");
            cor_retangulo[1] = al_load_bitmap("data/ret_verde.jpg");
            cor_retangulo[2] = al_load_bitmap("data/ret_azul.jpg");
            lock = al_load_bitmap("data/lock.png");
            deck_meio = al_load_bitmap("data/deck_meio.png");
            deck_cheio = al_load_bitmap("data/deck_cheio.png");

            escolher_tipo = al_load_bitmap("interface/prompt/escolher_tipo.jpg");
            prompt = al_load_bitmap("interface/prompt/prompt.png");
            level_prompt = al_load_bitmap("interface/prompt/level_prompt.png");
            menu_cards = al_load_bitmap("interface/prompt/menucards.jpg");

            menu = al_load_bitmap("interface/background/menu.jpg");
            iniciar_jogo = al_load_bitmap("interface/background/iniciarjogo.jpg");
            player1 = al_load_bitmap("interface/background/player1.jpg");
            player2 = al_load_bitmap("interface/background/player2.jpg");
            selecionar_prof = al_load_bitmap("interface/background/selecionar_profile.jpg");
            dados = al_load_bitmap("interface/background/dados.jpg");
            fundo_jogo = al_load_bitmap("interface/background/fundo_jogo.jpg");
            lista_cards = al_load_bitmap("interface/background/listacards.jpg");
            criar_prof = al_load_bitmap("interface/background/criar_profile.jpg");
            administrar_prof = al_load_bitmap("interface/background/administrar_profile.jpg");
            deletar_prof = al_load_bitmap("interface/background/deletar_profile.jpg");

            estilo_deck[0] = al_load_bitmap("interface/deck_opt/opcao_ewi.jpg");
            estilo_deck[1] = al_load_bitmap("interface/deck_opt/opcao_fwa.jpg");
            estilo_deck[2] = al_load_bitmap("interface/deck_opt/opcao_ld.jpg");
            estilo_deck[3] = al_load_bitmap("interface/deck_opt/opcao_el.jpg");
            estilo_deck[4] = al_load_bitmap("interface/deck_opt/opcao_wif.jpg");
            estilo_deck[5] = al_load_bitmap("interface/deck_opt/opcao_wad.jpg");
            estilo_deck[6] = al_load_bitmap("interface/deck_opt/opcao_ewa.jpg");
            estilo_deck[7] = al_load_bitmap("interface/deck_opt/opcao_fd.jpg");
            estilo_deck[8] = al_load_bitmap("interface/deck_opt/opcao_wil.jpg");

            rbmap = CarregaRupeeBitmap();
            statusBox = CarregaStatusBox();

            fundo_card = al_load_bitmap("cards/0_base_card.png");
            select_card = al_load_bitmap("cards/1_select.png");
            printf("OK!\n");

            printf("Carregando UI ");
            texto = al_load_ttf_font("data/triforce.ttf", 10, 0);
            texto2 = al_load_ttf_font("data/triforce.ttf", 12, 0);
            texto3 = al_load_ttf_font("data/triforce.ttf", 16, 0);
            texto4 = al_load_ttf_font("data/triforce.ttf", 42, 0);
            texto5 = al_load_ttf_font("data/triforce.ttf", 32, 0);
            cor_texto = al_map_rgb(0,0,0);       //DEFINE A COR DO TEXTO

            al_set_display_icon(janela,icon);
            al_set_window_title(janela,"The Legend of Zelda TCG");
            al_set_target_backbuffer(janela);
            al_draw_bitmap(menu,0,0,0);
            printf("OK!\n");

            //aqui carrega todas os cards, bem como profiles, etc.
            CarregaCartas(&colecao,texto3);
            CarregaProfile(&profiles,colecao);
            //Teste(profiles);

            printf("Carregando hardware drivers ");

            mouse = al_install_mouse();
            keyb = al_install_keyboard();
            if(mouse == true && keyb == true) {
                mouse = al_set_mouse_xy(janela,400,300);
                seta = al_create_mouse_cursor(cursor,0,0);
                if(mouse == true && seta != NULL) mouse = al_set_mouse_cursor(janela,seta);

                if(mouse == true) {
                    printf("OK!\n");
                    printf("Carregando timers ");
                    timer = al_create_timer(0.001);
                    mouse_press_timer = al_create_timer(0.001);
                    keyb_press_timer = al_create_timer(0.001);
                    printf("OK!\n");

                    printf("Carregando event queue ");
                    event_queue = al_create_event_queue();
                    if(!event_queue) {
                        printf("FALHOU!\n");
                        return(10);
                    }
                    al_register_event_source(event_queue, al_get_display_event_source(janela));
                    al_register_event_source(event_queue,al_get_keyboard_event_source());
                    al_register_event_source(event_queue,al_get_mouse_event_source());
                    printf("OK!\n");

                    //como detectar as cartas ja liberadas? sugere-se NUM ARQUIVO.
                    printf("Carregando listas de cards ");
                    ListaColecao(&lista,colecao,&total_cards);
                    printf("OK!\n");

                    printf("\nAllegro OK!\n");
                    while(!sair) {
                        al_draw_bitmap(menu,0,0,0);
                        al_draw_textf(texto2,cor_texto,500,10,0,"Projetado por RONAN C. P. LANA");

                        VerificaEventos(&sair,&mouseX,&mouseY,&deltaZ,&mouse,&mouse2,&mouse_lado,&keychar,&repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

                        //entra as opcoes do MENU INICIAL

                        if(mouseX >= 190 && mouseX < 190 + 420 && mouseY >= 205 && mouseY < 205 + 90) { //iniciar jogo
                            if(mouse == true) {
                                profile1 = NULL;
                                profile2 = NULL;
                                printf("--> INICIAR JOGO\n");
                                //al_rest(0.2);
                                while(!sair) {
                                    al_draw_bitmap(iniciar_jogo,0,0,0);
                                    if(save_state == true) {
                                        al_draw_bitmap(cor_retangulo[1],730,435,0);
                                        al_draw_text(texto2,cor_texto,635,445,0,"Debug mode ON");
                                    }
                                    else {
                                        al_draw_bitmap(cor_retangulo[0],730,435,0);
                                        al_draw_text(texto2,cor_texto,635,445,0,"Debug mode OFF");
                                    }

                                    VerificaEventos(&sair,&mouseX,&mouseY,&deltaZ,&mouse,&mouse2,&mouse_lado,&keychar,&repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

                                    if(mouseX >= 190 && mouseX < 190 + 420 && mouseY >= 205 && mouseY < 205 + 90) {
                                        if(mouse == true) {
                                            //al_rest(0.2);

                                            profile1 = EscolheProfile(profiles,janela,texto4,texto5,cor_texto,pont,player1,select_card,&sair,&mouseX,&mouseY,&deltaZ,&mouse,&mouse2,&mouse_lado,&keychar,&repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                                            if(profile1 != NULL && (profile2 == NULL || profile1 != profile2)) EscolheCharacter(profile1,colecao,texto5,cor_texto,janela,menu_cards,select_card,&sair,&mouseX,&mouseY,&deltaZ,&mouse,&mouse2,&mouse_lado,&keychar,&repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                                            else if(profile1 == profile2 && profile1 != NULL) {
                                                al_draw_textf(texto2,cor_texto,10,480,0,"Para iniciar o jogo, dois profiles diferentes devem ser inicializados!!!");
                                                al_flip_display();
                                                al_rest(2.0);
                                                profile1 = NULL;
                                            }
                                        }
                                        else al_draw_bitmap(pont,610,225,0);
                                    }
                                    else if(mouseX >= 190 && mouseX < 190 + 420 && mouseY >= 305 && mouseY < 305 + 90) {
                                        if(mouse == true) {
                                            //al_rest(0.2);

                                            profile2 = EscolheProfile(profiles,janela,texto4,texto5,cor_texto,pont,player2,select_card,&sair,&mouseX,&mouseY,&deltaZ,&mouse,&mouse2,&mouse_lado,&keychar,&repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                                            if(profile2 != NULL && (profile1 == NULL || profile1 != profile2)) EscolheCharacter(profile2,colecao,texto5,cor_texto,janela,menu_cards,select_card,&sair,&mouseX,&mouseY,&deltaZ,&mouse,&mouse2,&mouse_lado,&keychar,&repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                                            else if(profile1 == profile2 && profile2 != NULL) {
                                                al_draw_textf(texto2,cor_texto,10,480,0,"Para iniciar o jogo, dois profiles diferentes devem ser inicializados!!!");
                                                al_flip_display();
                                                al_rest(2.0);
                                                profile2 = NULL;
                                            }
                                        }
                                        else al_draw_bitmap(pont,610,325,0);
                                    }
                                    else if(profile1 != NULL && profile1->main_character != -1 && profile2 != NULL && profile2->main_character != -1 && mouseX >= 190 && mouseX < 190 + 420 && mouseY >= 405 && mouseY < 405 + 90) {
                                        if(mouse == true) {
                                            Jogo(colecao,profile1,profile2,janela,statusBox,select_card,roll_bar,fundo_jogo,pont,level_prompt,prompt,fundo_card,menu_cards,deck_meio,deck_cheio,prompt,escolher_tipo,lock,texto3,texto,texto5,cor_texto,save_state,timer,&sair,&mouseX,&mouseY,&deltaZ,&mouse,&mouse2,&mouse_lado,&keychar,&repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

                                            //al_rest(0.2);   //JOGAR!
                                            break;
                                        }
                                        else al_draw_bitmap(pont,610,425,0);
                                    }
                                    else if(mouseX >= 190 && mouseX < 190 + 420 && mouseY >= 505 && mouseY < 505 + 90) {
                                        if(mouse == true) {
                                            //al_rest(0.2);
                                            break;
                                        }
                                        else al_draw_bitmap(pont,610,525,0);
                                    }
                                    else if(mouseX >= 730 && mouseX < 730 + 30 && mouseY >= 435 && mouseY < 435 + 30 && mouse == true) {
                                        save_state = !save_state;
                                        //al_rest(0.2);
                                    }

                                    if(profile1 != NULL) {
                                        al_draw_textf(texto3,cor_texto,205,270,0,"%s --> %s",profile1->nome,profile1->nome_main_char);
                                        if(profile1->main_character != -1) al_draw_bitmap(cor_retangulo[1],150,235,0);
                                        else al_draw_bitmap(cor_retangulo[0],150,235,0);
                                    }
                                    if(profile2 != NULL) {
                                        al_draw_textf(texto3,cor_texto,205,370,0,"%s --> %s",profile2->nome,profile2->nome_main_char);
                                        if(profile2->main_character != -1) al_draw_bitmap(cor_retangulo[1],150,335,0);
                                        else al_draw_bitmap(cor_retangulo[0],150,335,0);
                                    }

                                    al_flip_display();
                                }
                            }
                            else al_draw_bitmap(pont,610,225,0);
                        }

                        else if(mouseX >= 190 && mouseX < 190 + 420 && mouseY >= 305 && mouseY < 305 + 90) {    //edit deck
                            if(mouse == true) {
                                printf("--> EDIT DECK\n");
                                //al_rest(0.2);
                                while(!sair) {
                                    al_flip_display();
                                    al_draw_bitmap(dados,0,0,0);

                                    VerificaEventos(&sair,&mouseX,&mouseY,&deltaZ,&mouse,&mouse2,&mouse_lado,&keychar,&repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

                                    if(mouseX >= 190 && mouseX < 190 + 420 && mouseY >= 205 && mouseY < 205 + 90) { //CRIAR PROFILE
                                        if(mouse == true) {
                                            CriarProfile(lista,total_cards,profiles,janela,texto5,texto3,cor_texto,criar_prof,select_card,botao,cor_retangulo,estilo_deck,&sair,&mouseX,&mouseY,&deltaZ,&mouse,&mouse2,&mouse_lado,&keychar,&repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                                            //Teste(profiles);
                                            LiberaProfile(profiles);      //processo para recuperar a lista de profiles disponiveis.
                                            CarregaProfile(&profiles,colecao);

                                            //al_rest(0.2);
                                            break;
                                        }
                                        else al_draw_bitmap(pont,610,225,0);
                                    }
                                    else if(mouseX >= 190 && mouseX < 190 + 420 && mouseY >= 305 && mouseY < 305 + 90) {    //ADMINISTRAR
                                        if(mouse == true) {
                                            AdministrarProfile(rbmap,colecao,profiles,janela,texto4,texto3,texto5,cor_texto,prompt,administrar_prof,pont,selecionar_prof,select_card,roll_bar,cor_retangulo,&sair,&mouseX,&mouseY,&deltaZ,&mouse,&mouse2,&mouse_lado,&keychar,&repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                                            //Teste(profiles);
                                            LiberaProfile(profiles);      //ao mudar o deck, altera-se tambem o estilo do jogo do deck.
                                            CarregaProfile(&profiles,colecao);

                                            //al_rest(0.2);
                                            break;
                                        }
                                        else al_draw_bitmap(pont,610,325,0);
                                    }
                                    else if(mouseX >= 190 && mouseX < 190 + 420 && mouseY >= 405 && mouseY < 405 + 90) {    //DELETAR
                                        if(mouse == true) {
                                            DeletarProfile(profiles,janela,cor_texto,deletar_prof,select_card,prompt,&sair,&mouseX,&mouseY,&deltaZ,&mouse,&mouse2,&mouse_lado,&keychar,&repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                                            //Teste(profiles);
                                            LiberaProfile(profiles);      //ao mudar o deck, altera-se tambem o estilo do jogo do deck.
                                            CarregaProfile(&profiles,colecao);

                                            //al_rest(0.2);
                                            break;
                                        }
                                        else al_draw_bitmap(pont,610,425,0);
                                    }
                                    else if(mouseX >= 190 && mouseX < 190 + 420 && mouseY >= 505 && mouseY < 505 + 90) {    //VOLTAR
                                        if(mouse == true) {
                                            //al_rest(0.2);
                                            break;
                                        }
                                        else al_draw_bitmap(pont,610,525,0);
                                    }
                                }
                            }
                            else al_draw_bitmap(pont,610,325,0);
                        }

                        else if(mouseX >= 190 && mouseX < 190 + 420 && mouseY >= 405 && mouseY < 405 + 90) {    //card list
                            if(mouse == true) {
                                //al_rest(0.2);
                                printf("--> CARD LIST\n");

                                //definir todas as listas aqui! Cards estarao TODOS na lista, cada qual em seu grupo.
                                //o diferencial eh o arquivo que contem a relacao de cards abertos! Este sera carregado na entrada do card list!

                                CardList(profiles,janela,total_cards,lista,texto3,texto4,texto5,cor_texto,lista_cards,select_card,roll_bar,pont,selecionar_prof,fundo_card,&sair,&mouseX,&mouseY,&deltaZ,&mouse,&mouse2,&mouse_lado,&keychar,&repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
                            }
                            else al_draw_bitmap(pont,610,425,0);
                        }

                        else if(mouseX >= 190 && mouseX < 190 + 420 && mouseY >= 505 && mouseY < 505 + 90) {    //sair
                            if(mouse == true) break;
                            else al_draw_bitmap(pont,610,525,0);
                        }
                        al_flip_display();
                    }
                    al_destroy_timer(timer);
                    al_destroy_timer(mouse_press_timer);
                    al_destroy_timer(keyb_press_timer);

                    LiberaProfile(profiles);
                    LiberaListaColecao(&lista);
                    free(total_cards);
                    DescarregaCartas(colecao);
                    DescarregaRupeeBitmap(rbmap);
                    DescarregaStatusBox(statusBox);
                    printf("Libera cards OK!\n");

                    al_destroy_bitmap(icon);
                    al_destroy_bitmap(pont);
                    al_destroy_bitmap(cursor);
                    al_destroy_bitmap(botao);
                    al_destroy_bitmap(roll_bar);

                    al_destroy_bitmap(cor_retangulo[0]);
                    al_destroy_bitmap(cor_retangulo[1]);
                    al_destroy_bitmap(cor_retangulo[2]);
                    free(cor_retangulo);

                    al_destroy_bitmap(lock);
                    al_destroy_bitmap(deck_meio);
                    al_destroy_bitmap(deck_cheio);
                    al_destroy_bitmap(menu);
                    al_destroy_bitmap(escolher_tipo);
                    al_destroy_bitmap(prompt);
                    al_destroy_bitmap(level_prompt);
                    al_destroy_bitmap(iniciar_jogo);
                    al_destroy_bitmap(menu_cards);
                    al_destroy_bitmap(player1);
                    al_destroy_bitmap(player2);
                    al_destroy_bitmap(selecionar_prof);
                    al_destroy_bitmap(dados);
                    al_destroy_bitmap(fundo_jogo);
                    al_destroy_bitmap(lista_cards);
                    al_destroy_bitmap(criar_prof);
                    al_destroy_bitmap(administrar_prof);
                    al_destroy_bitmap(deletar_prof);

                    al_destroy_bitmap(estilo_deck[0]);
                    al_destroy_bitmap(estilo_deck[1]);
                    al_destroy_bitmap(estilo_deck[2]);
                    al_destroy_bitmap(estilo_deck[3]);
                    al_destroy_bitmap(estilo_deck[4]);
                    al_destroy_bitmap(estilo_deck[5]);
                    al_destroy_bitmap(estilo_deck[6]);
                    al_destroy_bitmap(estilo_deck[7]);
                    al_destroy_bitmap(estilo_deck[8]);
                    free(estilo_deck);
                    printf("Libera bitmaps OK!\n");

                    al_destroy_font(texto);
                    al_destroy_font(texto2);
                    al_destroy_font(texto3);
                    al_destroy_font(texto4);
                    al_destroy_font(texto5);
                    printf("Libera fontes OK!\n");

                    al_flush_event_queue(event_queue);
                    printf("Libera ");
                    al_destroy_event_queue(event_queue);
                    printf("canvas ");
                    if(janela == NULL) printf("WUT?!\n");
                    al_destroy_display(janela);
                    printf("OK!\n");

                    al_uninstall_mouse();
                    printf("Libera sistema ");
                    al_uninstall_system();
                    printf("OK!\n");

                    return EXIT_SUCCESS;
                }
                else return(10);
            }
            else return(10);
        }
        else return(10);
    }
    else {
        al_show_native_message_box(NULL,"ERRO FATAL!","ERRO FATAL!","Falha ao INICIALIZAR Allegro!",NULL,ALLEGRO_MESSAGEBOX_ERROR);
        return(10);
    }
}

int main() {
    int saida;

    saida = MenuInicial();
    if(saida == 10) {
        printf("Allegro FALHOU!");
        return(-2);
    }

    return EXIT_SUCCESS;
}
