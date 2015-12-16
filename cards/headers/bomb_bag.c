#ifndef BOMB_BAG_H_INCLUDED
#define BOMB_BAG_H_INCLUDED

void bomb_bag(struct Card *card) {
        card->bmp = al_load_bitmap("cards/bomb_bag.png");
        card->nome = "Bomb Bag\0";
        card->elemento = "Dark\0";
        card->colecao = 82;
        card->RARIDADE = 3;
        card->preco = 1420;
        card->tipo = "Equipment\0";
        card->str_concat = "Dark - Equipment - Bag\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "At the start of your turn, you may stock a monster on the bag. Whenever you stock a monster, draw a card. If you have 3 monsters on the bag, you may destroy randomly one of them. If you do so, pick a monster on the field to get bonus attack this turn equals to half the destroyed monsters attack, then put the other cards on the bottom of your deck.\0";
        card->equip->level = 20;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Shadow Rip - Do 10 damage to a monster. If a monster was destroyed, do this action again with +10 damage to a character or monster instead.\0";
        card->lv_acao->nivel = 70;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // BOMB_BAG_H_INCLUDED
