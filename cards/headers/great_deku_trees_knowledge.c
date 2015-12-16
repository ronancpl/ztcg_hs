#ifndef GREAT_DEKU_TREES_KNOWLEDGE_H_INCLUDED
#define GREAT_DEKU_TREES_KNOWLEDGE_H_INCLUDED

void great_deku_trees_knowledge(struct Card *card) {
        card->bmp = al_load_bitmap("cards/great_deku_trees_knowledge.png");
        card->nome = "Great Deku Trees Knowledge\0";
        card->elemento = "Earth\0";
        card->colecao = 58;
        card->RARIDADE = 7;
        card->preco = 900;
        card->tipo = "Tactic\0";
        card->str_concat = "Earth - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Get a card of your level or less from your deck and draw it. Then, shuffle your deck.\0";
        card->tactic->level = 30;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Mercy - You and your opponent recover +40 HP. Draw a card.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void gdtk_lvacao(int id_acao,struct Card **buffer,bool *fim_de_jogo,int *rolagem,struct StatusBox_bitmaps *sbox,ALLEGRO_BITMAP *prompt,ALLEGRO_BITMAP *selecao,ALLEGRO_BITMAP *roll_bar,ALLEGRO_BITMAP *fundo_carta,ALLEGRO_BITMAP *fundo_menu,ALLEGRO_BITMAP *deck_meio,ALLEGRO_BITMAP *deck_cheio,ALLEGRO_BITMAP *pont,struct Player *jogador,struct Player *adversario,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *fundo,ALLEGRO_FONT *font,ALLEGRO_FONT *font2,ALLEGRO_COLOR color,bool *sair,int *posX,int *posY,int *dltZ,bool *mouse,bool *mouse2,bool *mouse_lado,int *keychar,bool *repete_keychar,ALLEGRO_EVENT_QUEUE *event_queue,ALLEGRO_TIMER *keyb_press_timer,ALLEGRO_TIMER *mouse_press_timer) {
    RefreshHP(id_acao,buffer,jogador->mesa->character,40,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    RefreshHP(id_acao,buffer,adversario->mesa->character,40,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,adversario,jogador,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
    DrawCard(id_acao,buffer,fim_de_jogo,rolagem,sbox,prompt,selecao,roll_bar,fundo_carta,fundo_menu,deck_meio,deck_cheio,pont,jogador,adversario,display,fundo,font,font2,color,sair,posX,posY,dltZ,mouse,mouse2,mouse_lado,keychar,repete_keychar,event_queue,keyb_press_timer,mouse_press_timer);
}

#endif // GREAT_DEKU_TREES_KNOWLEDGE_H_INCLUDED
