#ifndef BIG_DEKU_BABA_H_INCLUDED
#define BIG_DEKU_BABA_H_INCLUDED

void big_deku_baba(struct Card *card) {
        card->bmp = al_load_bitmap("cards/big_deku_baba.png");
        card->nome = "Big Deku Baba\0";
        card->elemento = "Earth\0";
        card->colecao = 145;
        card->RARIDADE = 3;
        card->preco = 980;
        card->tipo = "Jr. Boss\0";
        card->str_concat = "Earth - Jr. Boss - Deku\0";

        card->jrboss = (struct jrboss *)malloc(sizeof(struct jrboss));
        card->jrboss->level = 40;
        card->jrboss->attack = 20;
        card->jrboss->MaxHP = 60;

        card->jrboss->acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->acao = "Sting - Whenever a monster is targeted by Big Deku Baba, make that monster stunned for one turn.\0";
        card->jrboss->acao->atrib = 0;
        card->jrboss->acao->nivel = 0;
        card->jrboss->acao->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->prox->acao = "Deku Seeds - When Big Deku Baba is destroyed, look for a Deku monster on your deck and play it, then shuffle your deck.\0";
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
        card->lv_acao->acao = "Summon / Equip 90 - Play a monster or an equipment of level 90 or less.\0";
        card->lv_acao->nivel = 80;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // BIG_DEKU_BABA_H_INCLUDED
