#ifndef PLAY_OCARINA_H_INCLUDED
#define PLAY_OCARINA_H_INCLUDED

void play_ocarina(struct Card *card) {
        card->bmp = al_load_bitmap("cards/play_ocarina.png");
        card->nome = "Play Ocarina\0";
        card->elemento = "Light\0";
        card->colecao = 70;
        card->RARIDADE = 3;
        card->preco = 940;
        card->tipo = "Tactic\0";
        card->str_concat = "Light - Tactic - Skill\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Look at the 5 cards at the top of your deck, arrange these cards at an order of your choice and put it back.\0";
        card->tactic->level = 50;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Concussive Beam - Do 30 damage to a character or monster.\0";
        card->lv_acao->nivel = 80;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void play_ocarina_acao(int id_acao,struct Card **buffer,bool *fim,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *prompt,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer,int *rolagem) {
    struct Deck *alvo,*aux2,*aux3 = NULL;
    int i = 0;

    aux2 = jogador->deck->inicio;
    alvo = aux2;
    while(i < 5 && aux2->prox != NULL) {  //passa as 5 primeiras cartas do deck para uma lista independente, tirando-as do deck.
        aux3 = aux2;
        aux2 = aux2->prox;

        jogador->deck->quantidade--;
        i++;
    }
    if(aux3 == NULL) return;

    jogador->deck->inicio = aux2;
    aux3->prox = (struct Deck *)malloc(sizeof(struct Deck));
    aux3->prox->prox = NULL;

    printf("2 ");
    ArranjaOrdem(id_acao,alvo,buffer,fim,sbox,selecao,roll_bar,fundo_menu,prompt,fundo_carta,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    jogador->deck->quantidade += QuantidadeListaCards(alvo);

    aux3 = alvo;
    while(aux3->prox->prox != NULL) aux3 = aux3->prox;
    free(aux3->prox);
    printf("3 ");
    aux3->prox = jogador->deck->inicio;
    jogador->deck->inicio = alvo;

    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    printf("OK\n");
}

#endif // PLAY_OCARINA_H_INCLUDED
