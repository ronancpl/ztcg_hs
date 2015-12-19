#ifndef GIANTS_KNIFE_H_INCLUDED
#define GIANTS_KNIFE_H_INCLUDED

void giants_knife(struct Card *card) {
        card->bmp = al_load_bitmap("cards/giants_knife.png");
        card->nome = "Giants Knife\0";
        card->elemento = "Dark\0";
        card->colecao = 151;
        card->RARIDADE = 7;
        card->preco = 650;
        card->tipo = "Equipment\0";
        card->str_concat = "Dark - Equipment - Weapon\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Get +20 damage with two character actions each turn. Giants Knife will be destroyed after the 4th use of its buff.\0";
        card->equip->level = 50;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip 60 - Play an equipment of level 60 or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void giants_knife_acao(bool *usa_weapon,int id_acao,struct Card **buffer,bool *fim,struct CARD *equip,int *dano,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(ElaboraPrompt("Use GIANTS KNIFE?","Increase damage by 20. %d actions left.",(void *)equip->var_equip->giants_knife_cont,NULL,"Yes","No",240,515,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        *dano = *dano + 20;
        equip->var_equip->giants_knife_cont--;
        equip->var_equip->giants_knife_uses++;
        *usa_weapon = true;

        if(equip->var_equip->giants_knife_uses == 4) ForceDestroyCard(&equip,jogador,adversario);
    }
}

#endif // GIANTS_KNIFE_H_INCLUDED
