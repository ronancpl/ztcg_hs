#ifndef LARVA_GOHMA_H_INCLUDED
#define LARVA_GOHMA_H_INCLUDED

void larva_gohma(struct Card *card) {
        card->bmp = al_load_bitmap("cards/larva_gohma.png");
        card->nome = "Larva Gohma\0";
        card->elemento = "Earth\0";
        card->colecao = 55;
        card->RARIDADE = 7;
        card->preco = 420;
        card->tipo = "Monster\0";
        card->str_concat = "Earth - Monster - Spider\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Tough - Character actions dont hurt Larva Gohma.\0";
        card->monster->level = 12;
        card->monster->attack = 10;
        card->monster->MaxHP = 20;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 50 - Play a monster or an equipment of level 50 or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // LARVA_GOHMA_H_INCLUDED
