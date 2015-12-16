#ifndef WOLFOS_H_INCLUDED
#define WOLFOS_H_INCLUDED

void wolfos(struct Card *card) {
        card->bmp = al_load_bitmap("cards/wolfos.png");
        card->nome = "Wolfos\0";
        card->elemento = "Earth\0";
        card->colecao = 93;
        card->RARIDADE = 7;
        card->preco = 960;
        card->tipo = "Monster\0";
        card->str_concat = "Earth - Monster - Wolf\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Vicious - Wolfos attacks twice each turn.\0";
        card->monster->level = 70;
        card->monster->attack = 30;
        card->monster->MaxHP = 50;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action / Locate 80 - Play an equipment or a tactic of level 80 or less or a field card.\0";
        card->lv_acao->nivel = 80;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // WOLFOS_H_INCLUDED
