#ifndef PRINCESS_RUTO_H_INCLUDED
#define PRINCESS_RUTO_H_INCLUDED

void princess_ruto(struct Card *card) {
        Acao aux;

        card->bmp = al_load_bitmap("cards/princess_ruto.png");
        card->nome = "Princess Ruto\0";
        card->elemento = "Water\0";
        card->colecao = 112;
        card->RARIDADE = 3;
        card->preco = 970;
        card->tipo = "Character\0";
        card->str_concat = "Water - Character\0";

        card->character = (struct character *)malloc(sizeof(struct character));
        card->character->MaxHP = 200;

        card->character->inicio = (Acao)malloc(sizeof(struct char_action));
        aux = card->character->inicio;
        aux->card = NULL;
        aux->acao = "Bubble Shot - Do 10 damage to a character or a monster.\0";
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
        aux->acao = "Swim Mastery - Pick an action under this character and play its effect. The chosen actions requirements must be met.\0";
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

#endif // PRINCESS_RUTO_H_INCLUDED
