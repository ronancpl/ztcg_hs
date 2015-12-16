#ifndef LEEVER_H_INCLUDED
#define LEEVER_H_INCLUDED

void leever(struct Card *card) {
        card->bmp = al_load_bitmap("cards/leever.png");
        card->nome = "Leever\0";
        card->elemento = "Fire\0";
        card->colecao = 89;
        card->RARIDADE = 7;
        card->preco = 500;
        card->tipo = "Monster\0";
        card->str_concat = "Fire - Monster - Worm\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Call - Whenever Leever is destroyed, you may play Giant Leever at the start of your next turn, given that your character is level 50 or more and there is no other Jr. Boss or Boss at your side. Giant Leever gets +30 attack at the turn its played by this effect.\0";
        card->monster->level = 23;
        card->monster->attack = 10;
        card->monster->MaxHP = 30;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 30 - Play a monster or an equipment of level 30 or less.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 1;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // LEEVER_H_INCLUDED
