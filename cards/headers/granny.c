#ifndef GRANNY_H_INCLUDED
#define GRANNY_H_INCLUDED

void granny(struct Card *card) {
        card->bmp = al_load_bitmap("cards/granny.png");
        card->nome = "Granny\0";
        card->elemento = "Dark\0";
        card->colecao = 92;
        card->RARIDADE = 3;
        card->preco = 1300;
        card->tipo = "Monster\0";
        card->str_concat = "Dark - Monster - NPC Hylian\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "NPC Quest - When your turn starts, discard a card from your hand. Reward - Get +80 HP with a Character, a Jr. Boss or a Boss monster.\0";
        card->monster->level = 69;
        card->monster->attack = 40;
        card->monster->MaxHP = 50;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip / Rapid Action 80 - Play a monster, an equipment or a tactic of level 80 or less.\0";
        card->lv_acao->nivel = 80;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void granny_acao(int id_acao,struct Card **buffer,bool *fim,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer,ALLEGRO_BITMAP *pont,int *rolagem) {
    struct Deck *card,*menu,*aux,*aux2;

    if(jogador->hand->inicio->prox == NULL) return;

    if(ElaboraPrompt("Use GRANNY effect?","Discard a card to gain 80HP with a Character or Jr. Boss or Boss monster.",NULL,NULL,"Yes","No",245,515,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        DiscardCard(id_acao,buffer,fim,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,jogador,adversario,display,fundo,font,font2,color,pont,rolagem,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        menu = (struct Deck *)malloc(sizeof(struct Deck));
        aux = menu;

        if(jogador->mesa->character->HP < jogador->mesa->character->MaxHP) {
            aux->card = jogador->mesa->character;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
        }

        if(jogador->mesa->monstro1 != NULL && EhBoss(jogador->mesa->monstro1) && jogador->mesa->monstro1->HP < jogador->mesa->monstro1->MaxHP) {
            aux->card = jogador->mesa->monstro1;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
        }

        if(jogador->mesa->monstro2 != NULL && EhBoss(jogador->mesa->monstro2) && jogador->mesa->monstro2->HP < jogador->mesa->monstro2->MaxHP) {
            aux->card = jogador->mesa->monstro2;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
        }

        if(jogador->mesa->monstro3 != NULL && EhBoss(jogador->mesa->monstro3) && jogador->mesa->monstro3->HP < jogador->mesa->monstro3->MaxHP) {
            aux->card = jogador->mesa->monstro3;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
        }

        if(jogador->mesa->monstro4 != NULL && EhBoss(jogador->mesa->monstro4) && jogador->mesa->monstro4->HP < jogador->mesa->monstro4->MaxHP) {
            aux->card = jogador->mesa->monstro4;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
        }

        if(jogador->mesa->monstro5 != NULL && EhBoss(jogador->mesa->monstro5) && jogador->mesa->monstro5->HP < jogador->mesa->monstro5->MaxHP) {
            aux->card = jogador->mesa->monstro5;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
        }

        if(jogador->mesa->monstro6 != NULL && EhBoss(jogador->mesa->monstro6) && jogador->mesa->monstro6->HP < jogador->mesa->monstro6->MaxHP) {
            aux->card = jogador->mesa->monstro6;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
        }

        if(jogador->mesa->monstro7 != NULL && EhBoss(jogador->mesa->monstro7) && jogador->mesa->monstro7->HP < jogador->mesa->monstro7->MaxHP) {
            aux->card = jogador->mesa->monstro7;
            aux->prox = (struct Deck *)malloc(sizeof(struct Deck));
            aux = aux->prox;
        }

        aux->prox = NULL;

        card = MenuCards("GRANNY: Select the one to receive +80HP",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
        if(card != NULL) RefreshHP(id_acao,buffer,card->card,80,fim,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        aux = menu;
        while(aux->prox != NULL) {
            aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
        free(aux);
    }
}

#endif // GRANNY_H_INCLUDED
