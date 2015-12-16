#ifndef _1_TON_ROCK_LIFTING_H_INCLUDED
#define _1_TON_ROCK_LIFTING_H_INCLUDED

void _1_ton_rock_lifting(struct Card *card) {
        card->bmp = al_load_bitmap("cards/1_ton_rock_lifting.png");
        card->nome = "1 Ton Rock Lifting\0";
        card->elemento = "Water\0";
        card->colecao = 77;
        card->RARIDADE = 7;
        card->preco = 930;
        card->tipo = "Tactic\0";
        card->str_concat = "Water - Tactic - Skill\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Get +20 damage with a character action. If Silver Gauntlets or Golden Gauntlets is equipped, get +10 damage with all character actions and monster attacks this turn instead.\0";
        card->tactic->level = 45;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 60 - Play a monster or a equipment of level 60 or less.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

bool PossuiGauntlets(struct Player *jogador) {
    if(jogador->mesa->equip1 != NULL && (jogador->mesa->equip1->origem->colecao == SILVER_GAUNTLETS || jogador->mesa->equip1->origem->colecao == GOLDEN_GAUNTLETS)) return(true);
    if(jogador->mesa->equip2 != NULL && (jogador->mesa->equip2->origem->colecao == SILVER_GAUNTLETS || jogador->mesa->equip2->origem->colecao == GOLDEN_GAUNTLETS)) return(true);
    if(jogador->mesa->equip3 != NULL && (jogador->mesa->equip3->origem->colecao == SILVER_GAUNTLETS || jogador->mesa->equip3->origem->colecao == GOLDEN_GAUNTLETS)) return(true);
    if(jogador->mesa->equip4 != NULL && (jogador->mesa->equip4->origem->colecao == SILVER_GAUNTLETS || jogador->mesa->equip4->origem->colecao == GOLDEN_GAUNTLETS)) return(true);
    if(jogador->mesa->equip5 != NULL && (jogador->mesa->equip5->origem->colecao == SILVER_GAUNTLETS || jogador->mesa->equip5->origem->colecao == GOLDEN_GAUNTLETS)) return(true);
    if(jogador->mesa->equip6 != NULL && (jogador->mesa->equip6->origem->colecao == SILVER_GAUNTLETS || jogador->mesa->equip6->origem->colecao == GOLDEN_GAUNTLETS)) return(true);
    if(jogador->mesa->equip7 != NULL && (jogador->mesa->equip7->origem->colecao == SILVER_GAUNTLETS || jogador->mesa->equip7->origem->colecao == GOLDEN_GAUNTLETS)) return(true);

    return(false);
}

void _1_ton_rock_lifting_prompt(int *value,int id_acao,struct Card **buffer,bool *fim,int *dano,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(ElaboraPrompt("Use 1 TON ROCK LIFTING effect?","Increase damage by 20. %d actions left.",(void *)*value,NULL,"Yes","No",240,515,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        *dano = *dano + 20;
        (*value)--;
    }
}

#endif // _1_TON_ROCK_LIFTING_H_INCLUDED
