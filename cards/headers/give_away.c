#ifndef GIVE_AWAY_H_INCLUDED
#define GIVE_AWAY_H_INCLUDED

void give_away(struct Card *card) {
        card->bmp = al_load_bitmap("cards/give_away.png");
        card->nome = "Give Away\0";
        card->elemento = "Water\0";
        card->colecao = 68;
        card->RARIDADE = 7;
        card->preco = 830;
        card->tipo = "Tactic\0";
        card->str_concat = "Water - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Destroy an equipment.\0";
        card->tactic->level = 30;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Tidal Strike - Get x10 damage for each WATER card under your character, shared between all your WATER monsters attacks. Bonuses are rounded to the ceiling 10.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // GIVE_AWAY_H_INCLUDED
