#ifndef STALFOS_H_INCLUDED
#define STALFOS_H_INCLUDED

void stalfos(struct Card *card) {
        card->bmp = al_load_bitmap("cards/stalfos.png");
        card->nome = "Stalfos\0";
        card->elemento = "Dark\0";
        card->colecao = 144;
        card->RARIDADE = 7;
        card->preco = 690;
        card->tipo = "Monster\0";
        card->str_concat = "Dark - Monster - Undead\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Ancient Shield - Block 20 damage inflicted by a monster whenever it attacks Stalfos.\0";
        card->monster->level = 54;
        card->monster->attack = 20;
        card->monster->MaxHP = 30;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 90 - Play a monster or an equipment of level 90 or less.\0";
        card->lv_acao->nivel = 80;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // STALFOS_H_INCLUDED
