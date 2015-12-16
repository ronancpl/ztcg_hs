#ifndef PEAHAT_H_INCLUDED
#define PEAHAT_H_INCLUDED

void peahat(struct Card *card) {
        card->bmp = al_load_bitmap("cards/peahat.png");
        card->nome = "Peahat\0";
        card->elemento = "Wind\0";
        card->colecao = 53;
        card->RARIDADE = 3;
        card->preco = 2150;
        card->tipo = "Jr. Boss\0";
        card->str_concat = "Wind - Jr. Boss - Flying Plant\0";

        card->jrboss = (struct jrboss *)malloc(sizeof(struct jrboss));
        card->jrboss->level = 70;
        card->jrboss->attack = 40;
        card->jrboss->MaxHP = 110;

        card->jrboss->acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->acao = "Helix Attack - Do 30 damage to a character or monster at the turn Peahat is played.\0";
        card->jrboss->acao->atrib = 0;
        card->jrboss->acao->nivel = 0;
        card->jrboss->acao->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->jrboss->acao->prox->acao = "Larva Attack - Once per turn, if Peahats HP is 70 or less, do 20 damage to a character or monster for each WIND card under your character.\0";
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
        card->lv_acao->acao = "Summon / Locate 120 - Play a monster of level 120 or less or a field card.\0";
        card->lv_acao->nivel = 70;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // PEAHAT_H_INCLUDED
