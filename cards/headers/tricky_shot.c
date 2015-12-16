#ifndef TRICKY_SHOT_H_INCLUDED
#define TRICKY_SHOT_H_INCLUDED

void tricky_shot(struct Card *card) {
        card->bmp = al_load_bitmap("cards/tricky_shot.png");
        card->nome = "Tricky Shot\0";

        card->elemento = "Water\0";
        card->colecao = 142;
        card->RARIDADE = 3;
        card->preco = 970;
        card->tipo = "Tactic\0";
        card->str_concat = "Water - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Flip a coin. If you win, peek as many cards as your opponent has monsters on the field. For each card you discard from these you peeked, do 30 damage to a character or monster. Return the remaining cards to the top of the deck and then proceed to draw them.\0";
        card->tactic->level = 40;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Rapid Action 80 - Play a tactic of level 80 or less.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // TRICKY_SHOT_H_INCLUDED
