#ifndef FAIRY_BOW_H_INCLUDED
#define FAIRY_BOW_H_INCLUDED

void fairy_bow(struct Card *card) {
        card->bmp = al_load_bitmap("cards/fairy_bow.png");
        card->nome = "Fairy Bow\0";
        card->elemento = "Wind\0";
        card->colecao = 150;
        card->RARIDADE = 7;
        card->preco = 760;
        card->tipo = "Equipment\0";
        card->str_concat = "Wind - Equipment - Weapon\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Get +10 on damage you do with all your character actions each turn.\0";
        card->equip->level = 37;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Summon / Equip / Rapid Action 40 - Play a monster, an equipment or a tactic of level 40 or less.\0";
        card->lv_acao->nivel = 50;
        card->lv_acao->atrib = 3;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // FAIRY_BOW_H_INCLUDED
