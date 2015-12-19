#ifndef CARD_ACOES_C_INCLUDED
#define CARD_ACOES_C_INCLUDED

//SOMENTE acoes que dependem da existencia de alguma funcao!
void deku_seeds_bag_lvacao(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int cont = 0;
    bool not_prevent;

    if(jogador->mesa->monstro1 != NULL) cont++;
    if(jogador->mesa->monstro2 != NULL) cont++;
    if(jogador->mesa->monstro3 != NULL) cont++;
    if(jogador->mesa->monstro4 != NULL) cont++;
    if(jogador->mesa->monstro5 != NULL) cont++;
    if(jogador->mesa->monstro6 != NULL) cont++;
    if(jogador->mesa->monstro7 != NULL) cont++;

    if(adversario->mesa->monstro1 != NULL) cont++;
    if(adversario->mesa->monstro2 != NULL) cont++;
    if(adversario->mesa->monstro3 != NULL) cont++;
    if(adversario->mesa->monstro4 != NULL) cont++;
    if(adversario->mesa->monstro5 != NULL) cont++;
    if(adversario->mesa->monstro6 != NULL) cont++;
    if(adversario->mesa->monstro7 != NULL) cont++;

    if(cont == 0) return;
    not_prevent = LancaMoeda(id_acao,buffer,fim_de_jogo,rolagem,sbox,selecao,roll_bar,prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    Attack(id_acao,!not_prevent,false,buffer,fim_de_jogo,rolagem,ko,0,1,0,sbox,jogador,adversario,jogador->mesa->character,NULL,20*cont,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void twinrova_acao1(int id_acao,struct Card **buffer,bool *fim,struct CARD *card_twinrova,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *coin_prompt,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *prompt,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool resultado;

    printf("TR acao (%d pontos) ",card_twinrova->var_monster->twinrova_cont);
    Attack(id_acao,true,false,buffer,fim,rolagem,ko,2,0,0,sbox,jogador,adversario,card_twinrova,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    printf("1 ");
    resultado = LancaMoeda(id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,coin_prompt,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(resultado == true) {
        card_twinrova->var_monster->twinrova_cont++;
        if(card_twinrova->var_monster->twinrova_cont == 3) {
            card_twinrova->var_monster->twinrova_cont = 0;
            Attack(id_acao,true,false,buffer,fim,rolagem,ko,2,0,0,sbox,jogador,adversario,card_twinrova,NULL,120,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
    }
    else {
        card_twinrova->var_monster->twinrova_cont = 0;
    }
    printf("OK!\n");
}

bool princess_zelda_acao2(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(ElaboraPrompt("USE Magic Blast?","10 damage to monsters, 20 damage to character.",NULL,NULL,"Yes","No",250,523,315,id_acao,buffer,fim_de_jogo,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        if(adversario->mesa->monstro1 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,1,sbox,jogador,adversario,jogador->mesa->character,NULL,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro2 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,2,sbox,jogador,adversario,jogador->mesa->character,NULL,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro3 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,3,sbox,jogador,adversario,jogador->mesa->character,NULL,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro4 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,4,sbox,jogador,adversario,jogador->mesa->character,NULL,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro5 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,5,sbox,jogador,adversario,jogador->mesa->character,NULL,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro6 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,6,sbox,jogador,adversario,jogador->mesa->character,NULL,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro7 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,7,sbox,jogador,adversario,jogador->mesa->character,NULL,10,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,1,0,sbox,jogador,adversario,jogador->mesa->character,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        return(true);
    }
    return(false);
}

void bongobongo_acao2(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,struct CARD *atacante,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *prompt,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(ElaboraPrompt("USE Earthquake?","20 damage to monsters, 20 damage to character.",NULL,NULL,"Yes","No",250,523,315,id_acao,buffer,fim_de_jogo,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,bmp,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        if(adversario->mesa->monstro1 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,0,1,sbox,jogador,adversario,atacante,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro2 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,0,2,sbox,jogador,adversario,atacante,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro3 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,0,3,sbox,jogador,adversario,atacante,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro4 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,0,4,sbox,jogador,adversario,atacante,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro5 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,0,5,sbox,jogador,adversario,atacante,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro6 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,0,6,sbox,jogador,adversario,atacante,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(adversario->mesa->monstro7 != NULL) Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,0,7,sbox,jogador,adversario,atacante,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,3,0,0,sbox,jogador,adversario,atacante,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }
}

bool king_zora_acao3(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool ativo = false;

    ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,1,1,0,sbox,jogador,adversario,jogador->mesa->character,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    ativo = (Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,2,1,0,sbox,jogador,adversario,jogador->mesa->character,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer) || ativo);
    return(ativo);
}

void phantom_ganon_acao(struct Card **buffer,bool *fim_de_jogo,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,struct CARD *atacante,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *prompt,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(jogador->level >= 90 && jogador->earth_ic >= 3) Attack(-1,true,false,buffer,fim_de_jogo,rolagem,ko,0,0,0,sbox,jogador,adversario,atacante,NULL,80,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void gohma_acao(struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
        struct Deck *menu,*aux,*aux2,*card = NULL;
        bool toggle = false;

        if(!Possui_mobslot(jogador)) return;

        aux = jogador->deck->inicio;

        Menu_Cria(&menu,&aux2);
        while(aux->prox != NULL) {
            if(strstr(aux->card->origem->str_concat,"Spider") != NULL && strcmp(aux->card->origem->tipo,"Monster") == 0 && ((strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) || (strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) || (strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) || (strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) || (strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) || (strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0))) {
                toggle = true;
                Menu_CopiaDado(&aux2,aux->card);
            }

            aux = aux->prox;
        }
        Menu_CelulaFinal(&aux2);

        if(toggle) {
            card = MenuCards("Pull a SPIDER monster from your deck to play.",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            if(card == NULL) toggle = false;
            else {
                card = RetiraCardPorCopiaInstancia(card,&(jogador->deck));
                ColocaCardNaBaseDeck(&(jogador->hand),card);
            }
        }

        Menu_Finaliza(menu);

        if(!toggle) return;

        SpawnX(-1,true,buffer,fim,rolagem,sbox,jogador,adversario,jogador->level,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EmbaralhaDeck(jogador->deck->inicio,jogador->deck->quantidade);
}

void big_deku_baba_acao(struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
        struct Deck *menu,*aux,*aux2,*card = NULL;
        bool toggle = false;
        printf("big deku baba ACAO\n");

        if(!Possui_mobslot(jogador)) return;

        aux = jogador->deck->inicio;

        Menu_Cria(&menu,&aux2);
        while(aux->prox != NULL) {
            if(strstr(aux->card->origem->str_concat,"Deku") != NULL && strcmp(aux->card->origem->tipo,"Monster") == 0 && ((strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) || (strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) || (strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) || (strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) || (strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) || (strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0))) {
                toggle = true;
                Menu_CopiaDado(&aux2,aux->card);
            }

            aux = aux->prox;
        }
        Menu_CelulaFinal(&aux2);

        if(toggle) {
            card = MenuCards("Pull a DEKU monster from your deck to play.",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            if(card == NULL) toggle = false;
            else {
                card = RetiraCardPorCopiaInstancia(card,&(jogador->deck));
                ColocaCardNaBaseDeck(&(jogador->hand),card);
            }
        }

        Menu_Finaliza(menu);

        if(!toggle) return;

        SpawnX(-1,true,buffer,fim,rolagem,sbox,jogador,adversario,jogador->level,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EmbaralhaDeck(jogador->deck->inicio,jogador->deck->quantidade);
}

void big_poe_acao(struct CARD *big_poe,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
        struct Deck *menu,*aux,*aux2,*card = NULL;
        bool toggle = false;

        if(!Possui_mobslot(jogador)) return;

        aux = jogador->deck->inicio;
        Menu_Cria(&menu,&aux2);

        while(aux->prox != NULL) {
            if(strstr(aux->card->origem->str_concat,"Ghost") != NULL && strcmp(aux->card->origem->tipo,"Monster") == 0 && ((strcmp(aux->card->origem->elemento,"Earth") == 0 && jogador->earth_ic > 0) || (strcmp(aux->card->origem->elemento,"Wind") == 0 && jogador->wind_ic > 0) || (strcmp(aux->card->origem->elemento,"Fire") == 0 && jogador->fire_ic > 0) || (strcmp(aux->card->origem->elemento,"Water") == 0 && jogador->water_ic > 0) || (strcmp(aux->card->origem->elemento,"Light") == 0 && jogador->light_ic > 0) || (strcmp(aux->card->origem->elemento,"Dark") == 0 && jogador->dark_ic > 0))) {
                toggle = true;
                Menu_CopiaDado(&aux2,aux->card);
            }

            aux = aux->prox;
        }
        Menu_CelulaFinal(&aux2);

        if(toggle) {
            card = MenuCards("Pull a GHOST monster from your deck to play.",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            if(card == NULL) toggle = false;
            else {
                card = RetiraCardPorCopiaInstancia(card,&(jogador->deck));
                ColocaCardNaBaseDeck(&(jogador->hand),card);
            }
        }

        Menu_Finaliza(menu);

        if(!toggle) return;

        printf("aplicando em '%s' o efeito\n",card->card->origem->nome);
        IncluiBuff(card->card,big_poe,20,20,0,2);
        SpawnX(-1,true,buffer,fim,rolagem,sbox,jogador,adversario,jogador->level,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        EmbaralhaDeck(jogador->deck->inicio,jogador->deck->quantidade);
}

void leever_acao(int id_acao,struct Card **buffer,bool *fim,int *rolagem,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_BITMAP *prompt,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *card;

    if(VerificaCardPorNome(GIANT_LEEVER,jogador->hand) && jogador->level >= 50 && !BossPresente(jogador)) {
        if(ElaboraPrompt("CALL Giant Leever?","Leever was destroyed.",NULL,NULL,"Yes","No",250,523,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
            card = RetiraCardPorNome(GIANT_LEEVER,&(jogador->hand));
            card->card->var_monster->giant_leever_bool = true;

            ColocaCardNaBaseDeck(&(jogador->hand),card);
            SpawnX(id_acao,true,buffer,fim,rolagem,sbox,jogador,adversario,999,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
    }
}

void bari_acao(int id_acao,struct Card **buffer,bool *fim,int *rolagem,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_BITMAP *prompt,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *card;
    int slot;

    if(VerificaCardPorNome(BIRI,jogador->deck)) {
        if(ElaboraPrompt("SPAWN Biri?","Bari was destroyed.",NULL,NULL,"Yes","No",250,523,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
            card = RetiraCardPorNome(BIRI,&(jogador->deck));

            slot = RetornaProxSlotVazio(jogador);

            ColocaCardNaBaseDeck(&(jogador->hand),card);
            SpawnX(id_acao,true,buffer,fim,rolagem,sbox,jogador,adversario,999,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

            printf("slot: %d\n",slot);
            switch(slot) {
            case 1:
                jogador->mesa->monstro1->HP = 20;
                jogador->mesa->monstro1->var_monster->biri_bool = true;
                break;

            case 2:
                jogador->mesa->monstro2->HP = 20;
                jogador->mesa->monstro2->var_monster->biri_bool = true;
                break;

            case 3:
                jogador->mesa->monstro3->HP = 20;
                jogador->mesa->monstro3->var_monster->biri_bool = true;
                break;

            case 4:
                jogador->mesa->monstro4->HP = 20;
                jogador->mesa->monstro4->var_monster->biri_bool = true;
                break;

            case 5:
                jogador->mesa->monstro5->HP = 20;
                jogador->mesa->monstro5->var_monster->biri_bool = true;
                break;

            case 6:
                jogador->mesa->monstro6->HP = 20;
                jogador->mesa->monstro6->var_monster->biri_bool = true;
                break;

            case 7:
                jogador->mesa->monstro7->HP = 20;
                jogador->mesa->monstro7->var_monster->biri_bool = true;
                break;
            }
        }
    }
}

void shadow_merge_play_monster(struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *alvo,*aux,*aux2,*retorna_card = NULL;

    if(!Possui_mobslot(jogador)) return;

    alvo = (struct Deck *)malloc(sizeof(struct Deck));
    alvo->prox = NULL;
    aux2 = alvo;

    aux = jogador->hand->inicio;
    while(aux->prox != NULL) {
        if(ehMonstro(aux->card) && RecuperaCardLevel(aux->card->origem) <= jogador->level && !(EhBoss(aux->card) && BossPresente(jogador))) {
            aux2->card = aux->card;
            aux2->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux2 = aux2->prox;
        }

        aux = aux->prox;
    }
    aux2->prox = NULL;

    retorna_card = MenuCards("SHADOW MERGE: Play a monster from your hand.",true,alvo,fim_de_jogo,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(retorna_card != NULL) {
        aux = jogador->hand->inicio;
        while(aux->card != retorna_card->card) aux = aux->prox;
        retorna_card = aux;

        MoveCardPraBase(&(jogador->hand),retorna_card);
        SpawnX(-1,true,buffer,fim_de_jogo,rolagem,sbox,jogador,adversario,jogador->level,display,prompt,selecao,roll_bar,apontador,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    aux = alvo;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);
}

bool golden_gauntlets_lvacao(int id_acao,struct Card **buffer,struct CARD *card_origem,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *lock,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *prompt,bool *fim_de_jogo,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,ALLEGRO_TIMER *timer,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int damage = 0;
    bool ko = false;

    if(adversario->mesa->monstro1 != NULL) damage += 20;
    if(adversario->mesa->monstro2 != NULL) damage += 20;
    if(adversario->mesa->monstro3 != NULL) damage += 20;
    if(adversario->mesa->monstro4 != NULL) damage += 20;
    if(adversario->mesa->monstro5 != NULL) damage += 20;
    if(adversario->mesa->monstro6 != NULL) damage += 20;
    if(adversario->mesa->monstro7 != NULL) damage += 20;

    return(Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,&ko,0,1,0,sbox,jogador,adversario,card_origem,NULL,damage,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,apontador,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer));
}

bool impa_acao3(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Coordenadas *lista,*aux,*aux2;
    struct CARD *slot = NULL;
    bool ko = false,ativo = false;

    if(*(jogador->HP) <= 30) return(false);

    lista = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
    lista->prox = NULL;

    aux = lista;
    if(adversario->mesa->monstro1 != NULL) {
        aux->x = adversario->mesa->monstro1->PosicaoX;
        aux->y = adversario->mesa->monstro1->PosicaoY;

        aux->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(adversario->mesa->monstro2 != NULL) {
        aux->x = adversario->mesa->monstro2->PosicaoX;
        aux->y = adversario->mesa->monstro2->PosicaoY;

        aux->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(adversario->mesa->monstro3 != NULL) {
        aux->x = adversario->mesa->monstro3->PosicaoX;
        aux->y = adversario->mesa->monstro3->PosicaoY;

        aux->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(adversario->mesa->monstro4 != NULL) {
        aux->x = adversario->mesa->monstro4->PosicaoX;
        aux->y = adversario->mesa->monstro4->PosicaoY;

        aux->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(adversario->mesa->monstro5 != NULL) {
        aux->x = adversario->mesa->monstro5->PosicaoX;
        aux->y = adversario->mesa->monstro5->PosicaoY;

        aux->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(adversario->mesa->monstro6 != NULL) {
        aux->x = adversario->mesa->monstro6->PosicaoX;
        aux->y = adversario->mesa->monstro6->PosicaoY;

        aux->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(adversario->mesa->monstro7 != NULL) {
        aux->x = adversario->mesa->monstro7->PosicaoX;
        aux->y = adversario->mesa->monstro7->PosicaoY;

        aux->prox = (struct Coordenadas *)malloc(sizeof(struct Coordenadas));
        aux = aux->prox;
        aux->prox = NULL;
    }

    if(lista->prox == NULL) {
        free(lista);
        return(false);
    }

    while(1) {
        AtualizaMesa(true,"ACTION: Startle (Right Button to skip this action)",id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,lista,-1,-1,0,-1,NULL,NULL);
        if(*fim == true) return(false);

        if(*mouse2 == true) break;
        if(*mouse == true) {
            if(*posX >= 300 && *posX < 300 + 50 && *posY >= 190 && *posY < 190 + 75 && adversario->mesa->monstro1 != NULL) {
                slot = adversario->mesa->monstro1;
                break;
            }
            else if(*posX >= 355 && *posX < 355 + 50 && *posY >= 190 && *posY < 190 + 75 && adversario->mesa->monstro2 != NULL) {
                slot = adversario->mesa->monstro2;
                break;
            }
            else if(*posX >= 410 && *posX < 410 + 50 && *posY >= 190 && *posY < 190 + 75 && adversario->mesa->monstro3 != NULL) {
                slot = adversario->mesa->monstro3;
                break;
            }
            else if(*posX >= 465 && *posX < 465 + 50 && *posY >= 190 && *posY < 190 + 75 && adversario->mesa->monstro4 != NULL) {
                slot = adversario->mesa->monstro4;
                break;
            }
            else if(*posX >= 520 && *posX < 520 + 50 && *posY >= 190 && *posY < 190 + 75 && adversario->mesa->monstro5 != NULL) {
                slot = adversario->mesa->monstro5;
                break;
            }
            else if(*posX >= 575 && *posX < 575 + 50 && *posY >= 190 && *posY < 190 + 75 && adversario->mesa->monstro6 != NULL) {
                slot = adversario->mesa->monstro6;
                break;
            }
            else if(*posX >= 630 && *posX < 630 + 50 && *posY >= 190 && *posY < 190 + 75 && adversario->mesa->monstro7 != NULL) {
                slot = adversario->mesa->monstro7;
                break;
            }
        }
    }


    if(slot != NULL) {
        ativo = true;
        slot->turn_cooldown = 3;
        Attack(-1,false,false,buffer,fim,rolagem,&ko,4,0,0,sbox,adversario,jogador,NULL,NULL,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,pont,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    }

    aux = lista;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);

    //al_rest(0.2);
    return(ativo);
}

void mirror_shield_counter(struct CARD *equip,struct Card **buffer,bool *fim_de_jogo,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(equip != NULL && equip->var_equip->mirror_shield_cont >= 3) {
        printf("COUNTER: mirror shield with %d dmg.\n",equip->var_equip->mirror_shield_dmg);
        Attack(-1,true,false,buffer,fim_de_jogo,rolagem,ko,0,3,0,sbox,jogador,adversario,equip,NULL,equip->var_equip->mirror_shield_dmg,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        equip->var_equip->mirror_shield_cont = 0;
        equip->var_equip->mirror_shield_dmg = 0;
    }
}

bool channeled_strike_lvacao(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *bmp,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    bool ativo = false;

    ativo = Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,0,1,0,sbox,jogador,adversario,jogador->mesa->character,NULL,20,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    ativo = (Attack(id_acao,true,false,buffer,fim_de_jogo,rolagem,ko,2,1,0,sbox,jogador,adversario,jogador->mesa->character,NULL,30,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,bmp,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer) || ativo);
    return(ativo);
}

void purple_rupee_acao(struct CARD **card,int id_acao,struct Card **buffer,bool *fim,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *prompt,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer,int *rolagem) {
    struct Deck *menu,*menu2,*aux,*aux2,*aux3,*escolhido;
    int i;

    Menu_Cria(&menu,&aux);
    for(i = 0;i < 3;i++) {
        aux2 = RetiraPrimeiroCard(&(jogador->deck));
        if(aux2 != NULL) {
            Menu_CopiaDado(&aux,aux2->card);
            free(aux2);
        }
    }
    Menu_CelulaFinal(&aux);

    Menu_Cria(&menu2,&aux2);
    aux = menu;
    while(aux->prox != NULL) {
        if(strcmp(aux->card->origem->tipo,"Equipment") == 0 && RecuperaCardLevel(aux->card->origem) <= jogador->level)
            Menu_CopiaDado(&aux2,aux->card);

        aux = aux->prox;
    }
    Menu_CelulaFinal(&aux2);

    if(menu2->prox != NULL && ElaboraPrompt("Use PURPLE RUPEE?",NULL,NULL,NULL,"Trade","Keep",240,510,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        escolhido = MenuCards("PURPLE RUPEE: Play an equipment.",true,menu2,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(escolhido != NULL) {
            WearEquipment(escolhido,buffer,fim,rolagem,id_acao,sbox,jogador,adversario,display,prompt,selecao,roll_bar,pont,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
            RetiraCardPorCopiaSuperMenu(escolhido,&menu);

            aux3 = (struct Deck *)malloc(sizeof(struct Deck));
            aux3->card = *card;
            DestroyCard(aux3,jogador,adversario);
            *card = NULL;
        }
    }

    Menu_Finaliza(menu2);
    ArranjaOrdem(id_acao,menu,buffer,fim,sbox,selecao,roll_bar,fundo_menu,prompt,fundo_carta,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    ColocaListaCardsNaBaseDeck(&(jogador->deck),menu);
}

void RecuperaEquipStats(struct CARD **card,struct Card **buffer,bool *fim,bool *ko,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,int *rolagem,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(*card != NULL) {
        /*::: PONTO DE FUNCAO #2 ::: */
        if((*card)->origem->colecao == BLUE_POTION) blue_potion_acao(card,-1,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if((*card)->origem->colecao == PURPLE_RUPEE) purple_rupee_acao(card,-1,buffer,fim,sbox,selecao,roll_bar,fundo_menu,fundo_carta,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,prompt,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);
        else if((*card)->origem->colecao == MASTER_SWORD) (*card)->var_equip->master_sword_cont = 2;
        else if((*card)->origem->colecao == FAIRY_SLINGSHOT) (*card)->var_equip->fairy_slingshot_cont = 1;
        else if((*card)->origem->colecao == SKULL_MASK) (*card)->var_equip->skull_mask_cont = 1;
        else if((*card)->origem->colecao == BOOMERANG) (*card)->var_equip->boomerang_cont = 1;
        else if((*card)->origem->colecao == GIANTS_KNIFE) (*card)->var_equip->giants_knife_cont = 2;
        else if((*card)->origem->colecao == SILVER_GAUNTLETS) (*card)->var_equip->silver_gauntlets_cont = 1;
        else if((*card)->origem->colecao == GOLDEN_GAUNTLETS) (*card)->var_equip->golden_gauntlets_cont = 1;
        else if((*card)->origem->colecao == HOOKSHOT) hookshot_acao(-1,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if((*card)->origem->colecao == DEKU_SEEDS_BAG) deku_seeds_bag_acao(*card,-1,buffer,fim,ko,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if((*card)->origem->colecao == BOMB_BAG) bomb_bag_acao(*card,-1,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        else if((*card)->origem->colecao == COMPASS) (*card)->var_equip->compass_bool = true;
        else if((*card)->origem->colecao == MASK_OF_TRUTH) (*card)->var_equip->mask_of_truth_bool = true;
        else if((*card)->origem->colecao == HOVER_BOOTS) jogador->prevent_any_damage += 1;
        else if((*card)->origem->colecao == EPONA) jogador->prevent_damage += 1;
        else if((*card)->origem->colecao == CLAIM_CHECK) (*card)->var_equip->claim_check_bool = true;
        else if((*card)->origem->colecao == BIGGER_BOMB_BAG) {
            (*card)->var_equip->bigger_bomb_bag_bool = true;
            (*card)->var_equip->bigger_bomb_bag_overriding_bool = false;
        }
        else if((*card)->origem->colecao == BOMB) {
            (*card)->var_equip->bomb_cont = 1;
            (*card)->var_equip->bomb_dmg = 10;
        }

        AtualizaMesa(false,NULL,-1,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    }
}

#endif // CARD_ACOES_C_INCLUDED
