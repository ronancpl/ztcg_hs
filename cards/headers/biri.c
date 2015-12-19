#ifndef BIRI_H_INCLUDED
#define BIRI_H_INCLUDED

void biri(struct Card *card) {
        card->bmp = al_load_bitmap("cards/biri.png");
        card->nome = "Biri\0";
        card->elemento = "Light\0";
        card->colecao = 153;
        card->RARIDADE = 7;
        card->preco = 560;
        card->tipo = "Monster\0";
        card->str_concat = "Light - Monster - Jellyfish\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Spawnling - At the turn Bari turns into Biri, Biri gets +30 attack and starts with 20 HP. Eletric Body - Do 20 damage to any monsters that attacks Biri.\0";
        card->monster->level = 47;
        card->monster->attack = 30;
        card->monster->MaxHP = 40;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Refresh - Recover +10 HP.\0";
        card->lv_acao->nivel = 40;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // BIRI_H_INCLUDED
