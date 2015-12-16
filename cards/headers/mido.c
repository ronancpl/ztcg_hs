#ifndef MIDO_H_INCLUDED
#define MIDO_H_INCLUDED

void mido(struct Card *card) {     //ja deve vir alocado!
        Acao aux;

        card->bmp = al_load_bitmap("cards/mido.png");
        card->nome = "Mido\0";
        card->elemento = "Earth\0";
        card->colecao = 61;
        card->RARIDADE = 3;
        card->preco = 970;
        card->tipo = "Character\0";
        card->str_concat = "Earth - Character\0";

        card->character = (struct character *)malloc(sizeof(struct character));
        card->character->MaxHP = 240;
        card->character->inicio = (Acao)malloc(sizeof(struct char_action));
        aux = card->character->inicio;

        aux->card = NULL;
        aux->acao = "Headbutt - Do 10 damage to a character or a monster.\0";
        aux->atrib = 1;
        aux->nivel = 10;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Mission - Draw a card.\0";
        aux->atrib = 0;
        aux->nivel = 20;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Fairy PowerUP - Add +20 on damage with all your EARTH monster attacks.\0";
        aux->atrib = 3;
        aux->nivel = 50;

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

#endif // MIDO_H_INCLUDED
