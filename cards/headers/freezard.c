#ifndef FREEZARD_H_INCLUDED
#define FREEZARD_H_INCLUDED

void freezard(struct Card *card) {
        card->bmp = al_load_bitmap("cards/freezard.png");
        card->nome = "Freezard\0";
        card->elemento = "Wind\0";
        card->colecao = 128;
        card->RARIDADE = 1;
        card->preco = 1560;
        card->tipo = "Monster\0";
        card->str_concat = "Wind - Monster - Ice Statue\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Cold Breath - When you play Freezard, select a character or monster on the field and make it unable to attack or perform attack-based actions for 2 turns.\0";
        card->monster->level = 70;
        card->monster->attack = 40;
        card->monster->MaxHP = 70;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Hazardous Winds - If you have 3 or more WIND cards under your character, destroy a monster on field (except Jr. Boss or Boss monsters).\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void freezard_acao(int id_acao,struct Card **buffer,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *prompt,bool *fim_de_jogo,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,ALLEGRO_BITMAP *apontador,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *menu,*aux,*escolhido;

    Menu_Cria(&menu,&aux);
    if(adversario->var_tactic->char_withdrawal_cont == 0) Menu_CopiaDado(&aux,adversario->mesa->character);
    if(adversario->mesa->monstro1 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro1);
    if(adversario->mesa->monstro2 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro2);
    if(adversario->mesa->monstro3 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro3);
    if(adversario->mesa->monstro4 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro4);
    if(adversario->mesa->monstro5 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro5);
    if(adversario->mesa->monstro6 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro6);
    if(adversario->mesa->monstro7 != NULL) Menu_CopiaDado(&aux,adversario->mesa->monstro7);
    Menu_CelulaFinal(&aux);

    escolhido = MenuCards("FREEZARD: stun a target.",true,menu,fim_de_jogo,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(escolhido != NULL) escolhido->card->turn_cooldown += 2;

    Menu_Finaliza(menu);
}

#endif // FREEZARD_H_INCLUDED
