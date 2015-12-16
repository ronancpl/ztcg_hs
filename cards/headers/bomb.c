#ifndef BOMB_H_INCLUDED
#define BOMB_H_INCLUDED

void bomb(struct Card *card) {
        card->bmp = al_load_bitmap("cards/bomb.png");
        card->nome = "Bomb\0";
        card->elemento = "Fire\0";
        card->colecao = 139;
        card->RARIDADE = 7;
        card->preco = 520;
        card->tipo = "Equipment\0";
        card->str_concat = "Fire - Equipment - Weapon\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Do +10 damage with one character action each turn.\0";
        card->equip->level = 20;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Rapid Action 40 - Play a tactic of level 40 or less.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 1;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void bomb_acao(bool *usa_weapon,int id_acao,struct Card **buffer,bool *fim,struct CARD *bomb,int *dano,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(ElaboraPrompt("Use BOMB?","Increase damage by %d. %d actions left.",(void *)bomb->var_equip->bomb_dmg,(void *)bomb->var_equip->bomb_cont,"Yes","No",240,515,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        *dano = *dano + bomb->var_equip->bomb_dmg;
        bomb->var_equip->bomb_cont--;
        *usa_weapon = true;
    }
}

#endif // BOMB_H_INCLUDED
