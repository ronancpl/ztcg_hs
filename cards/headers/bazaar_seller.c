#ifndef BAZAAR_SELLER_H_INCLUDED
#define BAZAAR_SELLER_H_INCLUDED

void bazaar_seller(struct Card *card) {
        card->bmp = al_load_bitmap("cards/bazaar_seller.png");
        card->nome = "Bazaar Seller\0";
        card->elemento = "Water\0";
        card->colecao = 30;
        card->RARIDADE = 7;
        card->preco = 1050;
        card->tipo = "Monster\0";
        card->str_concat = "Water - Monster - NPC Hylian\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "NPC Quest - Play an equipment with the highest level among these you have equipped (once per turn, and multiple instances of this NPC Quest doesnt proc simultaneously). Reward - Search on your deck for an equipment of lesser level and draw it, then shuffle your deck.\0";
        card->monster->level = 60;
        card->monster->attack = 30;
        card->monster->MaxHP = 40;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip X - Play an equipment of your level or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // BAZAAR_SELLER_H_INCLUDED
