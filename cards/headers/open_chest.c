#ifndef OPEN_CHEST_H_INCLUDED
#define OPEN_CHEST_H_INCLUDED

void open_chest(struct Card *card) {
        card->bmp = al_load_bitmap("cards/open_chest.png");
        card->nome = "Open Chest\0";
        card->elemento = "Wind\0";
        card->colecao = 71;
        card->RARIDADE = 7;
        card->preco = 680;
        card->tipo = "Tactic\0";
        card->str_concat = "Wind - Tactic - Action\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Pick the next equipment from your deck and draw it, then shuffle your deck.\0";
        card->tactic->level = 40;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Drink Potion - Recover HP equals to your level.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // OPEN_CHEST_H_INCLUDED
