#ifndef GOHMA_H_INCLUDED
#define GOHMA_H_INCLUDED

void gohma(struct Card *card) {
        card->bmp = al_load_bitmap("cards/gohma.png");
        card->nome = "GOHMA, Parasitic Armored Arachnid\0";
        card->elemento = "Earth\0";
        card->colecao = 3;
        card->RARIDADE = 7;
        card->preco = 1400;
        card->tipo = "Boss\0";
        card->str_concat = "Earth - Boss\0";

        card->boss = (struct boss *)malloc(sizeof(struct boss));
        card->boss->level = 68;
        card->boss->attack = 40;
        card->boss->MaxHP = 90;

        card->boss->acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->boss->acao->acao = "Lay Eggs - Starting your monster attack phase, if Gohma has 60 HP or less, search for a Spider monster on your deck and play it. Then, shuffle your deck.\0";
        card->boss->acao->atrib = 3;
        card->boss->acao->nivel = 60;
        card->boss->acao->prox = (struct char_action *)malloc(sizeof(struct char_action));
        card->boss->acao->prox->prox = NULL;

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

#endif // GOHMA_H_INCLUDED
