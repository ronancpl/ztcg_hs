#ifndef CRYSTAL_SWITCH_H_INCLUDED
#define CRYSTAL_SWITCH_H_INCLUDED

void crystal_switch(struct Card *card) {
        card->bmp = al_load_bitmap("cards/crystal_switch.png");
        card->nome = "Crystal Switch\0";
        card->elemento = "Fire\0";
        card->colecao = 72;
        card->RARIDADE = 7;
        card->preco = 780;
        card->tipo = "Tactic\0";
        card->str_concat = "Fire - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Draw 2 cards.\0";
        card->tactic->level = 40;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Rapid Action 40 - Play a tactic of level 40 or less.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 1;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // CRYSTAL_SWITCH_H_INCLUDED
