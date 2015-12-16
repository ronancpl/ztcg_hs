#ifndef FABULOUS_FIVE_FROGGISH_TENORS_H_INCLUDED
#define FABULOUS_FIVE_FROGGISH_TENORS_H_INCLUDED

void fabulous_five_froggish_tenors(struct Card *card) {
        card->bmp = al_load_bitmap("cards/fabulous_five_froggish_tenors.png");
        card->nome = "Fabulous Five Froggish Tenors\0";
        card->elemento = "Earth\0";
        card->colecao = 88;
        card->RARIDADE = 3;
        card->preco = 1030;
        card->tipo = "Monster\0";
        card->str_concat = "Earth - Monster - Frog\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Orchestral Buff - All of your monsters on the field get +10 damage with their attacks.\0";
        card->monster->level = 36;
        card->monster->attack = 20;
        card->monster->MaxHP = 40;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Monster Resurrection - Retrieve a monster of level 50 or above from your graveyard and play it if its the same level of yours or less.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // FABULOUS_FIVE_FROGGISH_TENORS_H_INCLUDED
