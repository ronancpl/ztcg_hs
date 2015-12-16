#ifndef TRIPLE_SHOT_H_INCLUDED
#define TRIPLE_SHOT_H_INCLUDED

void triple_shot(struct Card *card) {
        card->bmp = al_load_bitmap("cards/triple_shot.png");
        card->nome = "Triple Shot\0";

        card->elemento = "Fire\0";
        card->colecao = 64;
        card->RARIDADE = 7;
        card->preco = 750;
        card->tipo = "Tactic\0";
        card->str_concat = "Fire - Tactic - Skill\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Destroy a monster on the field. Draw a card.\0";
        card->tactic->level = 20;

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

#endif // TRIPLE_SHOT_H_INCLUDED
