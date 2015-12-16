#ifndef MASTER_SWORD_H_INCLUDED
#define MASTER_SWORD_H_INCLUDED

void master_sword(struct Card *card) {
        card->bmp = al_load_bitmap("cards/master_sword.png");
        card->nome = "Master Sword\0";
        card->elemento = "Light\0";
        card->colecao = 17;
        card->RARIDADE = 7;
        card->preco = 540;
        card->tipo = "Equipment\0";
        card->str_concat = "Light - Equipment - Weapon\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Get +10 damage with two character actions each turn. For each LIGHT monster played, recover 20 HP.\0";
        card->equip->level = 30;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Rapid Action X - Play a tactic of your level or less.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void master_sword_acao(bool *usa_weapon,int id_acao,struct Card **buffer,bool *fim,struct CARD *master_sword,int *dano,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(ElaboraPrompt("Use MASTER SWORD?","Increase damage by 10. %d actions left.",(void *)master_sword->var_equip->master_sword_cont,NULL,"Yes","No",240,515,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        *dano = *dano + 10;
        master_sword->var_equip->master_sword_cont--;
        *usa_weapon = true;
    }
}

#endif // MASTER_SWORD_H_INCLUDED
