#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED

void link(struct Card *link) {     //ja deve vir alocado!
        Acao aux;

        link->bmp = al_load_bitmap("cards/link.png");
        link->nome = "Link\0";
        link->elemento = "Earth\0";
        link->colecao = 1;
        link->RARIDADE = 7;
        link->preco = 770;
        link->tipo = "Character\0";
        link->str_concat = "Earth - Character\0";

        link->character = (struct character *)malloc(sizeof(struct character));
        link->character->MaxHP = 280;
        link->character->inicio = (Acao)malloc(sizeof(struct char_action));
        aux = link->character->inicio;

        aux->card = NULL;
        aux->acao = "Thrust - Do 10 damage to a character or a monster.\0";
        aux->atrib = 1;
        aux->nivel = 10;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Mission - Draw a card.\0";
        aux->atrib = 0;
        aux->nivel = 10;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux = aux->prox;
        aux->card = NULL;
        aux->acao = "Summon X - Play a monster of your level or less.\0";
        aux->atrib = 2;
        aux->nivel = 30;

        aux->prox = (Acao)malloc(sizeof(struct char_action));
        aux->prox->prox = NULL;

        link->boss = NULL;
        link->equip = NULL;
        link->field = NULL;
        link->jrboss = NULL;
        link->monster = NULL;
        link->tactic = NULL;

        link->lv_acao = NULL;
}

#endif // LINK_H_INCLUDED
