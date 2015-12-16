#ifndef FLARE_DANCER_H_INCLUDED
#define FLARE_DANCER_H_INCLUDED

void flare_dancer(struct Card *card) {
        card->bmp = al_load_bitmap("cards/flare_dancer.png");
        card->nome = "Flare Dancer\0";
        card->elemento = "Fire\0";
        card->colecao = 12;
        card->RARIDADE = 3;
        card->preco = 1300;
        card->tipo = "Jr. Boss\0";
        card->str_concat = "Fire - Jr. Boss - Flare Dancer\0";

        card->jrboss = (struct jrboss *)malloc(sizeof(struct jrboss));
        card->jrboss->level = 67;
        card->jrboss->attack = 40;
        card->jrboss->MaxHP = 80;

        card->jrboss->acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->acao = "Flame Slide - Monster attacks dont hurt Flame Dancer.\0";
        card->jrboss->acao->atrib = 0;
        card->jrboss->acao->nivel = 0;
        card->jrboss->acao->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->prox->acao = "Fire Leader - All of your other FIRE monsters gets +20 attack while Flare Dancer remains on field.\0";
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
        card->lv_acao->acao = "Burning Flames - Do 20 damage to a character or monster.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // FLARE_DANCER_H_INCLUDED
