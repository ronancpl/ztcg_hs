#ifndef GANON_H_INCLUDED
#define GANON_H_INCLUDED

void ganon(struct Card *card) {
        card->bmp = al_load_bitmap("cards/ganon.png");
        card->nome = "GANON\0";
        card->elemento = "Dark\0";
        card->colecao = 24;
        card->RARIDADE = 1;
        card->preco = 2500;
        card->tipo = "Boss\0";
        card->str_concat = "Dark - Boss\0";

        card->boss = (struct boss *)malloc(sizeof(struct boss));
        card->boss->level = 120;
        card->boss->attack = 80;
        card->boss->MaxHP = 250;

        card->boss->acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->boss->acao->acao = "Ultra Vicious - Select one of your monsters on the field. That monster may perform up to 4 attacks at the same turn.\0";
        card->boss->acao->atrib = 3;
        card->boss->acao->nivel = 100;

        card->boss->acao->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->boss->acao->prox->prox = NULL;

        card->tactic = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "\0";
        card->lv_acao->nivel = 0;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void ganon_acao(int id_acao,struct Card **buffer,bool *fim,struct CARD *ganon,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *menu,*aux;
    struct Deck *retorna_card;
    ALLEGRO_FONT *font2,*font3;

    font2 = al_load_ttf_font("data/triforce.ttf", 6,0);
    font3 = al_load_ttf_font("data/triforce.ttf",10,0);
    menu = (struct Deck *)malloc(sizeof(struct CARD));
    menu->prox = NULL;
    printf("Comeca boss ");

    aux = menu;
    if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1 != ganon && jogador->mesa->monstro1->turn_cooldown == 0) {
        aux->card = jogador->mesa->monstro1;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2 != ganon && jogador->mesa->monstro2->turn_cooldown == 0) {
        aux->card = jogador->mesa->monstro2;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3 != ganon && jogador->mesa->monstro3->turn_cooldown == 0) {
        aux->card = jogador->mesa->monstro3;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4 != ganon && jogador->mesa->monstro4->turn_cooldown == 0) {
        aux->card = jogador->mesa->monstro4;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5 != ganon && jogador->mesa->monstro5->turn_cooldown == 0) {
        aux->card = jogador->mesa->monstro5;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6 != ganon && jogador->mesa->monstro6->turn_cooldown == 0) {
        aux->card = jogador->mesa->monstro6;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7 != ganon && jogador->mesa->monstro7->turn_cooldown == 0) {
        aux->card = jogador->mesa->monstro7;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }
    printf("1 ");

    retorna_card = MenuCards("SELECT a monster (perform 4 attacks at the same turn)...",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font3,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    printf("2 ");
    if(retorna_card != NULL) {
        if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1 == retorna_card->card) AdicionaNovaQuantidadeAtaque(&(jogador->mesa->monstro1->var_monster->lista_qte_ataques),ganon,4);
        else if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2 == retorna_card->card) AdicionaNovaQuantidadeAtaque(&(jogador->mesa->monstro2->var_monster->lista_qte_ataques),ganon,4);
        else if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3 == retorna_card->card) AdicionaNovaQuantidadeAtaque(&(jogador->mesa->monstro3->var_monster->lista_qte_ataques),ganon,4);
        else if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4 == retorna_card->card) AdicionaNovaQuantidadeAtaque(&(jogador->mesa->monstro4->var_monster->lista_qte_ataques),ganon,4);
        else if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5 == retorna_card->card) AdicionaNovaQuantidadeAtaque(&(jogador->mesa->monstro5->var_monster->lista_qte_ataques),ganon,4);
        else if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6 == retorna_card->card) AdicionaNovaQuantidadeAtaque(&(jogador->mesa->monstro6->var_monster->lista_qte_ataques),ganon,4);
        else AdicionaNovaQuantidadeAtaque(&(jogador->mesa->monstro7->var_monster->lista_qte_ataques),ganon,4);
    }

    printf("3 ");
    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    al_destroy_font(font2);
    al_destroy_font(font3);
}

#endif // GANON_H_INCLUDED
