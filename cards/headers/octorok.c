#ifndef OCTOROK_H_INCLUDED
#define OCTOROK_H_INCLUDED

void octorok(struct Card *card) {
        card->bmp = al_load_bitmap("cards/octorok.png");
        card->nome = "Octorok\0";
        card->elemento = "Water\0";
        card->colecao = 78;
        card->RARIDADE = 7;
        card->preco = 720;
        card->tipo = "Monster\0";
        card->str_concat = "Water - Monster - Octopus\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Squishy - Monster attacks dont hurt Octorok.\0";
        card->monster->level = 53;
        card->monster->attack = 20;
        card->monster->MaxHP = 40;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Crafty 70 - Play a card of level 70 or less.\0";
        card->lv_acao->nivel = 80;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // OCTOROK_H_INCLUDED
