#ifndef GREAT_DEKUS_BLESS_H_INCLUDED
#define GREAT_DEKUS_BLESS_H_INCLUDED

void great_dekus_bless(struct Card *card) {
        card->bmp = al_load_bitmap("cards/great_dekus_bless.png");
        card->nome = "Great Dekus Bless\0";
        card->elemento = "Earth\0";
        card->colecao = 2;
        card->RARIDADE = 7;
        card->preco = 450;
        card->tipo = "Tactic\0";
        card->str_concat = "Earth - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Get 20 damage with the next monster attack or tactic this turn. Draw a card.\0";
        card->tactic->level = 45;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Scout - Peek at the next card of your deck. If it is a monster, draw it. Flip back otherwise. If the former, play it if its of your level or less and playable.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

void great_dekus_bless_tactic(int *attack,short int *valor,bool aplicavel) {
    printf("BUFF: GREAT DEKU BLESS TACTIC x %d\n",*valor);
    *attack = *attack + (*valor * 20);
    if(aplicavel) *valor = 0;
}

#endif // GREAT_DEKUS_BLESS_H_INCLUDED
