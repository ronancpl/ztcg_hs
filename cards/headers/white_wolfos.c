#ifndef WHITE_WOLFOS_H_INCLUDED
#define WHITE_WOLFOS_H_INCLUDED

void white_wolfos(struct Card *card) {
        card->bmp = al_load_bitmap("cards/white_wolfos.png");
        card->nome = "White Wolfos\0";
        card->elemento = "Water\0";
        card->colecao = 118;
        card->RARIDADE = 1;
        card->preco = 1810;
        card->tipo = "Jr. Boss\0";
        card->str_concat = "Water - Jr. Boss - Wolf\0";

        card->jrboss = (struct jrboss *)malloc(sizeof(struct jrboss));
        card->jrboss->level = 80;
        card->jrboss->attack = 10;
        card->jrboss->MaxHP = 90;

        card->jrboss->acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->acao = "Extremely Vicious - White Wolfos attacks three times per turn.\0";
        card->jrboss->acao->atrib = 0;
        card->jrboss->acao->nivel = 0;
        card->jrboss->acao->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->prox->acao = "Crescent Howl - For each monster destroyed by White Wolfos, its attack get increased by +10.\0";
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
        card->lv_acao->acao = "Summon / Equip / Locate 100 - Play a monster an equipment of level 100 or less or a field.\0";
        card->lv_acao->nivel = 80;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // WHITE_WOLFOS_H_INCLUDED
