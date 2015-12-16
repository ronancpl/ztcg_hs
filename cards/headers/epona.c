#ifndef EPONA_H_INCLUDED
#define EPONA_H_INCLUDED

void epona(struct Card *card) {
        card->bmp = al_load_bitmap("cards/epona.png");
        card->nome = "Epona\0";
        card->elemento = "Wind\0";
        card->colecao = 133;
        card->RARIDADE = 7;
        card->preco = 780;
        card->tipo = "Equipment\0";
        card->str_concat = "Wind - Equipment - Steed\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Once per turn, you can prevent an opposing attack to your character.\0";
        card->equip->level = 53;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip 40 - Play a monster or an equipment of level 40 or less.\0";
        card->lv_acao->nivel = 40;
        card->lv_acao->atrib = 2;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // EPONA_H_INCLUDED
