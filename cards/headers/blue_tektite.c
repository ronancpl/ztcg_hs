#ifndef BLUE_TEKTITE_H_INCLUDED
#define BLUE_TEKTITE_H_INCLUDED

void blue_tektite(struct Card *card) {
        card->bmp = al_load_bitmap("cards/blue_tektite.png");
        card->nome = "Blue Tektite\0";
        card->elemento = "Water\0";
        card->colecao = 91;
        card->RARIDADE = 7;
        card->preco = 450;
        card->tipo = "Monster\0";
        card->str_concat = "Water - Monster - Water Spider\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Water Stride - If any Water Field is set on the game (regardless of side), Blue Tektite gets +20 attack and +20 HP.\0";
        card->monster->level = 20;
        card->monster->attack = 10;
        card->monster->MaxHP = 10;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Lesser Monster Resurrection - Get a monster of level 50 or less from your graveyard and play it.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // BLUE_TEKTITE_H_INCLUDED
