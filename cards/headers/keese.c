#ifndef KEESE_H_INCLUDED
#define KEESE_H_INCLUDED

void keese(struct Card *card) {
        card->bmp = al_load_bitmap("cards/keese.png");
        card->nome = "Keese\0";
        card->elemento = "Wind\0";
        card->colecao = 149;
        card->RARIDADE = 7;
        card->preco = 740;
        card->tipo = "Monster\0";
        card->str_concat = "Wind - Monster - Bat\0";

        card->monster = (struct monster *)malloc(sizeof(struct monster));
        card->monster->acao = "Flying Monster - Monster attacks dont hurt Keese.\0";
        card->monster->level = 30;
        card->monster->attack = 20;
        card->monster->MaxHP = 30;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->equip = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Rapid Action 70 - Play a monster or a tactic of level 70 or less.\0";
        card->lv_acao->nivel = 60;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // KEESE_H_INCLUDED
