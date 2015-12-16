#ifndef TWINROVA_H_INCLUDED
#define TWINROVA_H_INCLUDED

void twinrova(struct Card *card) {
        card->bmp = al_load_bitmap("cards/twinrova.png");
        card->nome = "TWINROVA, Sorceress Sisters\0";
        card->elemento = "Wind\0";
        card->colecao = 9;
        card->RARIDADE = 1;
        card->preco = 1830;
        card->tipo = "Boss\0";
        card->str_concat = "Wind - Boss\0";

        card->boss = (struct boss *)malloc(sizeof(struct boss));
        card->boss->level = 90;
        card->boss->attack = 60;
        card->boss->MaxHP = 150;

        card->boss->acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->boss->acao->acao = "Ice/Fire Energy Blast - Do 20 damage to a character. For each turn you use this action, flip a coin. Whenever you get 3 wins consecutively, do 120 damage to a character.\0";
        card->boss->acao->atrib = 0;
        card->boss->acao->nivel = 0;
        card->boss->acao->prox = (struct char_action *)malloc(sizeof(struct char_action));

        card->boss->acao->prox->acao = "Koume & Kotake Double Dynamite Attack - Whenever Twinrova gets 80 HP or less, get +20 attack with all of your monster attacks, character actions and tactics.\0";
        card->boss->acao->prox->atrib = 2;
        card->boss->acao->prox->nivel = 90;
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

#endif // TWINROVA_H_INCLUDED
