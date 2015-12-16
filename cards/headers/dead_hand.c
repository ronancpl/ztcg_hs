#ifndef DEAD_HAND_H_INCLUDED
#define DEAD_HAND_H_INCLUDED

void dead_hand(struct Card *card) {
        card->bmp = al_load_bitmap("cards/dead_hand.png");
        card->nome = "Dead Hand\0";
        card->elemento = "Earth\0";
        card->colecao = 34;
        card->RARIDADE = 1;
        card->preco = 1590;
        card->tipo = "Jr. Boss\0";
        card->str_concat = "Earth - Jr. Boss - Undead\0";

        card->jrboss = (struct jrboss *)malloc(sizeof(struct jrboss));
        card->jrboss->level = 73;
        card->jrboss->attack = 40;
        card->jrboss->MaxHP = 100;

        card->jrboss->acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->acao = "Grab - Make up to 2 monsters unable to attack while Dead Hand is on the field.\0";
        card->jrboss->acao->atrib = 0;
        card->jrboss->acao->nivel = 0;
        card->jrboss->acao->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->prox->acao = "Ground Expert - All of your other EARTH monsters gets +10 attack and +20 HP while Dead Hand remains on field.\0";
        card->jrboss->acao->prox->atrib = 0;
        card->jrboss->acao->prox->nivel = 0;
        card->jrboss->acao->prox->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->prox->prox->prox = NULL;

        card->tactic = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->boss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Devastating Strike - Do 30 damage to a character or monster.\0";
        card->lv_acao->nivel = 80;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void dh_card(struct CARD *card) {
    if(card != NULL && strcmp(card->origem->elemento,"Earth") == 0 && card->origem->colecao != DEAD_HAND && card->turn_silenced == 0) {
        card->MaxHP = card->MaxHP + 20;
        card->HP = card->HP + 20;
    }
}

void dead_hand_effect(struct Player *jogador) {
    dh_card(jogador->mesa->monstro1);
    dh_card(jogador->mesa->monstro2);
    dh_card(jogador->mesa->monstro3);
    dh_card(jogador->mesa->monstro4);
    dh_card(jogador->mesa->monstro5);
    dh_card(jogador->mesa->monstro6);
    dh_card(jogador->mesa->monstro7);
}

void dead_hand_acao(struct CARD *card,struct Player *player) { //somente ao colocar card em campo.
    if(strcmp(card->origem->elemento,"Earth") == 0) {
        if(player->mesa->monstro1 != NULL && player->mesa->monstro1 != card && player->mesa->monstro1->origem->colecao == DEAD_HAND && player->mesa->monstro1->turn_silenced == 0) {
            printf("BUFF dead hand\n");

            card->MaxHP = card->MaxHP + 20;
            card->HP = card->HP + 20;
        }
        if(player->mesa->monstro2 != NULL && player->mesa->monstro2 != card && player->mesa->monstro2->origem->colecao == DEAD_HAND && player->mesa->monstro2->turn_silenced == 0) {
            printf("BUFF dead hand\n");

            card->MaxHP = card->MaxHP + 20;
            card->HP = card->HP + 20;
        }
        if(player->mesa->monstro3 != NULL && player->mesa->monstro3 != card && player->mesa->monstro3->origem->colecao == DEAD_HAND && player->mesa->monstro3->turn_silenced == 0) {
            printf("BUFF dead hand\n");

            card->MaxHP = card->MaxHP + 20;
            card->HP = card->HP + 20;
        }
        if(player->mesa->monstro4 != NULL && player->mesa->monstro4 != card && player->mesa->monstro4->origem->colecao == DEAD_HAND && player->mesa->monstro4->turn_silenced == 0) {
            printf("BUFF dead hand\n");

            card->MaxHP = card->MaxHP + 20;
            card->HP = card->HP + 20;
        }
        if(player->mesa->monstro5 != NULL && player->mesa->monstro5 != card && player->mesa->monstro5->origem->colecao == DEAD_HAND && player->mesa->monstro5->turn_silenced == 0) {
            printf("BUFF dead hand\n");

            card->MaxHP = card->MaxHP + 20;
            card->HP = card->HP + 20;
        }
        if(player->mesa->monstro6 != NULL && player->mesa->monstro6 != card && player->mesa->monstro6->origem->colecao == DEAD_HAND && player->mesa->monstro6->turn_silenced == 0) {
            printf("BUFF dead hand\n");

            card->MaxHP = card->MaxHP + 20;
            card->HP = card->HP + 20;
        }
        if(player->mesa->monstro7 != NULL && player->mesa->monstro7 != card && player->mesa->monstro7->origem->colecao == DEAD_HAND && player->mesa->monstro7->turn_silenced == 0) {
            printf("BUFF dead hand\n");

            card->MaxHP = card->MaxHP + 20;
            card->HP = card->HP + 20;
        }
    }
}

bool GrabPossivel(struct Player *jogador) {
    if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->var_monster->dead_hand_bool == false) return(true);
    if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->var_monster->dead_hand_bool == false) return(true);
    if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->var_monster->dead_hand_bool == false) return(true);
    if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->var_monster->dead_hand_bool == false) return(true);
    if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->var_monster->dead_hand_bool == false) return(true);
    if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->var_monster->dead_hand_bool == false) return(true);
    if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->var_monster->dead_hand_bool == false) return(true);

    return(false);
}

void dead_hand_acao2(int id_acao,struct Card **buffer,struct CARD *dead_hand,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *menu,*aux,*aux2;
    struct Deck *retorna_card;
    int i = dead_hand->var_monster->dead_hand_cont;

    while(i > 0) {
        if(!GrabPossivel(adversario)) break;

        menu = (struct Deck *)malloc(sizeof(struct Deck));
        menu->prox = NULL;
        aux = menu;

        if(adversario->mesa->monstro1 != NULL && !adversario->mesa->monstro1->var_monster->dead_hand_bool) {
            aux->card = adversario->mesa->monstro1;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
            aux->prox = NULL;
        }

        if(adversario->mesa->monstro2 != NULL && !adversario->mesa->monstro2->var_monster->dead_hand_bool) {
            aux->card = adversario->mesa->monstro2;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
            aux->prox = NULL;
        }

        if(adversario->mesa->monstro3 != NULL && !adversario->mesa->monstro3->var_monster->dead_hand_bool) {
            aux->card = adversario->mesa->monstro3;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
            aux->prox = NULL;
        }

        if(adversario->mesa->monstro4 != NULL && !adversario->mesa->monstro4->var_monster->dead_hand_bool) {
            aux->card = adversario->mesa->monstro4;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
            aux->prox = NULL;
        }

        if(adversario->mesa->monstro5 != NULL && !adversario->mesa->monstro5->var_monster->dead_hand_bool) {
            aux->card = adversario->mesa->monstro5;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
            aux->prox = NULL;
        }

        if(adversario->mesa->monstro6 != NULL && !adversario->mesa->monstro6->var_monster->dead_hand_bool) {
            aux->card = adversario->mesa->monstro6;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
            aux->prox = NULL;
        }

        if(adversario->mesa->monstro7 != NULL && !adversario->mesa->monstro7->var_monster->dead_hand_bool) {
            aux->card = adversario->mesa->monstro7;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
            aux->prox = NULL;
        }

        retorna_card = MenuCards("GRAB - Select a monster to stun.",true,menu,fim_de_jogo,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(retorna_card != NULL) {
            if(adversario->mesa->monstro1 == retorna_card->card) {
                adversario->mesa->monstro1->var_monster->dead_hand_bool = true;
                dead_hand->var_monster->dead_hand_cont--;
            }
            else if(adversario->mesa->monstro2 == retorna_card->card) {
                adversario->mesa->monstro2->var_monster->dead_hand_bool = true;
                dead_hand->var_monster->dead_hand_cont--;
            }
            else if(adversario->mesa->monstro3 == retorna_card->card) {
                adversario->mesa->monstro3->var_monster->dead_hand_bool = true;
                dead_hand->var_monster->dead_hand_cont--;
            }
            else if(adversario->mesa->monstro4 == retorna_card->card) {
                adversario->mesa->monstro4->var_monster->dead_hand_bool = true;
                dead_hand->var_monster->dead_hand_cont--;
            }
            else if(adversario->mesa->monstro5 == retorna_card->card) {
                adversario->mesa->monstro5->var_monster->dead_hand_bool = true;
                dead_hand->var_monster->dead_hand_cont--;
            }
            else if(adversario->mesa->monstro6 == retorna_card->card) {
                adversario->mesa->monstro6->var_monster->dead_hand_bool = true;
                dead_hand->var_monster->dead_hand_cont--;
            }
            else {
                adversario->mesa->monstro7->var_monster->dead_hand_bool = true;
                dead_hand->var_monster->dead_hand_cont--;
            }
        }

        i--;
        AtualizaMesa(true,NULL,id_acao,-1,0,buffer,fim_de_jogo,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,fundo,pont,jogador,adversario,display,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem,NULL,-1,-1,0,-1,NULL,NULL);

        aux = menu;
        while(aux->prox != NULL) {
            aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
        free(aux);
    }
}

void desfaz_dh_card(struct CARD *card) {
    if(card != NULL && strcmp(card->origem->elemento,"Earth") == 0 && card->origem->colecao != DEAD_HAND) {
        card->MaxHP = card->MaxHP - 20;
        card->HP = card->HP - 20;
        //card->attack = card->attack - 10;
    }
}

void desfaz_dead_hand_effect(struct Player *jogador) {
    desfaz_dh_card(jogador->mesa->monstro1);
    desfaz_dh_card(jogador->mesa->monstro2);
    desfaz_dh_card(jogador->mesa->monstro3);
    desfaz_dh_card(jogador->mesa->monstro4);
    desfaz_dh_card(jogador->mesa->monstro5);
    desfaz_dh_card(jogador->mesa->monstro6);
    desfaz_dh_card(jogador->mesa->monstro7);
}

#endif // DEAD_HAND_H_INCLUDED
