#ifndef RED_TEKTITE_H_INCLUDED
#define RED_TEKTITE_H_INCLUDED

void red_tektite(struct Card *card) {
        card->bmp = al_load_bitmap("cards/red_tektite.png");
        card->nome = "Red Tektite\0";
        card->elemento = "Earth\0";
        card->colecao = 90;
        card->RARIDADE = 7;
        card->preco = 540;
        card->tipo = "Monster\0";
        card->str_concat = "Earth - Monster - Ground Spider\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "\0";
        card->monster->level = 30;
        card->monster->attack = 30;
        card->monster->MaxHP = 20;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Rapid Action 40 - Play a monster or a tactic of level 40 or less.\0";
        card->lv_acao->nivel = 30;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // RED_TEKTITE_H_INCLUDED
