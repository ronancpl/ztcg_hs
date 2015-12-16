#ifndef BONGOBONGO_H_INCLUDED
#define BONGOBONGO_H_INCLUDED

void bongobongo(struct Card *card) {
        card->bmp = al_load_bitmap("cards/bongobongo.png");
        card->nome = "BONGO-BONGO, Phantom Shadow Beast\0";
        card->elemento = "Dark\0";
        card->colecao = 27;
        card->RARIDADE = 3;
        card->preco = 1710;
        card->tipo = "Boss\0";
        card->str_concat = "Dark - Boss\0";

        card->boss = (struct boss *)malloc(sizeof(struct boss));
        card->boss->level = 87;
        card->boss->attack = 50;
        card->boss->MaxHP = 100;

        card->boss->acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->boss->acao->acao = "Shadow Hiding - All your monsters cant be hurt by character actions while Bongo-Bongo remains on the field.\0";
        card->boss->acao->atrib = 0;
        card->boss->acao->nivel = 0;
        card->boss->acao->prox = (struct char_action *)malloc(sizeof(struct char_action));

        card->boss->acao->prox->acao = "Earthquake - Do 20 damage to each opponents monsters on the field. Then, do 20 damage to a character.\0";
        card->boss->acao->prox->atrib = 2;
        card->boss->acao->prox->nivel = 70;
        card->boss->acao->prox->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->boss->acao->prox->prox->prox = NULL;

        card->tactic = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "\0";
        card->lv_acao->nivel = 0;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}
#endif // BONGOBONGO_H_INCLUDED
