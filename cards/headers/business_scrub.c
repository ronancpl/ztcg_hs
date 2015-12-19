#ifndef BUSINESS_SCRUB_H_INCLUDED
#define BUSINESS_SCRUB_H_INCLUDED

void business_scrub(struct Card *card) {
        card->bmp = al_load_bitmap("cards/business_scrub.png");
        card->nome = "Business Scrub\0";
        card->elemento = "Earth\0";
        card->colecao = 129;
        card->RARIDADE = 3;
        card->preco = 1120;
        card->tipo = "Monster\0";
        card->str_concat = "Earth - Monster - Deku\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Trade - When Business Scrub is destroyed, draw 2 cards. For each tactic drew, your opponent must discard a random card on his/her hand.\0";
        card->monster->level = 38;
        card->monster->attack = 30;
        card->monster->MaxHP = 30;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action / Locate 50 - Play an equipment or a tactic of level 50 or less or a field card.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void business_scrub_acao(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *apontador,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *aux;
    int tactics = 0,i;

    for(i = 0;i < 2;i++) {
        if(DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
            aux = jogador->hand->inicio;
            while(aux->prox->prox != NULL) aux = aux->prox;
            if(aux->card->origem->tactic != NULL) {
                //revela que eh uma tatica pro adversario ver
                RevelaCarta("TACTIC DRAWN!",aux->card,-1,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer,rolagem);

                tactics++;
            }
        }
    }

    for(i = 0;i < tactics;i++)
        DiscardRandomHandCard(id_acao,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,adversario,jogador,display,fundo,font,font2,color,apontador,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

#endif // BUSINESS_SCRUB_H_INCLUDED
