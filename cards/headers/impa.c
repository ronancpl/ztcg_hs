#ifndef IMPA_H_INCLUDED
#define IMPA_H_INCLUDED

void impa(struct Card *card) {
        Acao aux;

        card->bmp = al_load_bitmap("cards/impa.png");
        card->nome = "Impa\0";
        card->elemento = "Light\0";
        card->colecao = 8;
        card->RARIDADE = 3;
        card->preco = 970;
        card->tipo = "Character\0";
        card->str_concat = "Light - Character\0";

        card->character = (struct character *)malloc(sizeof(struct character));
        card->character->MaxHP = 280;

        card->character->inicio = (Acao)malloc(sizeof(struct char_action));
        aux = card->character->inicio;
        aux->card = NULL;
        aux->acao = "Mission - Draw a card.\0";
        aux->atrib = 0;
        aux->nivel = 10;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Flash Stab - Do 20 damage to a character or a monster.\0";
        aux->atrib = 2;
        aux->nivel = 40;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Startle - Giving up 30 HP, make a monster unable to attack for 3 turns.\0";
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

#endif // IMPA_H_INCLUDED
