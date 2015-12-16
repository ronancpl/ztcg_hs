#ifndef DEKU_SEEDS_BAG_H_INCLUDED
#define DEKU_SEEDS_BAG_H_INCLUDED

void deku_seeds_bag(struct Card *card) {
        card->bmp = al_load_bitmap("cards/deku_seeds_bag.png");
        card->nome = "Deku Seeds Bag\0";
        card->elemento = "Earth\0";
        card->colecao = 46;
        card->RARIDADE = 3;
        card->preco = 1230;
        card->tipo = "Equipment\0";
        card->str_concat = "Earth - Equipment - Bag\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "At the start of your character actions, you may put the top card of your deck face-down under Deku Seeds Bag. When you have 3 cards under it, pick one of these actions.                                                              - Do damage equals to the highest card level rounded by the nearest 10 to a character.                           - Do damage equals to the middle-leveled card rounded by the nearest 10 to each of your opponents monsters. Then, put these cards on the bottom of your deck at any order. If the deck is empty, draw all the cards under this one.\0";
        card->equip->level = 45;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Mortal Strike - For each monster on field, do x20 damage to a character or monster. Flip a coin. If you win, this attack can’t be prevented.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // DEKU_SEEDS_BAG_H_INCLUDED
