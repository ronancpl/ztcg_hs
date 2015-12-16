#ifndef HEART_PIECE_H_INCLUDED
#define HEART_PIECE_H_INCLUDED

void heart_piece(struct Card *card) {
        card->bmp = al_load_bitmap("cards/heart_piece.png");
        card->nome = "Heart Piece\0";
        card->elemento = "Light\0";
        card->colecao = 49;
        card->RARIDADE = 7;
        card->preco = 470;
        card->tipo = "Tactic\0";
        card->str_concat = "Light - Tactic - Recovery\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Pick one of these actions: Recover 80 HP OR add +40 HP to your maxHP.\0";
        card->tactic->level = 30;

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

#endif // HEART_PIECE_H_INCLUDED
