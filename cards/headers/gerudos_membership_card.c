#ifndef gerudos_membership_card_H_INCLUDED
#define gerudos_membership_card_H_INCLUDED

void gerudos_membership_card(struct Card *card) {
        card->bmp = al_load_bitmap("cards/gerudos_membership_card.png");
        card->nome = "Gerudos Membership Card\0";
        card->elemento = "Wind\0";
        card->colecao = 101;
        card->RARIDADE = 7;
        card->preco = 860;
        card->tipo = "Tactic\0";
        card->str_concat = "Wind - Tactic - Pass\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Destroy all monsters on the field, excluding WIND monsters. During this turn, WIND monsters has its attack improved by 10.\0";
        card->tactic->level = 50;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon 60 - Play a monster of level 60 or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // gerudos_membership_card_H_INCLUDED
