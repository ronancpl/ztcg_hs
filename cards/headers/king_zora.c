#ifndef KING_ZORA_H_INCLUDED
#define KING_ZORA_H_INCLUDED

void king_zora(struct Card *card) {
        Acao aux;

        card->bmp = al_load_bitmap("cards/king_zora.png");
        card->nome = "King Zora\0";
        card->elemento = "Water\0";
        card->colecao = 31;
        card->RARIDADE = 7;
        card->preco = 770;
        card->tipo = "Character\0";
        card->str_concat = "Water - Character\0";

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
        aux->acao = "Equip X - Play a equipment of your level or less.\0";
        aux->atrib = 2;
        aux->nivel = 20;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Wave Blast - Do 20 damage to a monster. Then, do 20 damage to a character.\0";
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

#endif // KING_ZORA_H_INCLUDED
