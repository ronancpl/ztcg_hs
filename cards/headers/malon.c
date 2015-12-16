#ifndef MALON_H_INCLUDED
#define MALON_H_INCLUDED

void malon(struct Card *card) {
        card->bmp = al_load_bitmap("cards/malon.png");
        card->nome = "Malon\0";
        card->elemento = "Earth\0";
        card->colecao = 140;
        card->RARIDADE = 7;
        card->preco = 1120;
        card->tipo = "Monster\0";
        card->str_concat = "Earth - Monster - NPC Hylian\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "NPC Quest - Dont attack with at least one monster on your turn. Reward - For each non-attacking (monster effects doesnt count) monster you have at the end of your turn, heal +10 HP.\0";
        card->monster->level = 49;
        card->monster->attack = 30;
        card->monster->MaxHP = 40;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Ranch Therapy - Restore all HP of a Jr. Boss or Boss you have deployed. For each monster on the field, your characters HP is recovered by 10.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void malon_acao(struct CARD *card,int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse1,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int val = 0;

    if(!(card != NULL && card->origem->colecao == MALON && card->turn_silenced == 0)) return;

    if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->var_monster->qte_ataques == 0) val++;
    if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->var_monster->qte_ataques == 0) val++;
    if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->var_monster->qte_ataques == 0) val++;
    if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->var_monster->qte_ataques == 0) val++;
    if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->var_monster->qte_ataques == 0) val++;
    if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->var_monster->qte_ataques == 0) val++;
    if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->var_monster->qte_ataques == 0) val++;

    RefreshHP(id_acao,buffer,jogador->mesa->character,10*val,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

void malon_lvacao(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse1,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(jogador->mesa->monstro1 != NULL && EhBoss(jogador->mesa->monstro1)) RefreshHP(id_acao,buffer,jogador->mesa->monstro1,999,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(jogador->mesa->monstro2 != NULL && EhBoss(jogador->mesa->monstro2)) RefreshHP(id_acao,buffer,jogador->mesa->monstro2,999,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(jogador->mesa->monstro3 != NULL && EhBoss(jogador->mesa->monstro3)) RefreshHP(id_acao,buffer,jogador->mesa->monstro3,999,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(jogador->mesa->monstro4 != NULL && EhBoss(jogador->mesa->monstro4)) RefreshHP(id_acao,buffer,jogador->mesa->monstro4,999,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(jogador->mesa->monstro5 != NULL && EhBoss(jogador->mesa->monstro5)) RefreshHP(id_acao,buffer,jogador->mesa->monstro5,999,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(jogador->mesa->monstro6 != NULL && EhBoss(jogador->mesa->monstro6)) RefreshHP(id_acao,buffer,jogador->mesa->monstro6,999,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    else if(jogador->mesa->monstro7 != NULL && EhBoss(jogador->mesa->monstro7)) RefreshHP(id_acao,buffer,jogador->mesa->monstro7,999,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    RefreshHP(id_acao,buffer,jogador->mesa->character,10*TotalMobsEmCampo(jogador,adversario,0),fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse1,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

#endif // MALON_H_INCLUDED
