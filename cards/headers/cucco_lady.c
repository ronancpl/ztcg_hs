#ifndef CUCCO_LADY_H_INCLUDED
#define CUCCO_LADY_H_INCLUDED

void cucco_lady(struct Card *card) {
        card->bmp = al_load_bitmap("cards/cucco_lady.png");
        card->nome = "Cucco Lady\0";
        card->elemento = "Light\0";
        card->colecao = 62;
        card->RARIDADE = 7;
        card->preco = 500;
        card->tipo = "Monster\0";
        card->str_concat = "Light - Monster - NPC Hylian\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "NPC Quest - Play a monster of level 30 or less. Reward - Draw a card (effect is not stackable by multiple Cucco Ladies on the field).\0";
        card->monster->level = 15;
        card->monster->attack = 10;
        card->monster->MaxHP = 20;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 30 - Play a monster or an equipment of level 30 or less.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // CUCCO_LADY_H_INCLUDED
