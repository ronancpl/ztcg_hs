#ifndef DARK_LINK_H_INCLUDED
#define DARK_LINK_H_INCLUDED

void dark_link(struct Card *card) {     //ja deve vir alocado!
        Acao aux;

        card->bmp = al_load_bitmap("cards/dark_link.png");
        card->nome = "Dark Link\0";
        card->elemento = "Dark\0";
        card->colecao = 5;
        card->RARIDADE = 7;
        card->preco = 770;
        card->tipo = "Character\0";
        card->str_concat = "Dark - Character\0";

        card->character = (struct character *)malloc(sizeof(struct character));
        card->character->MaxHP = 280;
        card->character->inicio = (Acao)malloc(sizeof(struct char_action));
        aux = card->character->inicio;

        aux->card = NULL;
        aux->acao = "Silent Stab - Do 10 damage to a character or a monster.\0";
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

        card->boss = NULL;
        card->equip = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = NULL;
}

#endif // DARK_LINK_H_INCLUDED
