#ifndef CARD_ACOES3_C_INCLUDED
#define CARD_ACOES3_C_INCLUDED

void milk_bottle_acao(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    RefreshHP(id_acao,buffer,jogador->mesa->character,50,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    DrawCard(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void heart_piece_acao(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(ElaboraPrompt("Heart Piece USED! Select an option:",NULL,NULL,NULL,"+80 HP","+40 MaxHP",215,470,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        RefreshHP(id_acao,buffer,jogador->mesa->character,80,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else {
        *(jogador->MaxHP) = *(jogador->MaxHP) + 40;
        *(jogador->HP) = *(jogador->HP) + 40;
    }
}

void skulltulas_ambush_acao(struct CARD *card,int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *prompt,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool resultado, ko = false;

    resultado = LancaMoeda(id_acao,buffer,fim_de_jogo,rolagem,sbox,selecao,roll_bar,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    if(resultado == true) {
        if(adversario->mesa->monstro1 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,1,sbox,jogador,adversario,card,NULL,jogador->level,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro2 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,2,sbox,jogador,adversario,card,NULL,jogador->level,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro3 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,3,sbox,jogador,adversario,card,NULL,jogador->level,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro4 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,4,sbox,jogador,adversario,card,NULL,jogador->level,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro5 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,5,sbox,jogador,adversario,card,NULL,jogador->level,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro6 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,6,sbox,jogador,adversario,card,NULL,jogador->level,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro7 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,7,sbox,jogador,adversario,card,NULL,jogador->level,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,0,sbox,jogador,adversario,card,NULL,jogador->level,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    DrawCard(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void deku_seeds_bag_acao(struct CARD *card,int id_acao,struct Card **buffer,bool *fim_de_jogo,bool *ko,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    //assume CARD == dekuseedsbag
    int card1,card2,card3,dmg1,dmg2;

    printf("INICIO DSB");
    if(jogador->deck->inicio->prox == NULL) {
        RetornaSubcards(card,jogador->deck);
        DrawCard(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        DrawCard(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        DrawCard(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        return;
    }

    //coloca novo card debaixo de DSB...
    InsereCardAssociado(&card,jogador->deck->inicio);
    jogador->deck->inicio = jogador->deck->inicio->prox;
    jogador->deck->quantidade--;

    printf("3 ");
    if(card->qte_associado == 3) {
        printf("-> ");

        card1 = RecuperaCardLevel(card->cards_associados->deck->card->origem);
        card2 = RecuperaCardLevel(card->cards_associados->prox->deck->card->origem);
        card3 = RecuperaCardLevel(card->cards_associados->prox->prox->deck->card->origem);
        printf("C1: %s\tC2: %s\tC3: %s\n", card->cards_associados->deck->card->origem->nome, card->cards_associados->prox->deck->card->origem->nome, card->cards_associados->prox->prox->deck->card->origem->nome);

        dmg1 = RetornaMaiorAproximado(card1,card2,card3);
        dmg2 = RetornaMedioAproximado(card1,card2,card3);
        printf("4 ");

        if(ElaboraPrompt("Deku Seeds Bag reached 3 cards! Select TARGET:","Character: %d dmg; Monsters: %d dmg",(void *)dmg1,(void *)dmg2,"CHARACTER","MONSTERS",195,475,315,id_acao,buffer,fim_de_jogo,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
            Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,0,sbox,jogador,adversario,card,NULL,dmg1,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
        else {
            if(adversario->mesa->monstro1 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,1,sbox,jogador,adversario,card,NULL,dmg2,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            if(adversario->mesa->monstro2 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,2,sbox,jogador,adversario,card,NULL,dmg2,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            if(adversario->mesa->monstro3 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,3,sbox,jogador,adversario,card,NULL,dmg2,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            if(adversario->mesa->monstro4 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,4,sbox,jogador,adversario,card,NULL,dmg2,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            if(adversario->mesa->monstro5 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,5,sbox,jogador,adversario,card,NULL,dmg2,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            if(adversario->mesa->monstro6 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,6,sbox,jogador,adversario,card,NULL,dmg2,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            if(adversario->mesa->monstro7 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,7,sbox,jogador,adversario,card,NULL,dmg2,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
        printf("7 ");
        card->cards_associados->deck->prox = card->cards_associados->prox->deck;
        printf("7.01 ");
        card->cards_associados->deck->prox->prox = card->cards_associados->prox->prox->deck;
        printf("7.02 ");
        card->cards_associados->deck->prox->prox->prox = (struct Deck *)malloc(sizeof(struct Deck));
        printf("7.03 ");
        card->cards_associados->deck->prox->prox->prox->prox = NULL;
        printf("7.1 ");
        ArranjaOrdem(id_acao,card->cards_associados->deck,buffer,fim_de_jogo,sbox,selecao,roll_bar,fundo_menu,prompt,fundo_carta,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        printf("7.2 ");

        ColocaListaCardsNaBaseDeck(&(jogador->deck),card->cards_associados->deck);
        LiberaEstruturaCardsAssociados(card);
    }

    printf("terminou!\n");
}

void bomb_bag_bonus(int bonus_dmg,bool *fim,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo,struct Player *jogador,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *alvo,*aux,*aux2;
    struct Deck *card;
    char *str = (char *)calloc(100,sizeof(char));
    char temp[4];

    strcpy(str,"Select a monster to receive Bomb Bag BONUS ATTACK... (");
    itoa(bonus_dmg,temp,10);
    strcat(str,temp);
    strcat(str," damage)");

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

    //al_rest(0.2);
    card = MenuCards(str,true,alvo,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(card != NULL) {
        if(jogador->mesa->monstro1 == card->card) jogador->mesa->monstro1->var_monster->bomb_bag_bonus_dmg_cont += bonus_dmg;
        else if(jogador->mesa->monstro2 == card->card) jogador->mesa->monstro2->var_monster->bomb_bag_bonus_dmg_cont += bonus_dmg;
        else if(jogador->mesa->monstro3 == card->card) jogador->mesa->monstro3->var_monster->bomb_bag_bonus_dmg_cont += bonus_dmg;
        else if(jogador->mesa->monstro4 == card->card) jogador->mesa->monstro4->var_monster->bomb_bag_bonus_dmg_cont += bonus_dmg;
        else if(jogador->mesa->monstro5 == card->card) jogador->mesa->monstro5->var_monster->bomb_bag_bonus_dmg_cont += bonus_dmg;
        else if(jogador->mesa->monstro6 == card->card) jogador->mesa->monstro6->var_monster->bomb_bag_bonus_dmg_cont += bonus_dmg;
        else jogador->mesa->monstro7->var_monster->bomb_bag_bonus_dmg_cont += bonus_dmg;
    }

    aux = alvo;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);

    free(str);
}

void bomb_bag_acao(struct CARD *card,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    CardAssociado aux,aux2 = NULL;  //assume CARD == dekuseedsbag
    int card_val[3],dmg_min,dmg_max;
    struct Deck *aux_hand,*aux_menu,*ant,*escolhido,*menu;

    printf("\nINICIO BOMB BAG ");
    printf("1 ");

    Menu_Cria(&menu,&aux_menu);
    aux_hand = jogador->hand->inicio;

    while(aux_hand->prox != NULL) {
        if(ehMonstro(aux_hand->card)) {
            Menu_CopiaDado(&aux_menu,aux_hand->card);
        }

        aux_hand = aux_hand->prox;
    }
    Menu_CelulaFinal(&aux_menu);

    printf("2 ");
    escolhido = MenuCards("BOMB BAG: Choose a monster to STOCK (right click to skip)",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(escolhido != NULL) {
        aux_hand = jogador->hand->inicio;
        ant = NULL;

        while(aux_hand->card != escolhido->card) {
            ant = aux_hand;
            aux_hand = aux_hand->prox;
        }

        if(ant != NULL) ant->prox = aux_hand->prox;
        else jogador->hand->inicio = jogador->hand->inicio->prox;
        jogador->hand->quantidade--;

        aux = card->cards_associados;
        while(aux->prox != NULL) aux = aux->prox;
        aux->deck = aux_hand;

        aux->prox = (struct card_associado *)malloc(sizeof(struct card_associado));
        aux->prox->prox = NULL;
        card->qte_associado++;

        DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    Menu_Finaliza(menu);

    printf("3 ");
    if(card->qte_associado == 3) {
        printf("-> ");

        card_val[0] = RetornaAproximado(card->cards_associados->deck->card->attack / 2);
        card_val[1] = RetornaAproximado(card->cards_associados->prox->deck->card->attack / 2);
        card_val[2] = RetornaAproximado(card->cards_associados->prox->prox->deck->card->attack / 2);

        dmg_min = card_val[0];
        dmg_max = card_val[0];

        if(card_val[1] > dmg_max) dmg_max = card_val[1];
        else if(card_val[1] < dmg_min) dmg_min = card_val[1];

        if(card_val[2] > dmg_max) dmg_max = card_val[2];
        else if(card_val[2] < dmg_min) dmg_min = card_val[2];

        printf("4 ");
        if(ElaboraPrompt("Bomb Bag FULL! Destroy RANDOMLY a stocked monster?","Damage gain: MIN %d, MAX %d",(void *)dmg_min,(void *)dmg_max,"Yes","No",240,515,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
            if(DiscardRandomAssocCard(card->cards_associados,id_acao,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,pont,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
                bomb_bag_bonus(RetornaAproximado(jogador->graveyard->inicio->card->attack / 2),fim,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,jogador,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            }
            printf("5 ");
        }

        printf("LISTA ATUAL:");
        aux = card->cards_associados;
        while(aux->prox != NULL) {
            printf("'%s' ",aux->deck->card->origem->nome);
            aux = aux->prox;
        }
        printf("\n");

        aux = card->cards_associados->prox;
        aux_menu = card->cards_associados->deck;
        while(1) {
            aux_menu->prox = aux->deck;
            aux_menu = aux_menu->prox;
            aux = aux->prox;

            if(aux->prox == NULL) break;
        }

        aux_menu->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux_menu->prox->prox = NULL;

        printf("LISTA ATUAL2:");
        aux_menu = card->cards_associados->deck;
        while(aux_menu->prox != NULL) {
            printf("'%s', ",aux_menu->card->origem->nome);
            aux_menu = aux_menu->prox;
        }
        printf("\n");

        printf("7.1 ");
        //ArranjaOrdem(id_acao,card->cards_associados->deck,buffer,fim_de_jogo,sbox,selecao,roll_bar,fundo_menu,prompt,fundo_carta,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,mouse_state,rolagem);
        printf("7.2 ");

        ColocaListaCardsNaBaseDeck(&(jogador->deck),card->cards_associados->deck);

        printf("8 ");
        aux = card->cards_associados;
        aux2 = NULL;
        while(aux->prox != NULL) {
            aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
        free(aux);

        printf("9 ");
        card->cards_associados = (struct card_associado *)malloc(sizeof(struct card_associado));
        card->cards_associados->prox = NULL;
        card->qte_associado -= 3;
    }

    printf("terminou!\n");
}

bool bomb_bag_lvacao(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,struct CARD *card_origem,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int damage = 10;
    bool ativo;

    printf("BOMB BAG lvacao\n");
    ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,1,1,0,sbox,jogador,adversario,card_origem,NULL,damage,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    while(*ko == true) {
        damage += 10;
        Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,0,1,0,sbox,jogador,adversario,card_origem,NULL,damage,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    return(ativo);
}

void bless_of_triforce_unit_unbuff(struct CARD *card,int instancias) {
    card->MaxHP -= (20*instancias);
    card->HP -= (20*instancias);
}

void bless_of_triforce_unit_buff(struct CARD *card,int instancias) {
    card->MaxHP += (20*instancias);
    card->HP += (20*instancias);

    card->var_monster->bless_of_triforce_buff_cont += instancias;
}

void bless_of_triforce_buff(struct Player *jogador,struct Player *adversario) {
    if(jogador->mesa->monstro1 != NULL) bless_of_triforce_unit_buff(jogador->mesa->monstro1,1);
    if(jogador->mesa->monstro2 != NULL) bless_of_triforce_unit_buff(jogador->mesa->monstro2,1);
    if(jogador->mesa->monstro3 != NULL) bless_of_triforce_unit_buff(jogador->mesa->monstro3,1);
    if(jogador->mesa->monstro4 != NULL) bless_of_triforce_unit_buff(jogador->mesa->monstro4,1);
    if(jogador->mesa->monstro5 != NULL) bless_of_triforce_unit_buff(jogador->mesa->monstro5,1);
    if(jogador->mesa->monstro6 != NULL) bless_of_triforce_unit_buff(jogador->mesa->monstro6,1);
    if(jogador->mesa->monstro7 != NULL) bless_of_triforce_unit_buff(jogador->mesa->monstro7,1);

    if(adversario->mesa->monstro1 != NULL) bless_of_triforce_unit_buff(adversario->mesa->monstro1,1);
    if(adversario->mesa->monstro2 != NULL) bless_of_triforce_unit_buff(adversario->mesa->monstro2,1);
    if(adversario->mesa->monstro3 != NULL) bless_of_triforce_unit_buff(adversario->mesa->monstro3,1);
    if(adversario->mesa->monstro4 != NULL) bless_of_triforce_unit_buff(adversario->mesa->monstro4,1);
    if(adversario->mesa->monstro5 != NULL) bless_of_triforce_unit_buff(adversario->mesa->monstro5,1);
    if(adversario->mesa->monstro6 != NULL) bless_of_triforce_unit_buff(adversario->mesa->monstro6,1);
    if(adversario->mesa->monstro7 != NULL) bless_of_triforce_unit_buff(adversario->mesa->monstro7,1);
}

void bless_of_triforce_acao(int id_acao,struct CARD *card,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool ko = false;

    Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,2,0,sbox,jogador,adversario,card,NULL,80,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RefreshHP(id_acao,buffer,jogador->mesa->character,80,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    bless_of_triforce_buff(jogador,adversario);
}

void small_key_acao(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *aux,*aux2 = NULL,*card = NULL,*menu;
    bool toggle = false;
    short i = 0;

    aux = jogador->deck->inicio;
    Menu_Cria(&menu,&aux2);

    while(aux->prox != NULL && i < 8) {
        toggle = true;
        Menu_CopiaDado(&aux2,aux->card);

        i++;
        aux = aux->prox;
    }
    Menu_CelulaFinal(&aux2);

    if(toggle) {
        card = MenuCards("Select and DRAW a card from the deck...",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        MoveCardProTopo(&(jogador->deck),card);
        if(card != NULL) DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    Menu_Finaliza(menu);
    EmbaralhaDeck(jogador->deck->inicio,jogador->deck->quantidade);
}

void EscolheCardDoDeck(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *aux,*aux2 = NULL,*card = NULL,*menu;
    bool toggle = false;

    aux = jogador->deck->inicio;
    Menu_Cria(&menu,&aux2);

    while(aux->prox != NULL) {
        if(RecuperaCardLevel(aux->card->origem) <= jogador->level) {
            toggle = true;
            Menu_CopiaDado(&aux2,aux->card);
        }
        aux = aux->prox;
    }
    Menu_CelulaFinal(&aux2);

    printf("escolhe card do deck ");
    if(toggle) {
        card = MenuCards("Select and DRAW a card from the deck...",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        MoveCardProTopo(&(jogador->deck),card);
        if(card != NULL) DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    Menu_Finaliza(menu);

    printf("quase: ");
    EmbaralhaDeck(jogador->deck->inicio,jogador->deck->quantidade);
    printf("OK\n");
}

void SelectDestroyMonster(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *menu,*aux,*aux2,*retorna_card = NULL;
    bool ko = false;

    menu = (struct Deck *)malloc(sizeof(struct Deck));
    menu->prox = NULL;
    aux = menu;

    if(adversario->mesa->monstro1 != NULL && !EhBoss(adversario->mesa->monstro1)) {
        aux->card = adversario->mesa->monstro1;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(adversario->mesa->monstro2 != NULL && !EhBoss(adversario->mesa->monstro2)) {
        aux->card = adversario->mesa->monstro2;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(adversario->mesa->monstro3 != NULL && !EhBoss(adversario->mesa->monstro3)) {
        aux->card = adversario->mesa->monstro3;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(adversario->mesa->monstro4 != NULL && !EhBoss(adversario->mesa->monstro4)) {
        aux->card = adversario->mesa->monstro4;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(adversario->mesa->monstro5 != NULL && !EhBoss(adversario->mesa->monstro5)) {
        aux->card = adversario->mesa->monstro5;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(adversario->mesa->monstro6 != NULL && !EhBoss(adversario->mesa->monstro6)) {
        aux->card = adversario->mesa->monstro6;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(adversario->mesa->monstro7 != NULL && !EhBoss(adversario->mesa->monstro7)) {
        aux->card = adversario->mesa->monstro7;
        aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
        aux = aux->prox;
        aux->prox = NULL;
    }

    retorna_card = MenuCards("Select a monster to destroy.",true,menu,fim_de_jogo,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(retorna_card != NULL) {
        if(adversario->mesa->monstro1 == retorna_card->card) {
            Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,1,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
        else if(adversario->mesa->monstro2 == retorna_card->card) {
            Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,2,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
        else if(adversario->mesa->monstro3 == retorna_card->card) {
            Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,3,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
        else if(adversario->mesa->monstro4 == retorna_card->card) {
            Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,4,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
        else if(adversario->mesa->monstro5 == retorna_card->card) {
            Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,5,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
        else if(adversario->mesa->monstro6 == retorna_card->card) {
            Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,6,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
        else {
            Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,7,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
    }

    aux = menu;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);
}

void bomb_rain_acao(struct CARD *bomb_rain,int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    short contador;
    bool ko = false;

    if(!MonstroPresente(adversario)) {
        Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,0,sbox,jogador,adversario,bomb_rain,NULL,70,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else {
        contador = 3;
        while(contador > 0 && MonstroPresente(adversario)) {
            SelectDestroyMonster(id_acao,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            contador--;
        }
    }
}

void cucco_lady_acao(struct Card *slot,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(RecuperaCardLevel(slot) <= 30) {
        if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->origem->colecao == CUCCO_LADY && jogador->mesa->monstro1->turn_silenced == 0) DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->origem->colecao == CUCCO_LADY && jogador->mesa->monstro2->turn_silenced == 0) DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->origem->colecao == CUCCO_LADY && jogador->mesa->monstro3->turn_silenced == 0) DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->origem->colecao == CUCCO_LADY && jogador->mesa->monstro4->turn_silenced == 0) DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->origem->colecao == CUCCO_LADY && jogador->mesa->monstro5->turn_silenced == 0) DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->origem->colecao == CUCCO_LADY && jogador->mesa->monstro6->turn_silenced == 0) DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->origem->colecao == CUCCO_LADY && jogador->mesa->monstro7->turn_silenced == 0) DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
}

void triple_shot_acao(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    SelectDestroyMonster(id_acao,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    DrawCard(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void ice_arrow_slot(struct CARD *source,struct CARD *card,int slot,int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(!strcmp(card->origem->elemento,"Fire") && !EhBoss(card)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,ko,4,2,slot,sbox,jogador,adversario,source,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else {
        card->turn_cooldown += 1;
        SilenciaAuras(fim_de_jogo,card,1,jogador,adversario);
    }
}

void ice_arrow_acao(struct CARD *source,int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *alvo,*aux;
    struct Deck *card;
    bool ko = false;

    Menu_Cria(&alvo,&aux);

    if(adversario->mesa->monstro1 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro1);
    if(adversario->mesa->monstro2 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro2);
    if(adversario->mesa->monstro3 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro3);
    if(adversario->mesa->monstro4 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro4);
    if(adversario->mesa->monstro5 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro5);
    if(adversario->mesa->monstro6 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro6);
    if(adversario->mesa->monstro7 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro7);

    Menu_CelulaFinal(&aux);

    //al_rest(0.2);
    card = MenuCards("Select ICE ARROW target...",true,alvo,fim_de_jogo,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(card != NULL) {
        if(adversario->mesa->monstro1 == card->card) ice_arrow_slot(source,adversario->mesa->monstro1,1,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(adversario->mesa->monstro2 == card->card) ice_arrow_slot(source,adversario->mesa->monstro2,2,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(adversario->mesa->monstro3 == card->card) ice_arrow_slot(source,adversario->mesa->monstro3,3,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(adversario->mesa->monstro4 == card->card) ice_arrow_slot(source,adversario->mesa->monstro4,4,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(adversario->mesa->monstro5 == card->card) ice_arrow_slot(source,adversario->mesa->monstro5,5,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(adversario->mesa->monstro6 == card->card) ice_arrow_slot(source,adversario->mesa->monstro6,6,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else ice_arrow_slot(source,adversario->mesa->monstro7,7,id_acao,buffer,fim_de_jogo,rolagem,&ko,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    Menu_Finaliza(alvo);
}

void open_chest_acao(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *aux;

    aux = jogador->deck->inicio;
    while(aux->prox != NULL) {
        if(strcmp(aux->card->origem->tipo,"Equipment") == 0) {
            MoveCardProTopo(&(jogador->deck),aux);
            DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

            EmbaralhaDeck(jogador->deck->inicio,jogador->deck->quantidade);
            break;
        }

        aux = aux->prox;
    }
}

void raze_acao(int id_acao,struct CARD *card,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool ko = false;

    if(adversario->mesa->monstro1 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,1,sbox,jogador,adversario,card,NULL,40,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro2 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,2,sbox,jogador,adversario,card,NULL,40,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro3 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,3,sbox,jogador,adversario,card,NULL,40,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro4 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,4,sbox,jogador,adversario,card,NULL,40,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro5 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,5,sbox,jogador,adversario,card,NULL,40,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro6 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,6,sbox,jogador,adversario,card,NULL,40,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro7 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,7,sbox,jogador,adversario,card,NULL,40,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,0,sbox,jogador,adversario,card,NULL,40,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    IncluiInstancia(jogador,"Raze",2);
}

void dins_fire_acao(int id_acao,struct CARD *card,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool ko = false;

    if(adversario->mesa->monstro1 != NULL && !EhBoss(adversario->mesa->monstro1)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,1,sbox,jogador,adversario,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro2 != NULL && !EhBoss(adversario->mesa->monstro2)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,2,sbox,jogador,adversario,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro3 != NULL && !EhBoss(adversario->mesa->monstro3)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,3,sbox,jogador,adversario,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro4 != NULL && !EhBoss(adversario->mesa->monstro4)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,4,sbox,jogador,adversario,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro5 != NULL && !EhBoss(adversario->mesa->monstro5)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,5,sbox,jogador,adversario,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro6 != NULL && !EhBoss(adversario->mesa->monstro6)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,6,sbox,jogador,adversario,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->monstro7 != NULL && !EhBoss(adversario->mesa->monstro7)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,7,sbox,jogador,adversario,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    if(jogador->mesa->monstro1 != NULL && !EhBoss(jogador->mesa->monstro1)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,1,sbox,adversario,jogador,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->monstro2 != NULL && !EhBoss(jogador->mesa->monstro2)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,2,sbox,adversario,jogador,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->monstro3 != NULL && !EhBoss(jogador->mesa->monstro3)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,3,sbox,adversario,jogador,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->monstro4 != NULL && !EhBoss(jogador->mesa->monstro4)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,4,sbox,adversario,jogador,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->monstro5 != NULL && !EhBoss(jogador->mesa->monstro5)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,5,sbox,adversario,jogador,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->monstro6 != NULL && !EhBoss(jogador->mesa->monstro6)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,6,sbox,adversario,jogador,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->monstro7 != NULL && !EhBoss(jogador->mesa->monstro7)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,7,sbox,adversario,jogador,card,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,3,2,0,sbox,jogador,adversario,card,NULL,40,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void guillotine_acao(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,struct CARD *card,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int i;
    bool ko = true;

    if(ElaboraPrompt("Guillotine USED! Select an option:",NULL,NULL,NULL,"Damage Char.","Kill Monsters",215,480,315,id_acao,buffer,fim_de_jogo,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,3,2,0,sbox,jogador,adversario,card,NULL,40,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else {
        for(i = 0;i < 2;i++) SelectDestroyMonster(id_acao,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
}

bool CardMesmoTipo(struct Card *card1,struct Card *card2) {
    if(!strcmp(card1->tipo,card2->tipo)) return(true);
    else return(false);
}

void compass_slot(struct CARD *equip,struct CARD *jogado,int id_acao,struct Card **buffer,bool *fim,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *apontador,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,int *rolagem,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(equip->var_equip->compass_bool == false || jogador->deck->inicio->prox == NULL) return;

    OlhaCarta(id_acao,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);
    if(CardMesmoTipo(jogado->origem,jogador->deck->inicio->card->origem)) {
        DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    equip->var_equip->compass_bool = false;
}

void compass_acao(struct CARD *jogado,int id_acao,struct Card **buffer,bool *fim,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *select_card,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,int *rolagem,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(jogador->mesa->equip1 != NULL) compass_slot(jogador->mesa->equip1,jogado,id_acao,buffer,fim,sbox,prompt,select_card,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip2 != NULL) compass_slot(jogador->mesa->equip2,jogado,id_acao,buffer,fim,sbox,prompt,select_card,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip3 != NULL) compass_slot(jogador->mesa->equip3,jogado,id_acao,buffer,fim,sbox,prompt,select_card,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip4 != NULL) compass_slot(jogador->mesa->equip4,jogado,id_acao,buffer,fim,sbox,prompt,select_card,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip5 != NULL) compass_slot(jogador->mesa->equip5,jogado,id_acao,buffer,fim,sbox,prompt,select_card,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip6 != NULL) compass_slot(jogador->mesa->equip6,jogado,id_acao,buffer,fim,sbox,prompt,select_card,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip7 != NULL) compass_slot(jogador->mesa->equip7,jogado,id_acao,buffer,fim,sbox,prompt,select_card,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void shadow_merge_acao(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *alvo,*alvo2,*aux,*aux2,*retorna_card = NULL;
    bool ko = false;
    int cont = 0;

    alvo = (struct Deck *)malloc(sizeof(struct Deck));
    aux = alvo;
    shadow_merge_insere_alvo(&aux,jogador->mesa->monstro1);
    shadow_merge_insere_alvo(&aux,jogador->mesa->monstro2);
    shadow_merge_insere_alvo(&aux,jogador->mesa->monstro3);
    shadow_merge_insere_alvo(&aux,jogador->mesa->monstro4);
    shadow_merge_insere_alvo(&aux,jogador->mesa->monstro5);
    shadow_merge_insere_alvo(&aux,jogador->mesa->monstro6);
    shadow_merge_insere_alvo(&aux,jogador->mesa->monstro7);
    aux->prox = NULL;

    cont = 0;
    aux = alvo;
    while(aux->prox != NULL) {
        cont++;
        aux = aux->prox;
    }
    printf("%d ",cont);

    alvo2 = (struct Deck *)malloc(sizeof(struct Deck));
    aux2 = alvo2;
    shadow_merge_insere_alvo(&aux2,adversario->mesa->monstro1);
    shadow_merge_insere_alvo(&aux2,adversario->mesa->monstro2);
    shadow_merge_insere_alvo(&aux2,adversario->mesa->monstro3);
    shadow_merge_insere_alvo(&aux2,adversario->mesa->monstro4);
    shadow_merge_insere_alvo(&aux2,adversario->mesa->monstro5);
    shadow_merge_insere_alvo(&aux2,adversario->mesa->monstro6);
    shadow_merge_insere_alvo(&aux2,adversario->mesa->monstro7);
    aux2->prox = NULL;

    cont = 0;
    aux2 = alvo2;
    while(aux2->prox != NULL) {
        cont++;
        aux2 = aux2->prox;
    }
    printf(" %d\n",cont);

    if(alvo->prox != NULL && alvo2->prox != NULL) {
        while(retorna_card == NULL) retorna_card = MenuCards("Select one of YOUR monsters to destroy.",true,alvo,fim_de_jogo,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(jogador->mesa->monstro1 == retorna_card->card) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,1,sbox,adversario,jogador,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(jogador->mesa->monstro2 == retorna_card->card) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,2,sbox,adversario,jogador,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(jogador->mesa->monstro3 == retorna_card->card) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,3,sbox,adversario,jogador,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(jogador->mesa->monstro4 == retorna_card->card) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,4,sbox,adversario,jogador,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(jogador->mesa->monstro5 == retorna_card->card) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,5,sbox,adversario,jogador,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(jogador->mesa->monstro6 == retorna_card->card) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,6,sbox,adversario,jogador,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,7,sbox,adversario,jogador,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        retorna_card = NULL;
        while(retorna_card == NULL) retorna_card = MenuCards("Select one of YOUR OPPONENT's monster to destroy.",true,alvo2,fim_de_jogo,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro1 == retorna_card->card) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,1,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(adversario->mesa->monstro2 == retorna_card->card) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,2,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(adversario->mesa->monstro3 == retorna_card->card) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,3,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(adversario->mesa->monstro4 == retorna_card->card) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,4,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(adversario->mesa->monstro5 == retorna_card->card) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,5,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if(adversario->mesa->monstro6 == retorna_card->card) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,6,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,7,sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        jogador->var_tactic->shadow_merge_spawn_cont += 1;
    }

    aux = alvo;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);

    aux = alvo2;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);
}

void skull_mask_acao2(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *menu,*aux,*aux2,*escolhido;
    bool ko = false;

    if(*(jogador->HP) <= 30) return;

    aux = jogador->hand->inicio;

    Menu_Cria(&menu,&aux2);
    while(aux->prox != NULL) {
        if(ehMonstro(aux->card) && aux->card->level_drop < 10)
            Menu_CopiaDado(&aux2,aux->card);

        aux = aux->prox;
    }
    Menu_CelulaFinal(&aux2);

    escolhido = MenuCards("Pick a monster on your hand to get its level REDUCED BY 10 for one turn.",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(escolhido != NULL) {
        Attack(-1,false,false,buffer,fim,rolagem,&ko,4,0,0,sbox,adversario,jogador,NULL,NULL,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        escolhido->card->level_drop = 10;
    }

    Menu_Finaliza(menu);
}

bool ganondorf_acao2(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool ativo = false;

    ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,0,1,0,sbox,jogador,adversario,jogador->mesa->character,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(PossuiWeapon(jogador)) ativo = (Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,2,1,0,sbox,jogador,adversario,jogador->mesa->character,NULL,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer) || ativo);
    return(ativo);
}

void chest_acao(struct CARD *card,int id_acao,struct Card **buffer,bool *fim_de_jogo,bool *ko,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *menu,*escolhido,*aux,*aux2 = NULL;
    CardAssociado aux3;
    //STOCK STATUS: 0 -> nunca stockado
    //              1 -> pronto para retirar / stockado antes
    //              2 -> stockado ha um turno

    aux3 = card->cards_associados;
    while(aux3->prox != NULL) {
        if(aux3->deck->card->var_equip->stocked_status > 0) aux3->deck->card->var_equip->stocked_status = 1;
        aux3 = aux3->prox;
    }

    if(card->qte_associado < 2) {
        Menu_Cria(&menu,&aux2);
        printf("criou\n");
        if(aux2 == NULL) printf("wtflel");
        aux = jogador->hand->inicio;

        while(aux->prox != NULL) {
            if(aux->card->origem->equip != NULL && aux->card->var_equip->stocked_status == 0) {
                Menu_CopiaDado(&aux2,aux->card);
                printf("copiou\n");
                //printf("'%s'\n",aux2->card->origem->nome);
            }
            aux = aux->prox;
        }
        Menu_CelulaFinal(&aux2);
        printf("inseriu final\n");

        aux2 = menu;
        while(aux2->prox != NULL) {
            printf("'%s' ",aux2->card->origem->nome);
            aux2 = aux2->prox;
        }
        printf("FIM\n");

        if(menu->prox != NULL && ElaboraPrompt("Do you want to STOCK an equipment?",NULL,NULL,NULL,"Yes","No",240,515,315,id_acao,buffer,fim_de_jogo,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
            escolhido = MenuCards("Choose an equipment to STOCK.",true,menu,fim_de_jogo,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            if(escolhido != NULL) {
                escolhido = RetiraCardPorCopiaInstancia(escolhido,&(jogador->hand));
                escolhido->card->var_equip->stocked_status = 2;
                InsereCardAssociado(&card,escolhido);

                if(card->qte_associado == 2) DrawCard(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            }
        }

        Menu_Finaliza(menu);
        printf("finalizou\n");
    }

    Menu_Cria(&menu,&aux2);
    aux3 = card->cards_associados;
    while(aux3->prox != NULL) {
        if(aux3->deck->card->var_equip->stocked_status == 1) {
            Menu_CopiaDado(&aux2,aux3->deck->card);
        }
        aux3 = aux3->prox;
    }
    Menu_CelulaFinal(&aux2);

    if(menu->prox != NULL && ElaboraPrompt("Do you want to RETRIEVE an equipment?",NULL,NULL,NULL,"Yes","No",240,515,315,id_acao,buffer,fim_de_jogo,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        escolhido = MenuCards("Choose an equipment to RETRIEVE.",true,menu,fim_de_jogo,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(escolhido != NULL) {
            escolhido = LiberaCardAssociadoPorCopia(card,escolhido);
            ColocaCardNaBaseDeck(&(jogador->hand),escolhido);
        }
    }

    Menu_Finaliza(menu);
}

void skull_kid_acao(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *aux,*escolhido,*menu;

    if(LancaMoeda(id_acao,buffer,fim_de_jogo,rolagem,sbox,selecao,roll_bar,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        Menu_Cria(&menu,&aux);
        if(jogador->mesa->monstro1 != NULL && RecuperaCardLevel(jogador->mesa->monstro1->origem) <= 50 && jogador->mesa->monstro1->var_monster->skull_kid_bool == false) Menu_CopiaDado(&aux,jogador->mesa->monstro1);
        if(jogador->mesa->monstro2 != NULL && RecuperaCardLevel(jogador->mesa->monstro2->origem) <= 50 && jogador->mesa->monstro2->var_monster->skull_kid_bool == false) Menu_CopiaDado(&aux,jogador->mesa->monstro2);
        if(jogador->mesa->monstro3 != NULL && RecuperaCardLevel(jogador->mesa->monstro3->origem) <= 50 && jogador->mesa->monstro3->var_monster->skull_kid_bool == false) Menu_CopiaDado(&aux,jogador->mesa->monstro3);
        if(jogador->mesa->monstro4 != NULL && RecuperaCardLevel(jogador->mesa->monstro4->origem) <= 50 && jogador->mesa->monstro4->var_monster->skull_kid_bool == false) Menu_CopiaDado(&aux,jogador->mesa->monstro4);
        if(jogador->mesa->monstro5 != NULL && RecuperaCardLevel(jogador->mesa->monstro5->origem) <= 50 && jogador->mesa->monstro5->var_monster->skull_kid_bool == false) Menu_CopiaDado(&aux,jogador->mesa->monstro5);
        if(jogador->mesa->monstro6 != NULL && RecuperaCardLevel(jogador->mesa->monstro6->origem) <= 50 && jogador->mesa->monstro6->var_monster->skull_kid_bool == false) Menu_CopiaDado(&aux,jogador->mesa->monstro6);
        if(jogador->mesa->monstro7 != NULL && RecuperaCardLevel(jogador->mesa->monstro7->origem) <= 50 && jogador->mesa->monstro7->var_monster->skull_kid_bool == false) Menu_CopiaDado(&aux,jogador->mesa->monstro7);
        Menu_CelulaFinal(&aux);

        escolhido = MenuCards("SKULL KID: Choose a monster to receive DOUBLE DAMAGE.",true,menu,fim_de_jogo,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(escolhido != NULL) escolhido->card->var_monster->skull_kid_bool = true;

        Menu_Finaliza(menu);

        DrawCard(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else DrawCard(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void fire_arrow_acao(struct CARD *source,int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool ko = false;
    struct CARD *card = NULL;

    Attack(-1,true,true,buffer,fim_de_jogo,rolagem,&ko,1,2,0,sbox,jogador,adversario,source,&card,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(ko == true) {
        if(adversario->turn_away == 0) IncluiDOT(adversario->mesa->character,source,20,2);
    }
    else if(!strcmp(card->origem->elemento,"Water") && !EhBoss(card)) Attack(id_acao,false,false,buffer,fim_de_jogo,rolagem,&ko,4,2,RetornaMonsterSlot(adversario,card),sbox,jogador,adversario,NULL,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void jump_quest(char *elemento,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(LancaMoeda2(id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        EscolheCardDoDeck(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
    else {
        //DAMAGE MULTIPLIER 150% / 200%
        struct Deck *alvo,*aux;
        struct Deck *escolhido;

        Menu_Cria(&alvo,&aux);

        if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->turn_cooldown == 0) Menu_CopiaDado(&aux,jogador->mesa->monstro1);
        if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->turn_cooldown == 0) Menu_CopiaDado(&aux,jogador->mesa->monstro2);
        if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->turn_cooldown == 0) Menu_CopiaDado(&aux,jogador->mesa->monstro3);
        if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->turn_cooldown == 0) Menu_CopiaDado(&aux,jogador->mesa->monstro4);
        if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->turn_cooldown == 0) Menu_CopiaDado(&aux,jogador->mesa->monstro5);
        if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->turn_cooldown == 0) Menu_CopiaDado(&aux,jogador->mesa->monstro6);
        if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->turn_cooldown == 0) Menu_CopiaDado(&aux,jogador->mesa->monstro7);
        Menu_CelulaFinal(&aux);

        al_rest(0.2);
        escolhido = MenuCards("JUMP QUEST buff...",true,alvo,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(escolhido != NULL)
            strcmp(escolhido->card->origem->elemento,elemento) ? (escolhido->card->var_monster->damage_multiplier += 50) : (escolhido->card->var_monster->damage_multiplier += 100);

        Menu_Finaliza(alvo);
    }
}

void whirling_scythes_acao(struct CARD *ws,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int koed = 0;
    bool ko = false;

    if(adversario->mesa->monstro1 != NULL && Attack(id_acao,true,false,buffer,fim,rolagem,&ko,3,2,1,sbox,jogador,adversario,ws,NULL,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer) && ko == true) koed++;
    if(adversario->mesa->monstro2 != NULL && Attack(id_acao,true,false,buffer,fim,rolagem,&ko,3,2,2,sbox,jogador,adversario,ws,NULL,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer) && ko == true) koed++;
    if(adversario->mesa->monstro3 != NULL && Attack(id_acao,true,false,buffer,fim,rolagem,&ko,3,2,3,sbox,jogador,adversario,ws,NULL,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer) && ko == true) koed++;
    if(adversario->mesa->monstro4 != NULL && Attack(id_acao,true,false,buffer,fim,rolagem,&ko,3,2,4,sbox,jogador,adversario,ws,NULL,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer) && ko == true) koed++;
    if(adversario->mesa->monstro5 != NULL && Attack(id_acao,true,false,buffer,fim,rolagem,&ko,3,2,5,sbox,jogador,adversario,ws,NULL,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer) && ko == true) koed++;
    if(adversario->mesa->monstro6 != NULL && Attack(id_acao,true,false,buffer,fim,rolagem,&ko,3,2,6,sbox,jogador,adversario,ws,NULL,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer) && ko == true) koed++;
    if(adversario->mesa->monstro7 != NULL && Attack(id_acao,true,false,buffer,fim,rolagem,&ko,3,2,7,sbox,jogador,adversario,ws,NULL,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer) && ko == true) koed++;
    if(Attack(id_acao,true,false,buffer,fim,rolagem,&ko,3,2,0,sbox,jogador,adversario,ws,NULL,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer) && ko == true) koed++;

    printf("Whirling Scythes: draw %d cards.\n",koed);
    while(koed > 0) {
        DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        koed--;
    }
}

void redead_alvo(int *damage,struct CARD *alvo,struct CARD *redead,int id_acao,struct Card **buffer,bool *fim,int *rolagem,bool *ko,int restricoes,int origem_ataque,int slot,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    *damage += alvo->origem->monster->attack;
    Attack(id_acao,false,false,buffer,fim,rolagem,ko,restricoes,origem_ataque,slot,sbox,jogador,adversario,redead,NULL,999,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void redead_acao(struct CARD *redead,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int damage = 0,alvos;
    struct Deck *menu,*aux,*escolhido;
    bool ko;

    Menu_Cria(&menu,&aux);
    if(adversario->mesa->monstro1 != NULL && !EhBoss(adversario->mesa->monstro1) && RecuperaCardLevel(adversario->mesa->monstro1->origem) <= 40) Menu_CopiaDado(&aux,adversario->mesa->monstro1);
    if(adversario->mesa->monstro2 != NULL && !EhBoss(adversario->mesa->monstro2) && RecuperaCardLevel(adversario->mesa->monstro2->origem) <= 40) Menu_CopiaDado(&aux,adversario->mesa->monstro2);
    if(adversario->mesa->monstro3 != NULL && !EhBoss(adversario->mesa->monstro3) && RecuperaCardLevel(adversario->mesa->monstro3->origem) <= 40) Menu_CopiaDado(&aux,adversario->mesa->monstro3);
    if(adversario->mesa->monstro4 != NULL && !EhBoss(adversario->mesa->monstro4) && RecuperaCardLevel(adversario->mesa->monstro4->origem) <= 40) Menu_CopiaDado(&aux,adversario->mesa->monstro4);
    if(adversario->mesa->monstro5 != NULL && !EhBoss(adversario->mesa->monstro5) && RecuperaCardLevel(adversario->mesa->monstro5->origem) <= 40) Menu_CopiaDado(&aux,adversario->mesa->monstro5);
    if(adversario->mesa->monstro6 != NULL && !EhBoss(adversario->mesa->monstro6) && RecuperaCardLevel(adversario->mesa->monstro6->origem) <= 40) Menu_CopiaDado(&aux,adversario->mesa->monstro6);
    if(adversario->mesa->monstro7 != NULL && !EhBoss(adversario->mesa->monstro7) && RecuperaCardLevel(adversario->mesa->monstro7->origem) <= 40) Menu_CopiaDado(&aux,adversario->mesa->monstro7);
    Menu_CelulaFinal(&aux);

    for(alvos = 0;alvos < 2;alvos++) {
        escolhido = MenuCards("REDEAD: Select a monster to destroy...",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if(escolhido != NULL) {
            if(escolhido->card == adversario->mesa->monstro1) redead_alvo(&damage,adversario->mesa->monstro1,redead,id_acao,buffer,fim,rolagem,&ko,4,0,1,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            else if(escolhido->card == adversario->mesa->monstro2) redead_alvo(&damage,adversario->mesa->monstro2,redead,id_acao,buffer,fim,rolagem,&ko,4,0,2,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            else if(escolhido->card == adversario->mesa->monstro3) redead_alvo(&damage,adversario->mesa->monstro3,redead,id_acao,buffer,fim,rolagem,&ko,4,0,3,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            else if(escolhido->card == adversario->mesa->monstro4) redead_alvo(&damage,adversario->mesa->monstro4,redead,id_acao,buffer,fim,rolagem,&ko,4,0,4,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            else if(escolhido->card == adversario->mesa->monstro5) redead_alvo(&damage,adversario->mesa->monstro5,redead,id_acao,buffer,fim,rolagem,&ko,4,0,5,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            else if(escolhido->card == adversario->mesa->monstro6) redead_alvo(&damage,adversario->mesa->monstro6,redead,id_acao,buffer,fim,rolagem,&ko,4,0,6,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            else if(escolhido->card == adversario->mesa->monstro7) redead_alvo(&damage,adversario->mesa->monstro7,redead,id_acao,buffer,fim,rolagem,&ko,4,0,7,sbox,jogador,adversario,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            else printf("ERRO: card invalido detectado para '%s'!\n",escolhido->card->origem->nome);

            RetiraCardPorCopiaMenu(escolhido,&menu);
        }
    }

    Menu_Finaliza(menu);

    if(damage > 0) {
        printf("redead shriek: %d dmg.\n",damage);
        Attack(id_acao,true,false,buffer,fim,rolagem,&ko,4,0,0,sbox,jogador,adversario,redead,NULL,damage,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
}

void freezard_lvacao(int id_acao,struct Card **buffer,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *prompt,bool *fim_de_jogo,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(jogador->wind_ic >= 3) {
        DestroyMonster(id_acao,buffer,rolagem,sbox,selecao,roll_bar,prompt,fim_de_jogo,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
}

void tricky_shot_acao(int id_acao,struct CARD *card,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int val = TotalMobsEmCampo(jogador,adversario,2),i;
    struct Deck *menu,*escolhido;
    bool ko;

    if(val == 0) return;

    menu = RetiraVariosCards(&(jogador->deck),val);
    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    while(1) {
        escolhido = MenuCards("TRICKY SHOT: DISCARD and convert into 30 damage attack (CLICK 'X' TO DISMISS).",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(escolhido == NULL) break;

        RetiraCardPorCopiaMenu(escolhido,&menu);
        ColocaNovoCardNoDeck(&(jogador->graveyard),escolhido);

        Attack(id_acao,true,false,buffer,fim,rolagem,&ko,0,2,0,sbox,jogador,adversario,card,NULL,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    val = RetornaQuantidadeCardsNaLista(menu);
    printf("TRICKY SHOT comprando %d cards.\n",val);

    ColocaListaCardsNoTopoDeck(&(jogador->deck),menu);
    for(i = 0;i < val;i++) DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

#endif // CARD_ACOES3_C_INCLUDED
