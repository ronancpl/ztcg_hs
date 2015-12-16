#ifndef CHEST_H_INCLUDED
#define CHEST_H_INCLUDED

void chest(struct Card *card) {
        card->bmp = al_load_bitmap("cards/chest.png");
        card->nome = "Chest\0";
        card->elemento = "Wind\0";
        card->colecao = 110;
        card->RARIDADE = 3;
        card->preco = 1020;
        card->tipo = "Equipment\0";
        card->str_concat = "Wind - Equipment - Chest\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "At the start of your character actions phase, you may stock a equipment on Chest (full on 2). Whenever it becomes full after a stock, draw a card. Regardless, you may then get one equipment stocked at previous turns. Each equipment can be stocked only one time.\0";
        card->equip->level = 10;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Hurricane - Do 20 damage to a character or monster. If you destroyed a monster this way, do this action again.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // CHEST_H_INCLUDED
