#ifndef HORSE_RIDING_H_INCLUDED
#define HORSE_RIDING_H_INCLUDED

void horse_riding(struct Card *card) {
        card->bmp = al_load_bitmap("cards/horse_riding.png");
        card->nome = "Horse Riding\0";
        card->elemento = "Earth\0";
        card->colecao = 76;
        card->RARIDADE = 3;
        card->preco = 1220;
        card->tipo = "Tactic\0";
        card->str_concat = "Earth - Tactic - Skill\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Add +20 damage at two character actions the turn this card is activated. During two turns, the opponents monsters can not inflict damage at your character.\0";
        card->tactic->level = 50;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip X - Play an equipment of your level or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void horse_riding_prompt(int id_acao,struct Card **buffer,bool *fim,int *dano,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(ElaboraPrompt("Use HORSE RIDING effect?","%d actions left.",(void *)jogador->var_tactic->horse_riding_cont,NULL,"Yes","No",240,515,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        *dano = *dano + 20;
        jogador->var_tactic->horse_riding_cont--;
    }
}

void horse_riding_acao(struct Player *jogador) {
    jogador->var_tactic->horse_riding_cont += 2;
    jogador->var_tactic->horse_riding_turn_cont += 2;
}

#endif // HORSE_RIDING_H_INCLUDED
