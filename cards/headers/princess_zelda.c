#ifndef PRINCESS_ZELDA_H_INCLUDED
#define PRINCESS_ZELDA_H_INCLUDED

void princess_zelda(struct Card *card) {     //ja deve vir alocado!
        Acao aux;

        card->bmp = al_load_bitmap("cards/princess_zelda.png");
        card->nome = "Princess Zelda\0";
        card->elemento = "Wind\0";
        card->colecao = 20;
        card->RARIDADE = 3;
        card->preco = 970;
        card->tipo = "Character\0";
        card->str_concat = "Wind - Character\0";

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
        aux->acao = "Gear Up - Play a weapon, a shield or an armor of your level or less.\0";
        aux->atrib = 2;
        aux->nivel = 30;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Magic Blast - Do 10 damage to each of your opponent monsters. Then, do 20 damage to a character.\0";
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

#endif // PRINCESS_ZELDA_H_INCLUDED
