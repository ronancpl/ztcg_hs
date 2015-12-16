#ifndef SMALL_KEY_H_INCLUDED
#define SMALL_KEY_H_INCLUDED

void small_key(struct Card *card) {
        card->bmp = al_load_bitmap("cards/small_key.png");
        card->nome = "Small Key\0";
        card->elemento = "Fire\0";
        card->colecao = 57;
        card->RARIDADE = 7;
        card->preco = 800;
        card->tipo = "Tactic\0";
        card->str_concat = "Fire - Tactic - Action\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Look for a card at the next 8 cards of your deck and draw it. Then shuffle your deck.\0";
        card->tactic->level = 25;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 50 - Play a monster or an equipment of level 50 or less.\0";
        card->lv_acao->nivel = 40;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // SMALL_KEY_H_INCLUDED
