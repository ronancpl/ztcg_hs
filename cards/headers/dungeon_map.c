#ifndef DUNGEON_MAP_H_INCLUDED
#define DUNGEON_MAP_H_INCLUDED

void dungeon_map(struct Card *card) {
        card->bmp = al_load_bitmap("cards/dungeon_map.png");
        card->nome = "Dungeon Map\0";
        card->elemento = "Light\0";
        card->colecao = 100;
        card->RARIDADE = 1;
        card->preco = 1870;
        card->tipo = "Equipment\0";
        card->str_concat = "Light - Equipment - Orientation Item\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Improve +10 on all bonus effects of one field on the table. If you do own a field this buff will be applied at your field, or else at the opponents, if there is any.\0";
        card->equip->level = 50;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Rapid Action / Locate 60 - Play a monster or a tactic of level 60 or less or a field.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 1;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // DUNGEON_MAP_H_INCLUDED
