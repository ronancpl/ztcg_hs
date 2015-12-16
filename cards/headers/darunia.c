#ifndef DARUNIA_H_INCLUDED
#define DARUNIA_H_INCLUDED

void darunia(struct Card *card) {
        Acao aux;

        card->bmp = al_load_bitmap("cards/darunia.png");
        card->nome = "Darunia\0";
        card->elemento = "Fire\0";
        card->colecao = 120;
        card->RARIDADE = 7;
        card->preco = 770;
        card->tipo = "Character\0";
        card->str_concat = "Fire - Character\0";

        card->character = (struct character *)malloc(sizeof(struct character));
        card->character->MaxHP = 240;
        card->character->inicio = (Acao)malloc(sizeof(struct char_action));
        aux = card->character->inicio;

        aux->card = NULL;
        aux->acao = "Mission - Draw a card.\0";
        aux->atrib = 0;
        aux->nivel = 10;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Roar - Get +10 damage on the next attack you do this turn, or +20 instead if got a Weapon.\0";
        aux->atrib = 1;
        aux->nivel = 20;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Goron Barrage - Do 20 damage to a character or monster.\0";
        aux->atrib = 2;
        aux->nivel = 40;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux->prox->prox = NULL;

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = NULL;
}

void darunia_acao(struct Player *jogador) {
    if(!PossuiWeapon(jogador)) jogador->var_tactic->turn_next_attack_bonus += 10;
    else jogador->var_tactic->turn_next_attack_bonus += 20;
}

#endif // DARUNIA_H_INCLUDED
