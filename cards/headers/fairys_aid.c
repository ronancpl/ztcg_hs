#ifndef FAIRYS_AID_H_INCLUDED
#define FAIRYS_AID_H_INCLUDED

void fairys_aid(struct Card *card) {
        card->bmp = al_load_bitmap("cards/fairys_aid.png");
        card->nome = "Fairys Aid\0";
        card->elemento = "Wind\0";
        card->colecao = 63;
        card->RARIDADE = 7;
        card->preco = 520;
        card->tipo = "Tactic\0";
        card->str_concat = "Wind - Tactic - Recovery\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Heal 80 HP, and boost your character attacks with +10 damage the turn this card is activated.\0";
        card->tactic->level = 60;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Rapid Action 50 - Play a monster or a tactic of level 50 or less.\0";
        card->lv_acao->nivel = 40;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void fairys_aid_acao(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    RefreshHP(id_acao,buffer,jogador->mesa->character,80,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    jogador->var_tactic->fairys_aid_cont += 1;
}

#endif // FAIRYS_AID_H_INCLUDED
