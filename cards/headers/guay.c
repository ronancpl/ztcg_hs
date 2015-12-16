#ifndef GUAY_H_INCLUDED
#define GUAY_H_INCLUDED

void guay(struct Card *card) {
        card->bmp = al_load_bitmap("cards/guay.png");
        card->nome = "Guay\0";
        card->elemento = "Wind\0";
        card->colecao = 28;
        card->RARIDADE = 7;
        card->preco = 540;
        card->tipo = "Monster\0";
        card->str_concat = "Wind - Monster - Bird\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Peck - When you play Guay, do 20 damage to a character or monster.\nFlying Monster - Monster attacks dont hurt Guay.\0";
        card->monster->level = 25;
        card->monster->attack = 20;
        card->monster->MaxHP = 20;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Stab - Do 10 damage to a character or monster.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 1;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // GUAY_H_INCLUDED
