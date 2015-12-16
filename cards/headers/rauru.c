#ifndef RAURU_H_INCLUDED
#define RAURU_H_INCLUDED

void rauru(struct Card *card) {
        card->bmp = al_load_bitmap("cards/rauru.png");
        card->nome = "Rauru\0";
        card->elemento = "Light\0";
        card->colecao = 38;
        card->RARIDADE = 3;
        card->preco = 1100;
        card->tipo = "Monster\0";
        card->str_concat = "Light - Monster - NPC Hylian\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "NPC QUEST - Get at least one of your monsters destroyed in consequence of the battle last turn. REWARD - Buff your character attacks with +20 damage for each monster of yours destroyed last turn.\0";
        card->monster->level = 80;
        card->monster->attack = 30;
        card->monster->MaxHP = 100;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Raurus Wisdom - If you have more than 3 cards in your hand, discard a card. Draw 2 cards.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void rauru_lvacao(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(jogador->hand->quantidade > 3) DiscardCard(id_acao,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,apontador,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

#endif // RAURU_H_INCLUDED
