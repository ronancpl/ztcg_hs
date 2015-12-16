#ifndef WARP_H_INCLUDED
#define WARP_H_INCLUDED

void warp(struct Card *card) {
        card->bmp = al_load_bitmap("cards/warp.png");
        card->nome = "Warp\0";
        card->elemento = "Light\0";
        card->colecao = 105;
        card->RARIDADE = 7;
        card->preco = 860;
        card->tipo = "Tactic\0";
        card->str_concat = "Light - Tactic - Skill\0";

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
        card->lv_acao->acao = "Equip / Locate 80 - Play an equipment of level 80 or less or a field card.\0";
        card->lv_acao->nivel = 80;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // WARP_H_INCLUDED
