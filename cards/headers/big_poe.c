#ifndef BIG_POE_H_INCLUDED
#define BIG_POE_H_INCLUDED

void big_poe(struct Card *card) {
        card->bmp = al_load_bitmap("cards/big_poe.png");
        card->nome = "Big Poe\0";
        card->elemento = "Light\0";
        card->colecao = 107;
        card->RARIDADE = 3;
        card->preco = 1525;
        card->tipo = "Jr. Boss\0";
        card->str_concat = "Light - Jr. Boss - Ghost Monster\0";

        card->jrboss = (struct jrboss *)malloc(sizeof(struct jrboss));
        card->jrboss->level = 57;
        card->jrboss->attack = 30;
        card->jrboss->MaxHP = 90;

        card->jrboss->acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->acao = "Hide - Monster attacks dont hurt Big Poe.\0";
        card->jrboss->acao->atrib = 0;
        card->jrboss->acao->nivel = 0;
        card->jrboss->acao->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->prox->acao = "Poe Summon - Starting your monster attack phase, if Big Poe has 50 HP or less, look for a Ghost monster on your deck and play it, then shuffle your deck. That monster gets +20 HP and +20 attack for 2 turns.\0";
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
        card->lv_acao->acao = "Summon 100 - Play a monster of level 100 or less.\0";
        card->lv_acao->nivel = 70;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // BIG_POE_H_INCLUDED
