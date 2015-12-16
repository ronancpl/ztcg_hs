#ifndef LAKE_HYLIA_H_INCLUDED
#define LAKE_HYLIA_H_INCLUDED

void lake_hylia(struct Card *card) {
        card->bmp = al_load_bitmap("cards/lake_hylia.png");
        card->nome = "Lake Hylia\0";
        card->elemento = "Water\0";
        card->colecao = 37;
        card->RARIDADE = 1;
        card->preco = 1650;
        card->tipo = "Field\0";
        card->str_concat = "Water - Field - Lake Hylia\0";

        card->field = (struct field *)malloc(sizeof(struct field));
        card->field->acao = "Add +10 attack and +20 HP to each WATER monster in battle. Add +20 attack to each character action of a WATER character. Next, get 50 HP for your character.\0";

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

#endif // LAKE_HYLIA_H_INCLUDED
