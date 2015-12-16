#ifndef CLAIM_CHECK_H_INCLUDED
#define CLAIM_CHECK_H_INCLUDED

void claim_check(struct Card *card) {
        card->bmp = al_load_bitmap("cards/claim_check.png");
        card->nome = "Claim Check\0";
        card->elemento = "Water\0";
        card->colecao = 134;
        card->RARIDADE = 7;
        card->preco = 750;
        card->tipo = "Equipment\0";
        card->str_concat = "Water - Equipment - Proof\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Once per turn, whenever you play a Weapon draw a card.\0";
        card->equip->level = 30;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Scout - Peek at the next card of your deck. If it is a monster, draw it. Flip back otherwise. If the former, play it if its of your level or less and playable.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // CLAIM_CHECK_H_INCLUDED
