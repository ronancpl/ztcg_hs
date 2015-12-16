#ifndef OCARINA_OF_TIME_H_INCLUDED
#define OCARINA_OF_TIME_H_INCLUDED

void ocarina_of_time(struct Card *card) {
        card->bmp = al_load_bitmap("cards/ocarina_of_time.png");
        card->nome = "Ocarina of Time\0";
        card->elemento = "Light\0";
        card->colecao = 97;
        card->RARIDADE = 3;
        card->preco = 1150;
        card->tipo = "Equipment\0";
        card->str_concat = "Light - Equipment - Ocarina\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Whenever you would draw a card, reveal the top 2 cards of your deck. Pick one of those to your hand. If the other card is a tactic of your level or less, you may play it. If not played, head the remaining card to the bottom of your deck. This effect is usable once per turn, and one instance of Ocarina of Time overrides draw card at a time.\0";
        card->equip->level = 39;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action 60 - Play an equipment or a tactic of level 60 or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // OCARINA_OF_TIME_H_INCLUDED
