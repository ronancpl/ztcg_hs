#ifndef GOSSIP_STONE_H_INCLUDED
#define GOSSIP_STONE_H_INCLUDED

void gossip_stone(struct Card *card) {
        card->bmp = al_load_bitmap("cards/gossip_stone.png");
        card->nome = "Gossip Stone\0";
        card->elemento = "Wind\0";
        card->colecao = 98;
        card->RARIDADE = 7;
        card->preco = 630;
        card->tipo = "Equipment\0";
        card->str_concat = "Wind - Equipment - Stone\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Whenever you play a tactic look at the top 2 cards of your deck. Set one card at the top and the other at the bottom of your deck. If there is a Mask of Truth equipped, draw one card and send the other at either top or bottom of your deck instead, effect limited up to once per turn for each Mask of Truth instances of yours.\0";
        card->equip->level = 37;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Airwave - Do 20 damage to a monster.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void gossip_stone_acao(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *lista,*aux,*aux2,*escolhido = NULL;
    bool toggle = false;

    lista = RetiraPrimeiroCard(&(jogador->deck));
    if(lista == NULL) return;

    aux = lista;
    aux2 = RetiraPrimeiroCard(&(jogador->deck));
    if(aux2 != NULL) {
        aux->prox = aux2;
        aux = aux->prox;
    }

    aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
    aux->prox->prox = NULL;

    if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1->origem->colecao == MASK_OF_TRUTH && jogador->mesa->equip1->var_equip->mask_of_truth_bool == true) {
        toggle = true;
        jogador->mesa->equip1->var_equip->mask_of_truth_bool = false;
    }
    else if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2->origem->colecao == MASK_OF_TRUTH && jogador->mesa->equip2->var_equip->mask_of_truth_bool == true) {
        toggle = true;
        jogador->mesa->equip2->var_equip->mask_of_truth_bool = false;
    }
    else if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3->origem->colecao == MASK_OF_TRUTH && jogador->mesa->equip3->var_equip->mask_of_truth_bool == true) {
        toggle = true;
        jogador->mesa->equip3->var_equip->mask_of_truth_bool = false;
    }
    else if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4->origem->colecao == MASK_OF_TRUTH && jogador->mesa->equip4->var_equip->mask_of_truth_bool == true) {
        toggle = true;
        jogador->mesa->equip4->var_equip->mask_of_truth_bool = false;
    }
    else if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5->origem->colecao == MASK_OF_TRUTH && jogador->mesa->equip5->var_equip->mask_of_truth_bool == true) {
        toggle = true;
        jogador->mesa->equip5->var_equip->mask_of_truth_bool = false;
    }
    else if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6->origem->colecao == MASK_OF_TRUTH && jogador->mesa->equip6->var_equip->mask_of_truth_bool == true) {
        toggle = true;
        jogador->mesa->equip6->var_equip->mask_of_truth_bool = false;
    }
    else if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7->origem->colecao == MASK_OF_TRUTH && jogador->mesa->equip7->var_equip->mask_of_truth_bool == true) {
        toggle = true;
        jogador->mesa->equip7->var_equip->mask_of_truth_bool = false;
    }


    if(toggle == false) {
        while(escolhido == NULL) escolhido = MenuCards("Select a card to head to the top of the deck. The other one will be headed to the bottom.",true,lista,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        RetiraCardPorCopiaMenu(escolhido,&lista);

        ColocaNovoCardNoDeck(&(jogador->deck),escolhido);
        ColocaListaCardsNaBaseDeck(&(jogador->deck),lista);
    }
    else {
        while(escolhido == NULL) escolhido = MenuCards("Select a card to DRAW. The other one will be headed at either top or bottom of the deck.",true,lista,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        RetiraCardPorCopiaMenu(escolhido,&lista);
        ColocaNovoCardNoDeck(&(jogador->hand),escolhido);

        if(lista->prox != NULL && ElaboraPrompt("Head the other card to which side of the deck?","Card: %s",lista->card->origem->nome,NULL,"Top","Bottom",242,505,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer))
            ColocaListaCardsNoTopoDeck(&(jogador->deck),lista);
        else
            ColocaListaCardsNaBaseDeck(&(jogador->deck),lista);
    }
}

#endif // GOSSIP_STONE_H_INCLUDED
