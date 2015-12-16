#ifndef SKULL_MASK_H_INCLUDED
#define SKULL_MASK_H_INCLUDED

void skull_mask(struct Card *card) {
        card->bmp = al_load_bitmap("cards/skull_mask.png");
        card->nome = "Skull Mask\0";
        card->elemento = "Dark\0";
        card->colecao = 108;
        card->RARIDADE = 7;
        card->preco = 490;
        card->tipo = "Equipment\0";
        card->str_concat = "Dark - Equipment - Mask\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Get +10 attack with one character action. Starting your turn, you may give up 30 HP. If you do so, treat a monster on your hand like it is 10 levels less than the actual for summoning. This effect cant be stacked onto the same target by other level modifiers.\0";
        card->equip->level = 35;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 30 - Play a monster or an equipment of level 30 or less.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void skull_mask_acao(int id_acao,struct Card **buffer,bool *fim,struct CARD *skull_mask,int *dano,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(ElaboraPrompt("Use SKULL MASK?","Increase damage by 10. %d actions left.",(void *)skull_mask->var_equip->skull_mask_cont,NULL,"Yes","No",240,515,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        *dano = *dano + 10;
        skull_mask->var_equip->skull_mask_cont--;
    }
}

#endif // SKULL_MASK_H_INCLUDED
