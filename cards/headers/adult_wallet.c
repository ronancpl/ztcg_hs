#ifndef ADULT_WALLET_H_INCLUDED
#define ADULT_WALLET_H_INCLUDED

void adult_wallet(struct Card *card) {
        card->bmp = al_load_bitmap("cards/adult_wallet.png");
        card->nome = "Adult Wallet\0";
        card->elemento = "Wind\0";
        card->colecao = 13;
        card->RARIDADE = 3;
        card->preco = 720;
        card->tipo = "Equipment\0";
        card->str_concat = "Wind - Equipment - Bag\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Whenever you play an equipment, search for an equipment at the top 5 cards of your deck and draw it, then put the other cards at the bottom of your deck at any order.\0";
        card->equip->level = 45;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 80 - Play a monster or an equipment of level 80 or less.\0";
        card->lv_acao->nivel = 70;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // ADULT_WALLET_H_INCLUDED
