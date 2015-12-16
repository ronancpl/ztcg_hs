#ifndef MOUNTAIN_CLIMBING_H_INCLUDED
#define MOUNTAIN_CLIMBING_H_INCLUDED

void mountain_climbing(struct Card *card) {
        card->bmp = al_load_bitmap("cards/mountain_climbing.png");
        card->nome = "Mountain Climbing\0";
        card->elemento = "Earth\0";
        card->colecao = 75;
        card->RARIDADE = 7;
        card->preco = 925;
        card->tipo = "Tactic\0";
        card->str_concat = "Earth - Tactic - Strategy\0";

        card->tactic = (struct tactic *)malloc(sizeof(struct tactic));
        card->tactic->acao = "Withdraw your character from the battle for one turn. Recover 60 HP, and add +10 damage inflicted by your monsters during the turn this card is activated.\0";
        card->tactic->level = 60;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->character = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 70 - Play a monster or an equipment of level 70 or less.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // MOUNTAIN_CLIMBING_H_INCLUDED
