#ifndef PURPLE_RUPEE_H_INCLUDED
#define PURPLE_RUPEE_H_INCLUDED

void purple_rupee(struct Card *card) {
        card->bmp = al_load_bitmap("cards/purple_rupee.png");
        card->nome = "Purple Rupee\0";
        card->elemento = "Water\0";
        card->colecao = 123;
        card->RARIDADE = 3;
        card->preco = 1320;
        card->tipo = "Equipment\0";
        card->str_concat = "Water - Equipment - Cash\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "At the start of your turn peek the top 3 cards of your deck. You may choose play one equipment of your level or less revealed this way and then destroy Purple Rupee. Head the remaining cards to the bottom of your deck at a order of your choice.\0";
        card->equip->level = 25;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip / Locate 90 - Play a monster or an equipment of level 90 or less or a field card.\0";
        card->lv_acao->nivel = 70;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // PURPLE_RUPEE_H_INCLUDED
