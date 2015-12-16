#ifndef MAGIC_JAR_H_INCLUDED
#define MAGIC_JAR_H_INCLUDED

void magic_jar(struct Card *card) {
        card->bmp = al_load_bitmap("cards/magic_jar.png");
        card->nome = "Magic Jar\0";
        card->elemento = "Light\0";
        card->colecao = 67;
        card->RARIDADE = 3;
        card->preco = 850;
        card->tipo = "Tactic\0";
        card->str_concat = "Light - Tactic - Recovery\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Draw 3 cards. Then put one card from your hand to the bottom of your deck.\0";
        card->tactic->level = 40;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip / Locate 70 - Play a monster or an equipment of level 70 or less or a field card.\0";
        card->lv_acao->nivel = 70;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void magic_jar_acao(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *apontador,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *escolhido;

    DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    if(jogador->hand->inicio->prox == NULL) return;
    do {
        escolhido = MenuCards("Select a card to go to the bottom of the deck.",true,jogador->hand->inicio,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    } while(escolhido == NULL);

    RetiraCardPorCopia(escolhido,&(jogador->hand));
    printf("1 ");

    escolhido->prox = (struct Deck *)malloc(sizeof(struct Deck));
    escolhido->prox->prox = NULL;

    printf("2 ");
    ColocaListaCardsNaBaseDeck(&(jogador->deck),escolhido);
    printf("OK ");
}

#endif // MAGIC_JAR_H_INCLUDED
