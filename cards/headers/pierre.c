#ifndef PIERRE_H_INCLUDED
#define PIERRE_H_INCLUDED

void pierre(struct Card *card) {
        card->bmp = al_load_bitmap("cards/pierre.png");
        card->nome = "Pierre, the Scarecrow\0";
        card->elemento = "Wind\0";
        card->colecao = 10;
        card->RARIDADE = 3;
        card->preco = 1000;
        card->tipo = "Monster\0";
        card->str_concat = "Wind - Monster - NPC Scarecrow\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "NPC QUEST - At your turn, play at least a monster of your level or less. REWARD - One of these monsters gets +20 damage with its attack until the end of the turn.\0";
        card->monster->level = 40;
        card->monster->attack = 20;
        card->monster->MaxHP = 30;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Monster Resurrection - Retrieve a monster of level 50 or above from your graveyard and play it if its the same level of yours or less.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void pierre_acao(bool *fim,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *fundo,struct Player *jogador,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *alvo,*aux;
    struct Deck *escolhido;

    Menu_Cria(&alvo,&aux);

    if(jogador->mesa->monstro1 != NULL && jogador->mesa->monstro1->var_monster->spawn_bool == true) Menu_CopiaDado(&aux,jogador->mesa->monstro1);
    if(jogador->mesa->monstro2 != NULL && jogador->mesa->monstro2->var_monster->spawn_bool == true) Menu_CopiaDado(&aux,jogador->mesa->monstro2);
    if(jogador->mesa->monstro3 != NULL && jogador->mesa->monstro3->var_monster->spawn_bool == true) Menu_CopiaDado(&aux,jogador->mesa->monstro3);
    if(jogador->mesa->monstro4 != NULL && jogador->mesa->monstro4->var_monster->spawn_bool == true) Menu_CopiaDado(&aux,jogador->mesa->monstro4);
    if(jogador->mesa->monstro5 != NULL && jogador->mesa->monstro5->var_monster->spawn_bool == true) Menu_CopiaDado(&aux,jogador->mesa->monstro5);
    if(jogador->mesa->monstro6 != NULL && jogador->mesa->monstro6->var_monster->spawn_bool == true) Menu_CopiaDado(&aux,jogador->mesa->monstro6);
    if(jogador->mesa->monstro7 != NULL && jogador->mesa->monstro7->var_monster->spawn_bool == true) Menu_CopiaDado(&aux,jogador->mesa->monstro7);
    Menu_CelulaFinal(&aux);

    al_rest(0.2);
    escolhido = MenuCards("Pierre REWARD...",true,alvo,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(escolhido != NULL) {
        if(jogador->mesa->monstro1 == escolhido->card) jogador->mesa->monstro1->var_monster->pierre_cont += 1;
        else if(jogador->mesa->monstro2 == escolhido->card) jogador->mesa->monstro2->var_monster->pierre_cont += 1;
        else if(jogador->mesa->monstro3 == escolhido->card) jogador->mesa->monstro3->var_monster->pierre_cont += 1;
        else if(jogador->mesa->monstro4 == escolhido->card) jogador->mesa->monstro4->var_monster->pierre_cont += 1;
        else if(jogador->mesa->monstro5 == escolhido->card) jogador->mesa->monstro5->var_monster->pierre_cont += 1;
        else if(jogador->mesa->monstro6 == escolhido->card) jogador->mesa->monstro6->var_monster->pierre_cont += 1;
        else jogador->mesa->monstro7->var_monster->pierre_cont += 1;
    }

    Menu_Finaliza(alvo);
}

#endif // PIERRE_H_INCLUDED
