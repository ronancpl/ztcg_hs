#ifndef LIKELIKE_H_INCLUDED
#define LIKELIKE_H_INCLUDED

void likelike(struct Card *card) {
        card->bmp = al_load_bitmap("cards/likelike.png");
        card->nome = "Like-Like\0";
        card->elemento = "Earth\0";
        card->colecao = 7;
        card->RARIDADE = 3;
        card->preco = 900;
        card->tipo = "Monster\0";
        card->str_concat = "Earth - Monster - Sponge\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Gear-Eating Monster - Whenever Like-Like inflicts damage to a character, destroy an equipment.\0";
        card->monster->level = 59;
        card->monster->attack = 20;
        card->monster->MaxHP = 50;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action 70 - Play an equipment or a tactic of level 70 or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // LIKELIKE_H_INCLUDED
