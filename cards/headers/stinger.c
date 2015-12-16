#ifndef STINGER_H_INCLUDED
#define STINGER_H_INCLUDED

void stinger(struct Card *card) {
        card->bmp = al_load_bitmap("cards/stinger.png");
        card->nome = "Stinger\0";
        card->elemento = "Water\0";
        card->colecao = 51;
        card->RARIDADE = 7;
        card->preco = 780;
        card->tipo = "Monster\0";
        card->str_concat = "Water - Monster - Fish Monster\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Motion-sense Bioequipped - When you play Stinger, do 20 damage to a character or monster.\0";
        card->monster->level = 45;
        card->monster->attack = 20;
        card->monster->MaxHP = 50;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip 40 - Play an equipment of level 40 or less.\0";
        card->lv_acao->nivel = 20;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // STINGER_H_INCLUDED
