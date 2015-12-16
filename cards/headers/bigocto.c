#ifndef BIGOCTO_H_INCLUDED
#define BIGOCTO_H_INCLUDED

void bigocto(struct Card *card) {
        card->bmp = al_load_bitmap("cards/bigocto.png");
        card->nome = "Bigocto\0";
        card->elemento = "Water\0";
        card->colecao = 40;
        card->RARIDADE = 3;
        card->preco = 1320;
        card->tipo = "Jr. Boss\0";
        card->str_concat = "Water - Jr. Boss - Octopus\0";

        card->jrboss = (struct jrboss *)malloc(sizeof(struct jrboss));
        card->jrboss->level = 65;
        card->jrboss->attack = 30;
        card->jrboss->MaxHP = 80;

        card->jrboss->acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->acao = "Tough - Monster attacks dont hurt Bigocto.\0";
        card->jrboss->acao->atrib = 0;
        card->jrboss->acao->nivel = 0;
        card->jrboss->acao->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->prox->acao = "Well-protected Weak Point - Whenever Bigocto is damaged, do 20 damage to a character or monster.\0";
        card->jrboss->acao->prox->atrib = 0;
        card->jrboss->acao->prox->nivel = 0;
        card->jrboss->acao->prox->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->prox->prox->prox = NULL;

        card->tactic = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->boss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Refresh - Recover +10 HP.\0";
        card->lv_acao->nivel = 40;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // BIGOCTO_H_INCLUDED
