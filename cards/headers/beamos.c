#ifndef BEAMOS_H_INCLUDED
#define BEAMOS_H_INCLUDED

void beamos(struct Card *card) {
        card->bmp = al_load_bitmap("cards/beamos.png");
        card->nome = "Beamos\0";
        card->elemento = "Dark\0";
        card->colecao = 125;
        card->RARIDADE = 7;
        card->preco = 470;
        card->tipo = "Monster\0";
        card->str_concat = "Dark - Monster - Statue\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Beam Attack - Whenever Beamos destroys a monster, draw a card.\0";
        card->monster->level = 26;
        card->monster->attack = 20;
        card->monster->MaxHP = 20;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Scout - Peek at the next card of your deck. If it is a monster, draw it. Flip back otherwise. If the former, play it if its of your level or less and playable.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // BEAMOS_H_INCLUDED
