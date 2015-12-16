#ifndef NABOORU_H_INCLUDED
#define NABOORU_H_INCLUDED

void nabooru(struct Card *card) {
        Acao aux;

        card->bmp = al_load_bitmap("cards/nabooru.png");
        card->nome = "Nabooru\0";
        card->elemento = "Fire\0";
        card->colecao = 32;
        card->RARIDADE = 3;
        card->preco = 970;
        card->tipo = "Character\0";
        card->str_concat = "Fire - Character\0";

        card->character = (struct character *)malloc(sizeof(struct character));
        card->character->MaxHP = 240;
        card->character->inicio = (Acao)malloc(sizeof(struct char_action));
        aux=card->character->inicio;

        aux->card = NULL;
        aux->acao = "Mission - Draw a card.\0";
        aux->atrib = 0;
        aux->nivel = 20;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Crafty 50 - Play a card of level 50 or less.\0";
        aux->atrib = 3;
        aux->nivel = 50;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Gerudo Assault - Do 40 damage to a character.\0";
        aux->atrib = 2;
        aux->nivel = 70;

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

#endif // NABOORU_H_INCLUDED
