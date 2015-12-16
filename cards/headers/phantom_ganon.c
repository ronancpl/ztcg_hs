#ifndef PHANTOM_GANON_H_INCLUDED
#define PHANTOM_GANON_H_INCLUDED

void phantom_ganon(struct Card *card) {
        card->bmp = al_load_bitmap("cards/phantom_ganon.png");
        card->nome = "PHANTOM GANON, Evil Spirit from Beyond\0";
        card->elemento = "Earth\0";
        card->colecao = 39;
        card->RARIDADE = 1;
        card->preco = 1720;
        card->tipo = "Boss\0";
        card->str_concat = "Earth - Boss\0";

        card->boss = (struct boss *)malloc(sizeof(struct boss));
        card->boss->level = 80;
        card->boss->attack = 50;
        card->boss->MaxHP = 120;

        card->boss->acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->boss->acao->acao = "Dimensional Shifter - When Phantom Ganon is destroyed, flip a coin. If you win, it backs to the field with 40 HP.\0";
        card->boss->acao->atrib = 0;
        card->boss->acao->nivel = 0;
        card->boss->acao->prox = (struct char_action *)malloc(sizeof(struct char_action));

        card->boss->acao->prox->acao = "Rainbow Blast - Do 80 damage to a character or monster.\0";
        card->boss->acao->prox->atrib = 3;
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

#endif // PHANTOM_GANON_H_INCLUDED
