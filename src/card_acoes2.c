#ifndef CARD_ACOES2_C_INCLUDED
#define CARD_ACOES2_C_INCLUDED

void cursed_villager_acao(bool *fim,struct Player *jogador,struct Player *adversario) {
    adversario->global_silence = true;

    if(adversario->mesa->monstro1 != NULL && adversario->mesa->monstro1->turn_silenced == 0) SilenciaAuras(fim,adversario->mesa->monstro1,1,jogador,adversario);
    if(adversario->mesa->monstro2 != NULL && adversario->mesa->monstro2->turn_silenced == 0) SilenciaAuras(fim,adversario->mesa->monstro2,1,jogador,adversario);
    if(adversario->mesa->monstro3 != NULL && adversario->mesa->monstro3->turn_silenced == 0) SilenciaAuras(fim,adversario->mesa->monstro3,1,jogador,adversario);
    if(adversario->mesa->monstro4 != NULL && adversario->mesa->monstro4->turn_silenced == 0) SilenciaAuras(fim,adversario->mesa->monstro4,1,jogador,adversario);
    if(adversario->mesa->monstro5 != NULL && adversario->mesa->monstro5->turn_silenced == 0) SilenciaAuras(fim,adversario->mesa->monstro5,1,jogador,adversario);
    if(adversario->mesa->monstro6 != NULL && adversario->mesa->monstro6->turn_silenced == 0) SilenciaAuras(fim,adversario->mesa->monstro6,1,jogador,adversario);
    if(adversario->mesa->monstro7 != NULL && adversario->mesa->monstro7->turn_silenced == 0) SilenciaAuras(fim,adversario->mesa->monstro7,1,jogador,adversario);
}

void efeito_zs_monstro(struct CARD *card) {
    if(card != NULL && !strcmp(card->origem->elemento,"Water")) {
        printf("Ativando zoras sapphire em '%s'\n",card->origem->nome);
        card->MaxHP = card->MaxHP + 10;
        card->HP = card->HP + 10;
    }
}

void zoras_sapphire_acao(struct Player *jogador,struct Player *adversario) {
    efeito_zs_monstro(jogador->mesa->monstro1);
    efeito_zs_monstro(jogador->mesa->monstro2);
    efeito_zs_monstro(jogador->mesa->monstro3);
    efeito_zs_monstro(jogador->mesa->monstro4);
    efeito_zs_monstro(jogador->mesa->monstro5);
    efeito_zs_monstro(jogador->mesa->monstro6);
    efeito_zs_monstro(jogador->mesa->monstro7);

    efeito_zs_monstro(adversario->mesa->monstro1);
    efeito_zs_monstro(adversario->mesa->monstro2);
    efeito_zs_monstro(adversario->mesa->monstro3);
    efeito_zs_monstro(adversario->mesa->monstro4);
    efeito_zs_monstro(adversario->mesa->monstro5);
    efeito_zs_monstro(adversario->mesa->monstro6);
    efeito_zs_monstro(adversario->mesa->monstro7);
}

void desfaz_efeito_zs_monstro(struct CARD *card) {
    if(card != NULL && !strcmp(card->origem->elemento,"Water")) {
        printf("Tirando zoras sapphire em '%s'\n",card->origem->nome);
        card->MaxHP = card->MaxHP - 10;
        card->HP = card->HP - 10;
    }
}

void desfaz_zoras_sapphire_acao(struct Player *jogador,struct Player *adversario) {
    desfaz_efeito_zs_monstro(jogador->mesa->monstro1);
    desfaz_efeito_zs_monstro(jogador->mesa->monstro2);
    desfaz_efeito_zs_monstro(jogador->mesa->monstro3);
    desfaz_efeito_zs_monstro(jogador->mesa->monstro4);
    desfaz_efeito_zs_monstro(jogador->mesa->monstro5);
    desfaz_efeito_zs_monstro(jogador->mesa->monstro6);
    desfaz_efeito_zs_monstro(jogador->mesa->monstro7);

    desfaz_efeito_zs_monstro(adversario->mesa->monstro1);
    desfaz_efeito_zs_monstro(adversario->mesa->monstro2);
    desfaz_efeito_zs_monstro(adversario->mesa->monstro3);
    desfaz_efeito_zs_monstro(adversario->mesa->monstro4);
    desfaz_efeito_zs_monstro(adversario->mesa->monstro5);
    desfaz_efeito_zs_monstro(adversario->mesa->monstro6);
    desfaz_efeito_zs_monstro(adversario->mesa->monstro7);
}

void efeito_gr_monstro(struct CARD *card) {
    if(card != NULL && !strcmp(card->origem->elemento,"Fire")) {
        printf("Ativando goron ruby em '%s'\n",card->origem->nome);
        card->MaxHP = card->MaxHP + 10;
        card->HP = card->HP + 10;
    }
}

void goron_ruby_acao(struct Player *jogador,struct Player *adversario) {
    efeito_gr_monstro(jogador->mesa->monstro1);
    efeito_gr_monstro(jogador->mesa->monstro2);
    efeito_gr_monstro(jogador->mesa->monstro3);
    efeito_gr_monstro(jogador->mesa->monstro4);
    efeito_gr_monstro(jogador->mesa->monstro5);
    efeito_gr_monstro(jogador->mesa->monstro6);
    efeito_gr_monstro(jogador->mesa->monstro7);

    efeito_gr_monstro(adversario->mesa->monstro1);
    efeito_gr_monstro(adversario->mesa->monstro2);
    efeito_gr_monstro(adversario->mesa->monstro3);
    efeito_gr_monstro(adversario->mesa->monstro4);
    efeito_gr_monstro(adversario->mesa->monstro5);
    efeito_gr_monstro(adversario->mesa->monstro6);
    efeito_gr_monstro(adversario->mesa->monstro7);
}

void desfaz_efeito_gr_monstro(struct CARD *card) {
    if(card != NULL && !strcmp(card->origem->elemento,"Fire")) {
        printf("Tirando goron ruby em '%s'\n",card->origem->nome);
        //card->attack = card->attack - 10;
        card->MaxHP = card->MaxHP - 10;
        card->HP = card->HP - 10;
    }
}

void desfaz_goron_ruby_acao(struct Player *jogador,struct Player *adversario) {
    desfaz_efeito_gr_monstro(jogador->mesa->monstro1);
    desfaz_efeito_gr_monstro(jogador->mesa->monstro2);
    desfaz_efeito_gr_monstro(jogador->mesa->monstro3);
    desfaz_efeito_gr_monstro(jogador->mesa->monstro4);
    desfaz_efeito_gr_monstro(jogador->mesa->monstro5);
    desfaz_efeito_gr_monstro(jogador->mesa->monstro6);
    desfaz_efeito_gr_monstro(jogador->mesa->monstro7);

    desfaz_efeito_gr_monstro(adversario->mesa->monstro1);
    desfaz_efeito_gr_monstro(adversario->mesa->monstro2);
    desfaz_efeito_gr_monstro(adversario->mesa->monstro3);
    desfaz_efeito_gr_monstro(adversario->mesa->monstro4);
    desfaz_efeito_gr_monstro(adversario->mesa->monstro5);
    desfaz_efeito_gr_monstro(adversario->mesa->monstro6);
    desfaz_efeito_gr_monstro(adversario->mesa->monstro7);
}

bool GerudoPresente(struct Player *jogador,int *instancias) {
    *instancias = 0;

    if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->origem->colecao == GERUDO_GUARD && jogador->mesa->monstro1->turn_silenced == 0) (*instancias)++;
    if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->origem->colecao == GERUDO_GUARD && jogador->mesa->monstro2->turn_silenced == 0) (*instancias)++;
    if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->origem->colecao == GERUDO_GUARD && jogador->mesa->monstro3->turn_silenced == 0) (*instancias)++;
    if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->origem->colecao == GERUDO_GUARD && jogador->mesa->monstro4->turn_silenced == 0) (*instancias)++;
    if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->origem->colecao == GERUDO_GUARD && jogador->mesa->monstro5->turn_silenced == 0) (*instancias)++;
    if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->origem->colecao == GERUDO_GUARD && jogador->mesa->monstro6->turn_silenced == 0) (*instancias)++;
    if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->origem->colecao == GERUDO_GUARD && jogador->mesa->monstro7->turn_silenced == 0) (*instancias)++;

    if(*instancias == 0) return(false);
    else return(true);
}

void InstantRapidAction() {
    //Táticas que tomam posição automaticamente



}

void adult_wallet_acao(int id_acao,struct Card **buffer,bool *fim,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_BITMAP *prompt,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer,int *rolagem) {
    struct Deck *alvo,*menu,*aux,*aux2,*aux3 = NULL,*aux4,*escolhido = NULL;
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

    menu = (struct Deck *)malloc(sizeof(struct Deck));
    menu->prox = NULL;

    aux = alvo;
    aux2 = menu;
    while(aux->prox != NULL) {
        if(strcmp(aux->card->origem->tipo,"Equipment") == 0) {
            aux2->card = aux->card;
            aux2->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux2 = aux2->prox;
            aux2->prox = NULL;
        }
        aux = aux->prox;
    }

    escolhido = MenuCards("ADULT WALLET: Select and draw one of these cards.",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    printf("ACAO TOMADA: ");
    if(escolhido != NULL) {  //O card, se escolhido, eh retirado do conjunto e levado para a mão.
        aux = alvo;
        aux2 = NULL;

        while(escolhido->card != aux->card) {
            aux2 = aux;
            aux = aux->prox;
        }
        if(aux2 == NULL) alvo = aux->prox;
        else aux2->prox = aux->prox;

        aux3 = jogador->hand->inicio;
        aux4 = NULL;
        while(aux3->prox != NULL) {
            aux4 = aux3;
            aux3 = aux3->prox;
        }
        if(aux4 == NULL) jogador->hand->inicio = aux;
        else aux4->prox = aux;

        aux->prox = aux3;
        jogador->hand->quantidade++;
    }

    printf("1 ");
    aux2 = menu;
    while(aux2->prox != NULL) {
        aux = aux2;
        aux2 = aux2->prox;
        free(aux);
    }
    free(aux2);

    printf("2 ");
    ArranjaOrdem(id_acao,alvo,buffer,fim,sbox,selecao,roll_bar,fundo_menu,prompt,fundo_carta,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    printf("3 ");
    aux = jogador->deck->inicio;
    aux2 = NULL;
    while(aux->prox != NULL) {
        aux2 = aux;
        aux = aux->prox;
    }

    free(aux);   //Libera a cabeca da lista (nao contem dado relevante).
    if(aux2 != NULL) aux2->prox = alvo;
    else jogador->deck->inicio = alvo;

    jogador->deck->quantidade += QuantidadeListaCards(alvo);
    printf("4 ");

    AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);
    printf("OK\n");
}

void bazaar_seller_acao(int id_acao,struct Card **buffer,bool *fim,struct CARD *equip,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *menu,*aux,*aux2,*retorna_card = NULL;
    bool valor = true;

    if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1 != equip && jogador->mesa->equip1->origem->equip->level >= equip->origem->equip->level) valor = false;
    else if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2 != equip && jogador->mesa->equip2->origem->equip->level >= equip->origem->equip->level) valor = false;
    else if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3 != equip && jogador->mesa->equip3->origem->equip->level >= equip->origem->equip->level) valor = false;
    else if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4 != equip && jogador->mesa->equip4->origem->equip->level >= equip->origem->equip->level) valor = false;
    else if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5 != equip && jogador->mesa->equip5->origem->equip->level >= equip->origem->equip->level) valor = false;
    else if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6 != equip && jogador->mesa->equip6->origem->equip->level >= equip->origem->equip->level) valor = false;
    else if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7 != equip && jogador->mesa->equip7->origem->equip->level >= equip->origem->equip->level) valor = false;

    if(valor) {
        menu = (struct Deck *)malloc(sizeof(struct Deck));
        menu->prox = NULL;

        aux = jogador->deck->inicio;
        aux2 = NULL;
        while(aux->prox != NULL) {
            if(strcmp(aux->card->origem->tipo,"Equipment") == 0 && aux->card->origem->equip->level < equip->origem->equip->level) {
                if(aux2 != NULL) {
                    aux2->prox = aux->prox;
                    aux->prox = menu;
                    menu = aux;
                    aux = aux2;
                }
                else {
                    jogador->deck->inicio = aux->prox;
                    aux->prox = menu;
                    menu = aux;
                    aux = jogador->deck->inicio;

                    jogador->deck->quantidade--;
                    continue;
                }

                jogador->deck->quantidade--;
            }

            aux2 = aux;
            aux = aux->prox;
        }

        retorna_card = MenuCards("BAZAAR SELLER: Draw one of these cards.",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        printf("BAZARSELLER FUNCT ");
        if(retorna_card != NULL) {
            RetiraCardPorCopiaMenu(retorna_card,&menu);
            ColocaNovoCardNoDeck(&(jogador->deck),retorna_card);
            DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        }
        printf("OK\n");

        ColocaListaCardsNoTopoDeck(&(jogador->deck),menu);
        EmbaralhaDeck(jogador->deck->inicio,jogador->deck->quantidade);
    }
    else printf("EQUIP DE NIVEL MAIOR DETECTADO!\n");
}

void goron_tunic_acao2(struct Player *jogador) {
    *(jogador->MaxHP) = *(jogador->MaxHP) + 40;
    *(jogador->HP) = *(jogador->HP) + 90;   //+40 vem aumentando o maxHP.
    if(*(jogador->HP) > *(jogador->MaxHP)) *(jogador->HP) = *(jogador->MaxHP);
}

void desfaz_goron_tunic_acao2(struct Player *jogador) {
    *(jogador->MaxHP) = *(jogador->MaxHP) - 40;
    *(jogador->HP) = *(jogador->HP) - 40;
    if(*(jogador->HP) <= 0) *(jogador->HP) = 10;
}

void mirror_shield_absorve_dano(struct CARD *equip,int dmg) {
    equip->var_equip->mirror_shield_cont++;
    equip->var_equip->mirror_shield_dmg += RetornaAproximado(dmg / 3);
}

int tidal_strike_multiplier(struct Player *jogador) {
    int cont = 0, bonus;

    if(jogador->mesa->monstro1 != NULL && !strcmp(jogador->mesa->monstro1->origem->elemento,"Water")) cont++;
    if(jogador->mesa->monstro2 != NULL && !strcmp(jogador->mesa->monstro2->origem->elemento,"Water")) cont++;
    if(jogador->mesa->monstro3 != NULL && !strcmp(jogador->mesa->monstro3->origem->elemento,"Water")) cont++;
    if(jogador->mesa->monstro4 != NULL && !strcmp(jogador->mesa->monstro4->origem->elemento,"Water")) cont++;
    if(jogador->mesa->monstro5 != NULL && !strcmp(jogador->mesa->monstro5->origem->elemento,"Water")) cont++;
    if(jogador->mesa->monstro6 != NULL && !strcmp(jogador->mesa->monstro6->origem->elemento,"Water")) cont++;
    if(jogador->mesa->monstro7 != NULL && !strcmp(jogador->mesa->monstro7->origem->elemento,"Water")) cont++;

    bonus = jogador->water_ic / cont;
    if((jogador->water_ic % cont) > 0) bonus += 1;

    return(bonus);
}

#endif // CARD_ACOES2_C_INCLUDED
