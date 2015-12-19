#ifndef BARI_H_INCLUDED
#define BARI_H_INCLUDED

void bari(struct Card *card) {
        card->bmp = al_load_bitmap("cards/bari.png");
        card->nome = "Bari\0";
        card->elemento = "Light\0";
        card->colecao = 152;
        card->RARIDADE = 1;
        card->preco = 1650;
        card->tipo = "Monster\0";
        card->str_concat = "Light - Monster - Jellyfish\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Eletric Body - Do 20 damage to any monsters that attacks Bari. Sunder - When Bari is destroyed in consequence of battle, you may search for a Biri monster on your deck and summon it.\0";
        card->monster->level = 62;
        card->monster->attack = 50;
        card->monster->MaxHP = 60;

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

#endif // BARI_H_INCLUDED
