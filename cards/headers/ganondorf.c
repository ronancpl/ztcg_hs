#ifndef GANONDORF_H_INCLUDED
#define GANONDORF_H_INCLUDED

void ganondorf(struct Card *card) {
        Acao aux;

        card->bmp = al_load_bitmap("cards/ganondorf.png");
        card->nome = "Ganondorf\0";
        card->elemento = "Dark\0";
        card->colecao = 109;
        card->RARIDADE = 3;
        card->preco = 970;
        card->tipo = "Character\0";
        card->str_concat = "Dark - Character\0";

        card->character = (struct character *)malloc(sizeof(struct character));
        card->character->MaxHP = 200;

        card->character->inicio = (Acao)malloc(sizeof(struct char_action));
        aux = card->character->inicio;
        aux->card = NULL;
        aux->acao = "Mission - Draw a card.\0";
        aux->atrib = 0;
        aux->nivel = 20;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Warlock Punch - Do 20 damage to a character or monster. If a weapon is equipped, do another 10 damage to a character.\0";
        aux->atrib = 2;
        aux->nivel = 40;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Shadow Leader - Add +10 attack and +20 HP to all your DARK monsters on the field.\0";
        aux->atrib = 3;
        aux->nivel = 60;

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

void desfaz_ganondorf_card(struct CARD *card) {
    if(card != NULL && !strcmp(card->origem->elemento,"Dark")) {
        card->MaxHP = card->MaxHP - 20;
        card->HP = card->HP - 20;
    }
}

void desfaz_ganondorf_effect(struct Player *jogador) {
    desfaz_ganondorf_card(jogador->mesa->monstro1);
    desfaz_ganondorf_card(jogador->mesa->monstro2);
    desfaz_ganondorf_card(jogador->mesa->monstro3);
    desfaz_ganondorf_card(jogador->mesa->monstro4);
    desfaz_ganondorf_card(jogador->mesa->monstro5);
    desfaz_ganondorf_card(jogador->mesa->monstro6);
    desfaz_ganondorf_card(jogador->mesa->monstro7);
}

void ganondorf_card(struct CARD *card) {
    if(card != NULL && !strcmp(card->origem->elemento,"Dark")) {
        printf("proccing ON CARD on '%s'\n",card->origem->nome);
        card->MaxHP = card->MaxHP + 20;
        card->HP = card->HP + 20;
    }
}

void ganondorf_effect(struct Player *jogador) {
    ganondorf_card(jogador->mesa->monstro1);
    ganondorf_card(jogador->mesa->monstro2);
    ganondorf_card(jogador->mesa->monstro3);
    ganondorf_card(jogador->mesa->monstro4);
    ganondorf_card(jogador->mesa->monstro5);
    ganondorf_card(jogador->mesa->monstro6);
    ganondorf_card(jogador->mesa->monstro7);
}

void ganondorf_acao(struct CARD *card,struct Player *player) { //somente ao colocar card em campo.
    if(!strcmp(card->origem->elemento,"Dark") && player->var_tactic->ganondorf_bool == true) {
        card->MaxHP = card->MaxHP + 20;
        card->HP = card->HP + 20;
    }
}

#endif // GANONDORF_H_INCLUDED
