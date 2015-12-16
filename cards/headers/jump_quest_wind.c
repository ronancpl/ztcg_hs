#ifndef JUMP_QUEST_WIND_H_INCLUDED
#define JUMP_QUEST_WIND_H_INCLUDED

void jump_quest_wind(struct Card *card) {
        card->bmp = al_load_bitmap("cards/jump_quest_wind.png");
        card->nome = "Jump Quest (Wind)\0";
        card->elemento = "Wind\0";
        card->colecao = 130;
        card->RARIDADE = 1;
        card->preco = 1615;
        card->tipo = "Tactic\0";
        card->str_concat = "Wind - Tactic - Jump Quest\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Flip a coin. If it goes heads, pick a card of your level or less from your deck, then shuffle it. If it goes tails, choose one of your monsters to do 0.5x more damage with its attack (or 1x more damage if it is a WIND monster) this turn.\0";
        card->tactic->level = 40;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Side Quest - Draw a card.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // JUMP_QUEST_WIND_H_INCLUDED
