#ifndef GOLDEN_GAUNTLETS_H_INCLUDED
#define GOLDEN_GAUNTLETS_H_INCLUDED

void golden_gauntlets(struct Card *card) {
        card->bmp = al_load_bitmap("cards/golden_gauntlets.png");
        card->nome = "Golden Gauntlets\0";
        card->elemento = "Light\0";
        card->colecao = 103;
        card->RARIDADE = 1;
        card->preco = 1970;
        card->tipo = "Equipment\0";
        card->str_concat = "Light - Equipment - Glove\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Get +30 damage with one character action each turn. Block 10 damage inflicted at your character by your opponents character and monsters.\0";
        card->equip->level = 80;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Light Nova - Inflict damage of 20 x number of monsters on the opponents side to a character or monster.\0";
        card->lv_acao->nivel = 100;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void golden_gauntlets_acao(int id_acao,struct Card **buffer,bool *fim,struct CARD *golden_gauntlets,int *dano,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(ElaboraPrompt("Use GOLDEN GAUNTLETS?","Increase damage by 30. %d actions left.",(void *)golden_gauntlets->var_equip->golden_gauntlets_cont,NULL,"Yes","No",240,515,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        *dano = *dano + 30;
        golden_gauntlets->var_equip->golden_gauntlets_cont--;
    }
}

#endif // GOLDEN_GAUNTLETS_H_INCLUDED
