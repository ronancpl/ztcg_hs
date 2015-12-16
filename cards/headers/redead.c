#ifndef REDEAD_H_INCLUDED
#define REDEAD_H_INCLUDED

void redead(struct Card *card) {
        card->bmp = al_load_bitmap("cards/redead.png");
        card->nome = "ReDead\0";
        card->elemento = "Dark\0";
        card->colecao = 124;
        card->RARIDADE = 7;
        card->preco = 480;
        card->tipo = "Monster\0";
        card->str_concat = "Dark - Monster - Undead\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Thrilling Shriek - When you play ReDead destroy up to 2 monsters of level 40 or less, then do fixed damage equals to the sum of their base attack to a character (still can be prevented).\0";
        card->monster->level = 52;
        card->monster->attack = 30;
        card->monster->MaxHP = 20;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action 30 - Play an equipment or a tactic of level 30 or less.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // REDEAD_H_INCLUDED
