#ifndef COMPASS_H_INCLUDED
#define COMPASS_H_INCLUDED

void compass(struct Card *card) {
        card->bmp = al_load_bitmap("cards/compass.png");
        card->nome = "Compass\0";
        card->elemento = "Dark\0";
        card->colecao = 84;
        card->RARIDADE = 3;
        card->preco = 1010;
        card->tipo = "Equipment\0";
        card->str_concat = "Dark - Equipment - Orientation Item\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Whenever you play a card, reveal the top card of your deck. If this card type matches with the one played, draw this card. Compass effect can be used only once per turn.\0";
        card->equip->level = 60;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Rapid Action / Locate 60 - Play a monster or a tactic of level 60 or less or a field.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // COMPASS_H_INCLUDED
