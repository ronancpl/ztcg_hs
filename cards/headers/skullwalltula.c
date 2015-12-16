#ifndef SKULLWALLTULA_H_INCLUDED
#define SKULLWALLTULA_H_INCLUDED

void skullwalltula(struct Card *card) {
        card->bmp = al_load_bitmap("cards/skullwalltula.png");
        card->nome = "Skullwalltula\0";
        card->elemento = "Dark\0";
        card->colecao = 86;
        card->RARIDADE = 7;
        card->preco = 710;
        card->tipo = "Monster\0";
        card->str_concat = "Dark - Monster - Spider\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Wall Climbing - Monster attacks dont hurt Skullwalltula.\0";
        card->monster->level = 32;
        card->monster->attack = 30;
        card->monster->MaxHP = 20;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Skulltulas Wrath - Spider monsters gets +20 bonus attack.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // SKULLWALLTULA_H_INCLUDED
