#ifndef DODONGO_H_INCLUDED
#define DODONGO_H_INCLUDED

void dodongo(struct Card *card) {
        card->bmp = al_load_bitmap("cards/dodongo.png");
        card->nome = "Dodongo\0";
        card->elemento = "Fire\0";
        card->colecao = 127;
        card->RARIDADE = 7;
        card->preco = 620;
        card->tipo = "Monster\0";
        card->str_concat = "Fire - Monster - Dodongo\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "\0";
        card->monster->level = 50;
        card->monster->attack = 20;
        card->monster->MaxHP = 50;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action 50 - Play an equipment or a tactic of level 50 or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // DODONGO_H_INCLUDED
