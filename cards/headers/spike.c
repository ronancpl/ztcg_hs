#ifndef SPIKE_H_INCLUDED
#define SPIKE_H_INCLUDED

void spike(struct Card *card) {
        card->bmp = al_load_bitmap("cards/spike.png");
        card->nome = "Spike\0";
        card->elemento = "Water\0";
        card->colecao = 81;
        card->RARIDADE = 7;
        card->preco = 620;
        card->tipo = "Monster\0";
        card->str_concat = "Water - Monster - Spiky Monster\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Poisonous Spikes - Apply 10 DOT to any character or monster targeted by its attack, lasting for 3 turns. Spiky Shield - If it gets destroyed, recover its HP to 10, but it wont attack neither use this effect for one turn.\0";
        card->monster->level = 29;
        card->monster->attack = 20;
        card->monster->MaxHP = 30;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Bubble Shot - Do 10 damage to a character or monster.\0";
        card->lv_acao->nivel = 20;
        card->lv_acao->atrib = 1;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // SPIKE_H_INCLUDED
