#ifndef HOVER_BOOTS_H_INCLUDED
#define HOVER_BOOTS_H_INCLUDED

void hover_boots(struct Card *card) {
        card->bmp = al_load_bitmap("cards/hover_boots.png");
        card->nome = "Hover Boots\0";
        card->elemento = "Wind\0";
        card->colecao = 132;
        card->RARIDADE = 7;
        card->preco = 1030;
        card->tipo = "Equipment\0";
        card->str_concat = "Wind - Equipment - Shoes\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Once per turn, cancel an opposing attack.\0";
        card->equip->level = 60;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Equip / Rapid Action 60 - Play an equipment or a tactic of level 60 or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}


#endif // HOVER_BOOTS_H_INCLUDED
