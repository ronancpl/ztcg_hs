#ifndef SHABOM_H_INCLUDED
#define SHABOM_H_INCLUDED

void shabom(struct Card *card) {
        card->bmp = al_load_bitmap("cards/shabom.png");
        card->nome = "Shabom\0";
        card->elemento = "Wind\0";
        card->colecao = 94;
        card->RARIDADE = 7;
        card->preco = 710;
        card->tipo = "Monster\0";
        card->str_concat = "Wind - Monster - Bubble\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Squishy - Character actions dont hurt Shabom. Bubble Burst - When Shabom is destroyed, do damage to a character or monster.\0";
        card->monster->level = 34;
        card->monster->attack = 30;
        card->monster->MaxHP = 20;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action 50 - Play an equipment or a tactic of level 50 or less.\0";
        card->lv_acao->nivel = 40;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // SHABOM_H_INCLUDED
