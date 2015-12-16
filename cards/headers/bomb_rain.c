#ifndef BOMB_RAIN_H_INCLUDED
#define BOMB_RAIN_H_INCLUDED

void bomb_rain(struct Card *card) {
        card->bmp = al_load_bitmap("cards/bomb_rain.png");
        card->nome = "Bomb Rain\0";

        card->elemento = "Fire\0";
        card->colecao = 59;
        card->RARIDADE = 1;
        card->preco = 1600;
        card->tipo = "Tactic\0";
        card->str_concat = "Fire - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "If there are none of opponents monsters on the field, do 70 damage to a character. Else, destroy up to 3 monsters on the field.\0";
        card->tactic->level = 70;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Rapid Action 70 - Play a monster or a tactic of level 70 or less.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // BOMB_RAIN_H_INCLUDED
