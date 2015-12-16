#ifndef ANUBIS_H_INCLUDED
#define ANUBIS_H_INCLUDED

void anubis(struct Card *card) {
        card->bmp = al_load_bitmap("cards/anubis.png");
        card->nome = "Anubis\0";
        card->elemento = "Fire\0";
        card->colecao = 33;
        card->RARIDADE = 1;
        card->preco = 1600;
        card->tipo = "Monster\0";
        card->str_concat = "Fire - Monster - Stone Monster\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Toughness - Anubis can only be harmed by a FIRE attack.\0";
        card->monster->level = 38;
        card->monster->attack = 10;
        card->monster->MaxHP = 30;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Locate 50 - Play a monster of level 50 or less or a field.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // ANUBIS_H_INCLUDED
