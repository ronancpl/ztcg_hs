#ifndef BIGGER_BOMB_BAG_H_INCLUDED
#define BIGGER_BOMB_BAG_H_INCLUDED

void bigger_bomb_bag(struct Card *card) {
        card->bmp = al_load_bitmap("cards/bigger_bomb_bag.png");
        card->nome = "Bigger Bomb Bag\0";
        card->elemento = "Fire\0";
        card->colecao = 138;
        card->RARIDADE = 3;
        card->preco = 1570;
        card->tipo = "Equipment\0";
        card->str_concat = "Dark - Equipment - Bag\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Once per turn, whenever you destroy a monster with a character attack buffed by a Weapon effect draw a card. Additionally, you may override one Bomb if equipped: get +20 attack with two character actions per turn instead. Bomb actions count is not restored to 2 if this is played after use of a Bomb action; one extra action still applied.\0";
        card->equip->level = 50;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Locate 60 - Play an equipment of level 60 or less or a field card.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void bigger_bomb_bag_slot(struct CARD *card,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    DrawCard(id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    card->var_equip->bigger_bomb_bag_bool = false;
}

void bigger_bomb_bag_acao(bool usa_weapon,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    if(usa_weapon == false) return;

    if(jogador->mesa->equip1 != NULL && jogador->mesa->equip1->origem->colecao == BIGGER_BOMB_BAG && jogador->mesa->equip1->var_equip->bigger_bomb_bag_bool == true) bigger_bomb_bag_slot(jogador->mesa->equip1,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip2 != NULL && jogador->mesa->equip2->origem->colecao == BIGGER_BOMB_BAG && jogador->mesa->equip2->var_equip->bigger_bomb_bag_bool == true) bigger_bomb_bag_slot(jogador->mesa->equip2,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip3 != NULL && jogador->mesa->equip3->origem->colecao == BIGGER_BOMB_BAG && jogador->mesa->equip3->var_equip->bigger_bomb_bag_bool == true) bigger_bomb_bag_slot(jogador->mesa->equip3,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip4 != NULL && jogador->mesa->equip4->origem->colecao == BIGGER_BOMB_BAG && jogador->mesa->equip4->var_equip->bigger_bomb_bag_bool == true) bigger_bomb_bag_slot(jogador->mesa->equip4,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip5 != NULL && jogador->mesa->equip5->origem->colecao == BIGGER_BOMB_BAG && jogador->mesa->equip5->var_equip->bigger_bomb_bag_bool == true) bigger_bomb_bag_slot(jogador->mesa->equip5,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip6 != NULL && jogador->mesa->equip6->origem->colecao == BIGGER_BOMB_BAG && jogador->mesa->equip6->var_equip->bigger_bomb_bag_bool == true) bigger_bomb_bag_slot(jogador->mesa->equip6,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    if(jogador->mesa->equip7 != NULL && jogador->mesa->equip7->origem->colecao == BIGGER_BOMB_BAG && jogador->mesa->equip7->var_equip->bigger_bomb_bag_bool == true) bigger_bomb_bag_slot(jogador->mesa->equip7,id_acao,buffer,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

bool bigger_bomb_bag_override_bomb(struct CARD *equip) {
    if(equip != NULL && equip->origem->colecao == BOMB && equip->var_equip->bomb_dmg == 10) {
        equip->var_equip->bomb_dmg = 20;
        equip->var_equip->bomb_cont += 1;
        return(true);
    }
    return(false);
}

void bigger_bomb_bag_override_effect_slot(struct CARD *equip,struct Player *jogador) {
    if(equip != NULL && equip->origem->colecao == BIGGER_BOMB_BAG) {
        if(bigger_bomb_bag_override_bomb(jogador->mesa->equip1) ||
            bigger_bomb_bag_override_bomb(jogador->mesa->equip2) ||
            bigger_bomb_bag_override_bomb(jogador->mesa->equip3) ||
            bigger_bomb_bag_override_bomb(jogador->mesa->equip4) ||
            bigger_bomb_bag_override_bomb(jogador->mesa->equip5) ||
            bigger_bomb_bag_override_bomb(jogador->mesa->equip6) ||
            bigger_bomb_bag_override_bomb(jogador->mesa->equip7)) equip->var_equip->bigger_bomb_bag_overriding_bool = true;
    }
}

bool bigger_bomb_bag_played_bomb_slot(struct CARD *equip,struct CARD *bomb) {
    if(equip != NULL && equip->origem->colecao == BIGGER_BOMB_BAG && equip->var_equip->bigger_bomb_bag_overriding_bool == false) {
        bigger_bomb_bag_override_bomb(bomb);
        equip->var_equip->bigger_bomb_bag_overriding_bool = true;
        return(true);
    }
    return(false);
}

void bigger_bomb_bag_played_bomb(struct CARD *equip,struct Player *jogador) {
        if(bigger_bomb_bag_played_bomb_slot(jogador->mesa->equip1,equip));
        else if(bigger_bomb_bag_played_bomb_slot(jogador->mesa->equip2,equip));
        else if(bigger_bomb_bag_played_bomb_slot(jogador->mesa->equip3,equip));
        else if(bigger_bomb_bag_played_bomb_slot(jogador->mesa->equip4,equip));
        else if(bigger_bomb_bag_played_bomb_slot(jogador->mesa->equip5,equip));
        else if(bigger_bomb_bag_played_bomb_slot(jogador->mesa->equip6,equip));
        else if(bigger_bomb_bag_played_bomb_slot(jogador->mesa->equip7,equip));
}

#endif // BIGGER_BOMB_BAG_H_INCLUDED
