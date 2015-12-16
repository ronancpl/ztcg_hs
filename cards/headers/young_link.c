#ifndef YOUNG_LINK_H_INCLUDED
#define YOUNG_LINK_H_INCLUDED

void young_link(struct Card *card) {
        Acao aux;

        card->bmp = al_load_bitmap("cards/young_link.png");
        card->nome = "Young Link\0";
        card->elemento = "Wind\0";
        card->colecao = 23;
        card->RARIDADE = 7;
        card->preco = 770;
        card->tipo = "Character\0";
        card->str_concat = "Wind - Character\0";

        card->character = (struct character *)malloc(sizeof(struct character));
        card->character->MaxHP = 200;
        card->character->inicio = (Acao)malloc(sizeof(struct char_action));
        aux = card->character->inicio;

        aux->card = NULL;
        aux->acao = "Equip X - Play an equipment of your level or less.\0";
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
        aux->acao = "Spin Attack - Do 20 damage to a character or monster.\0";
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

#endif // YOUNG_LINK_H_INCLUDED
