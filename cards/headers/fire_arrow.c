#ifndef FIRE_ARROW_H_INCLUDED
#define FIRE_ARROW_H_INCLUDED

void fire_arrow(struct Card *card) {
        card->bmp = al_load_bitmap("cards/fire_arrow.png");
        card->nome = "Fire Arrow\0";
        card->elemento = "Fire\0";
        card->colecao = 114;
        card->RARIDADE = 7;
        card->preco = 890;
        card->tipo = "Tactic\0";
        card->str_concat = "Fire - Tactic - Skill\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Do 30 damage to a monster. If this tactic destroyed the target, inflict 20 direct damage to a character for 2 turns. If the target is a WATER monster and it is still alive, destroy it (this wont trigger the DOT effect).\0";
        card->tactic->level = 40;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Lesser Monster Resurrection - Get a monster of level 50 or less from your graveyard and play it.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // FIRE_ARROW_H_INCLUDED
