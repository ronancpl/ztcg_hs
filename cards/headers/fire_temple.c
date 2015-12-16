#ifndef FIRE_TEMPLE_H_INCLUDED
#define FIRE_TEMPLE_H_INCLUDED

void fire_temple(struct Card *card) {
        card->bmp = al_load_bitmap("cards/fire_temple.png");
        card->nome = "Fire Temple\0";
        card->elemento = "Fire\0";
        card->colecao = 137;
        card->RARIDADE = 3;
        card->preco = 1000;
        card->tipo = "Field\0";
        card->str_concat = "Fire - Field - Fire Temple\0";

        card->field = (struct field *)malloc(sizeof(struct field));
        card->field->acao = "Add +20 attack and +10 HP to each FIRE monster in game. If your character is a FIRE character, add +10 attack to each character actions, and block 10 damage for each opponent actions, effects limited up to as many FIRE cards you have under your character.\0";

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

#endif // FIRE_TEMPLE_H_INCLUDED
