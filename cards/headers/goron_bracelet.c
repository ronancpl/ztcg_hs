#ifndef GORON_BRACELET_H_INCLUDED
#define GORON_BRACELET_H_INCLUDED

void goron_bracelet(struct Card *card) {
        card->bmp = al_load_bitmap("cards/goron_bracelet.png");
        card->nome = "Goron Bracelet\0";
        card->elemento = "Fire\0";
        card->colecao = 14;
        card->RARIDADE = 7;
        card->preco = 760;
        card->tipo = "Equipment\0";
        card->str_concat = "Fire - Equipment - Armor\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Once per turn, whenever you would do once a character action under your character, do it twice instead.\0";
        card->equip->level = 40;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Assistance - Get +10 damage at your first monster attack.\0";
        card->lv_acao->nivel = 20;
        card->lv_acao->atrib = 1;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void goron_bracelet_acao(int ponto_inicial,bool *fim,struct Player *jogador,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *menu,*aux2,*aux3,*retorna_card;
    struct char_action *aux;
    int i;

    menu = (struct Deck *)malloc(sizeof(struct Deck));
    menu->prox = NULL;
    //printf("BRACELET START...\n");

    aux2 = menu;
    aux = jogador->character_actions->prox->prox->prox;
    for(i = 0;i < ponto_inicial - 3;i++) {
        aux = aux->prox;
    }

    while(aux->prox != NULL) {
        if(aux->card->origem->lv_acao->nivel != 999 && strcmp(aux->card->origem->tipo,"Boss") != 0 && aux->nivel <= jogador->level && aux->goron_bracelet_bool == false && ((strcmp(aux->card->origem->elemento,"Earth") == 0 && aux->atrib <= jogador->earth_ic) || (strcmp(aux->card->origem->elemento,"Wind") == 0 && aux->atrib <= jogador->wind_ic) || (strcmp(aux->card->origem->elemento,"Fire") == 0 && aux->atrib <= jogador->fire_ic) || (strcmp(aux->card->origem->elemento,"Water") == 0 && aux->atrib <= jogador->water_ic) || (strcmp(aux->card->origem->elemento,"Light") == 0 && aux->atrib <= jogador->light_ic) || (strcmp(aux->card->origem->elemento,"Dark") == 0 && aux->atrib <= jogador->dark_ic))) {
            aux2->card = aux->card;
            aux2->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux2 = aux2->prox;
            aux2->prox = NULL;
        }
        aux = aux->prox;
    }

    retorna_card = MenuCards("Select the card which character action will be used TWICE...",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    if(retorna_card != NULL) {
        aux = jogador->character_actions->prox->prox->prox;
        while(aux->card != retorna_card->card) aux = aux->prox;

        aux->goron_bracelet_bool = true;
    }

    aux2 = menu;
    while(aux2->prox != NULL) {
        aux3 = aux2;
        aux2 = aux2->prox;
        free(aux3);
    }
    free(aux2);
}

#endif // GORON_BRACELET_H_INCLUDED
