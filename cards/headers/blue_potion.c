#ifndef BLUE_POTION_H_INCLUDED
#define BLUE_POTION_H_INCLUDED

void blue_potion(struct Card *card) {
        card->bmp = al_load_bitmap("cards/blue_potion.png");
        card->nome = "Blue Potion\0";
        card->elemento = "Water\0";
        card->colecao = 11;
        card->RARIDADE = 3;
        card->preco = 970;
        card->tipo = "Equipment\0";
        card->str_concat = "Water - Equipment - Potion\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "At the start of your turn you may destroy this item. If you do, get + 20HP x your level, and draw cards until you have 3 cards on the hand. Also, get +10 damage with your monster attacks.\0";
        card->equip->level = 70;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Drink Potion - Recover x10 HP equals to your level.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void blue_potion_acao(struct CARD **card,int id_acao,struct Card **buffer,bool *fim,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    int HPrest = 0,cards;
    struct Deck *aux;

    cards = 3 - jogador->hand->quantidade;
    if(cards < 0) cards = 0;

    HPrest = (jogador->level * 2);
    if(ElaboraPrompt("Use BLUE POTION?","%d HP restoration, draw %d cards.",(void *)HPrest,(void *)cards,"Drink","Keep",240,510,315,id_acao,buffer,fim,rolagem,sbox,selecao,roll_bar,fundo_carta,fundo_menu,prompt,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer)) {
        aux = (struct Deck *)malloc(sizeof(struct Deck));
        aux->card = *card;
        DestroyCard(aux,jogador,adversario);
        *card = NULL;

        *(jogador->HP) = *(jogador->HP) + HPrest;
        if(*(jogador->HP) > *(jogador->MaxHP)) *(jogador->HP) = *(jogador->MaxHP);
        while(jogador->hand->quantidade < 3 && jogador->deck->quantidade > 0) DrawCard_inicial(jogador);

        jogador->var_tactic->blue_potion_cont++;
    }
}

#endif // BLUE_POTION_H_INCLUDED
