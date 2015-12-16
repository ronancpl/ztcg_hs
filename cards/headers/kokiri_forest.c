#ifndef KOKIRI_FOREST_H_INCLUDED
#define KOKIRI_FOREST_H_INCLUDED

void kokiri_forest(struct Card *card) {
        card->bmp = al_load_bitmap("cards/kokiri_forest.png");
        card->nome = "Kokiri Forest\0";
        card->elemento = "Earth\0";
        card->colecao = 15;
        card->RARIDADE = 1;
        card->preco = 1650;
        card->tipo = "Field\0";
        card->str_concat = "Earth - Field - Kokiri Forest\0";

        card->field = (struct field *)malloc(sizeof(struct field));
        card->field->acao = "Add +10 attack and +20 HP to each EARTH monster in battle. Add +20 attack to each character action of a EARTH character. Next, get 50 HP for your character.\0";

        card->boss = NULL;
        card->character = NULL;
        card->equip = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Locate - Play a field card.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // KOKIRI_FOREST_H_INCLUDED
