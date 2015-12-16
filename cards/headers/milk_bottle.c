#ifndef MILK_BOTTLE_H_INCLUDED
#define MILK_BOTTLE_H_INCLUDED

void milk_bottle(struct Card *card) {
        card->bmp = al_load_bitmap("cards/milk_bottle.png");
        card->nome = "Milk Bottle\0";
        card->elemento = "Light\0";
        card->colecao = 50;
        card->RARIDADE = 7;
        card->preco = 520;
        card->tipo = "Tactic\0";
        card->str_concat = "Light - Tactic - Recovery\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Recover 50 HP. Draw a card.\0";
        card->tactic->level = 15;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Buff - Select a monster to receive additional 30 damage with its attack for one turn.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void milk_bottle_lvacao(bool *fim,struct Player *jogador,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *alvo,*aux,*aux2,*escolhido = NULL;

    alvo = (struct Deck *)malloc(sizeof(struct Deck));
    alvo->prox = NULL;
    aux = alvo;

    if(jogador->mesa->monstro1 != NULL) {
        aux->card = jogador->mesa->monstro1;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(jogador->mesa->monstro2 != NULL) {
        aux->card = jogador->mesa->monstro2;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(jogador->mesa->monstro3 != NULL) {
        aux->card = jogador->mesa->monstro3;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(jogador->mesa->monstro4 != NULL) {
        aux->card = jogador->mesa->monstro4;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(jogador->mesa->monstro5 != NULL) {
        aux->card = jogador->mesa->monstro5;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(jogador->mesa->monstro6 != NULL) {
        aux->card = jogador->mesa->monstro6;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(jogador->mesa->monstro7 != NULL) {
        aux->card = jogador->mesa->monstro7;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    escolhido = MenuCards("Select the monster which will be applied +30 attack...",true,alvo,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(escolhido != NULL) {
        escolhido->card->var_monster->milk_bottle_bool = true;
        printf("Detectou INSTABUFF (+30 atk)\n");
    }

    aux = alvo;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);
}

#endif // MILK_BOTTLE_H_INCLUDED
