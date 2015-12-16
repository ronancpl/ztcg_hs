#ifndef SKULL_KID_H_INCLUDED
#define SKULL_KID_H_INCLUDED

void skull_kid(struct Card *card) {
        card->bmp = al_load_bitmap("cards/skull_kid.png");
        card->nome = "Skull Kid\0";
        card->elemento = "Earth\0";
        card->colecao = 111;
        card->RARIDADE = 3;
        card->preco = 1360;
        card->tipo = "Monster\0";
        card->str_concat = "Earth - Monster - NPC Skull Kid\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "NPC QUEST - Play a tactic. REWARD - Flip a coin. If you win, for one turn double the damage output of one of your monsters (not stackable) with level equal or below 50 and draw a card. Else, your opponent draws a card.\0";
        card->monster->level = 42;
        card->monster->attack = 20;
        card->monster->MaxHP = 40;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action 60 - Play an equipment or a tactic of level 60 or less.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 1;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // SKULL_KID_H_INCLUDED
