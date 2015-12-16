#ifndef HYRULE_CASTLE_H_INCLUDED
#define HYRULE_CASTLE_H_INCLUDED

void hyrule_castle(struct Card *card) {
        card->bmp = al_load_bitmap("cards/hyrule_castle.png");
        card->nome = "Hyrule Castle\0";
        card->elemento = "Light\0";
        card->colecao = 36;
        card->RARIDADE = 3;
        card->preco = 1000;
        card->tipo = "Field\0";
        card->str_concat = "Light - Field - Hyrule Market\0";

        card->field = (struct field *)malloc(sizeof(struct field));
        card->field->acao = "Add +20 attack and +10 HP to each LIGHT monster in game. If your character is a LIGHT character, add +10 attack to each character actions, and block 10 damage for each opponent actions, effects limited up to as many LIGHT cards you have under your character.\0";

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

#endif // HYRULE_CASTLE_H_INCLUDED
