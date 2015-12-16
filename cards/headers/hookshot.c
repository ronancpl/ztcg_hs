#ifndef HOOKSHOT_H_INCLUDED
#define HOOKSHOT_H_INCLUDED

void hookshot(struct Card *card) {
        card->bmp = al_load_bitmap("cards/hookshot.png");
        card->nome = "Hookshot\0";
        card->elemento = "Water\0";
        card->colecao = 22;
        card->RARIDADE = 1;
        card->preco = 1900;
        card->tipo = "Equipment\0";
        card->str_concat = "Water - Equipment - Weapon\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "At the start of your turn, pick one of these actions: Stun one of your opponents monsters for one turn OR Prevent one attack aimed to your character this turn.\0";
        card->equip->level = 60;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip / Locate 50 - Play a monster or an equipment of level 50 or less or a field card.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void hookshot_acao(int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    struct Deck *menu,*alvo,*aux,*resultado;

    if(ElaboraPrompt("HOOKSHOT effect! Pick one:",NULL,NULL,NULL,"STUN monster","PREVENT dmg",200,460,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        menu = (struct Deck *)malloc(sizeof(struct Deck));
        menu->prox = NULL;
        alvo = menu;

        if(adversario->mesa->monstro1 != NULL) {
            alvo->card = adversario->mesa->monstro1;
            alvo->prox = (struct Deck *)malloc(sizeof(struct Deck));
            alvo = alvo->prox;
            alvo->prox = NULL;
        }
        if(adversario->mesa->monstro2 != NULL) {
            alvo->card = adversario->mesa->monstro2;
            alvo->prox = (struct Deck *)malloc(sizeof(struct Deck));
            alvo = alvo->prox;
            alvo->prox = NULL;
        }
        if(adversario->mesa->monstro3 != NULL) {
            alvo->card = adversario->mesa->monstro3;
            alvo->prox = (struct Deck *)malloc(sizeof(struct Deck));
            alvo = alvo->prox;
            alvo->prox = NULL;
        }
        if(adversario->mesa->monstro4 != NULL) {
            alvo->card = adversario->mesa->monstro4;
            alvo->prox = (struct Deck *)malloc(sizeof(struct Deck));
            alvo = alvo->prox;
            alvo->prox = NULL;
        }
        if(adversario->mesa->monstro5 != NULL) {
            alvo->card = adversario->mesa->monstro5;
            alvo->prox = (struct Deck *)malloc(sizeof(struct Deck));
            alvo = alvo->prox;
            alvo->prox = NULL;
        }
        if(adversario->mesa->monstro6 != NULL) {
            alvo->card = adversario->mesa->monstro6;
            alvo->prox = (struct Deck *)malloc(sizeof(struct Deck));
            alvo = alvo->prox;
            alvo->prox = NULL;
        }
        if(adversario->mesa->monstro7 != NULL) {
            alvo->card = adversario->mesa->monstro7;
            alvo->prox = (struct Deck *)malloc(sizeof(struct Deck));
            alvo = alvo->prox;
            alvo->prox = NULL;
        }

        resultado = MenuCards("STUN a monster...",true,menu,fim,jogador,display,prompt,selecao,roll_bar,fundo_carta,fundo_menu,fundo,font2,font,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);

        if(resultado != NULL) {
            if(adversario->mesa->monstro1 != NULL && adversario->mesa->monstro1 == resultado->card) adversario->mesa->monstro1->turn_cooldown = adversario->mesa->monstro1->turn_cooldown + 1;
            else if(adversario->mesa->monstro2 != NULL && adversario->mesa->monstro2 == resultado->card) adversario->mesa->monstro2->turn_cooldown = adversario->mesa->monstro2->turn_cooldown + 1;
            else if(adversario->mesa->monstro3 != NULL && adversario->mesa->monstro3 == resultado->card) adversario->mesa->monstro3->turn_cooldown = adversario->mesa->monstro3->turn_cooldown + 1;
            else if(adversario->mesa->monstro4 != NULL && adversario->mesa->monstro4 == resultado->card) adversario->mesa->monstro4->turn_cooldown = adversario->mesa->monstro4->turn_cooldown + 1;
            else if(adversario->mesa->monstro5 != NULL && adversario->mesa->monstro5 == resultado->card) adversario->mesa->monstro5->turn_cooldown = adversario->mesa->monstro5->turn_cooldown + 1;
            else if(adversario->mesa->monstro6 != NULL && adversario->mesa->monstro6 == resultado->card) adversario->mesa->monstro6->turn_cooldown = adversario->mesa->monstro6->turn_cooldown + 1;
            else if(adversario->mesa->monstro7 != NULL && adversario->mesa->monstro7 == resultado->card) adversario->mesa->monstro7->turn_cooldown = adversario->mesa->monstro7->turn_cooldown + 1;
            else printf("RESULTADO GERADO NULO!\n");
        }

        alvo = menu;
        while(alvo->prox != NULL) {
            aux = alvo;
            alvo = alvo->prox;
            free(aux);
        }
        free(alvo);
    }
    else jogador->prevent_damage = jogador->prevent_damage + 1;
}

#endif // HOOKSHOT_H_INCLUDED
