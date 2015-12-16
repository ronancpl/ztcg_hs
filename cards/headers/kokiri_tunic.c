#ifndef KOKIRI_TUNIC_H_INCLUDED
#define KOKIRI_TUNIC_H_INCLUDED

void kokiri_tunic(struct Card *card) {
        card->bmp = al_load_bitmap("cards/kokiri_tunic.png");
        card->nome = "Kokiri Tunic\0";
        card->elemento = "Earth\0";
        card->colecao = 143;
        card->RARIDADE = 3;
        card->preco = 1200;
        card->tipo = "Equipment\0";
        card->str_concat = "Earth - Equipment - Armor\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Block 10 damage from monster attacks aimed to your character. Also, heal 10 HP for each monster destroyed by a character action.\0";
        card->equip->level = 40;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon 100 - Play a monster of level 100 or less.\0";
        card->lv_acao->nivel = 70;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void kokiri_tunic_acao(int origem_ataque,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *apontador,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(origem_ataque != 1) return;

    if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,jogador->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,jogador->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,jogador->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,jogador->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,jogador->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,jogador->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,jogador->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

    if(adversario->mesa->equip1 != NULL && adversario->mesa->equip1->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,adversario->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->equip2 != NULL && adversario->mesa->equip2->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,adversario->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->equip3 != NULL && adversario->mesa->equip3->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,adversario->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->equip4 != NULL && adversario->mesa->equip4->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,adversario->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->equip5 != NULL && adversario->mesa->equip5->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,adversario->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->equip6 != NULL && adversario->mesa->equip6->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,adversario->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(adversario->mesa->equip7 != NULL && adversario->mesa->equip7->origem->colecao == KOKIRI_TUNIC) RefreshHP(id_acao,buffer,adversario->mesa->character,10,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,apontador,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}
#endif // KOKIRI_TUNIC_H_INCLUDED
