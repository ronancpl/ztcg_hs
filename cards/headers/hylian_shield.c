#ifndef HYLIAN_SHIELD_H_INCLUDED
#define HYLIAN_SHIELD_H_INCLUDED

void hylian_shield(struct Card *card) {
        card->bmp = al_load_bitmap("cards/hylian_shield.png");
        card->nome = "Hylian Shield\0";
        card->elemento = "Fire\0";
        card->colecao = 45;
        card->RARIDADE = 7;
        card->preco = 850;
        card->tipo = "Equipment\0";
        card->str_concat = "Fire - Equipment - Shield\0";

        card->equip = (struct equipment *)malloc(sizeof(struct equipment));
        card->equip->acao = "Block 20 damage inflicted to your character by a opponent monster.\0";
        card->equip->level = 45;

        card->boss = NULL;
        card->character = NULL;
        card->field = NULL;
        card->jrboss = NULL;
        card->monster = NULL;
        card->tactic = NULL;

        card->lv_acao = (struct char_action *)malloc(sizeof(struct char_action));
        card->lv_acao->acao = "Drink Potion - Recover HP equals to your level.\0";
        card->lv_acao->nivel = 999;
        card->lv_acao->atrib = 0;

        card->lv_acao->ant = NULL;
        card->lv_acao->prox = NULL;
}

#endif // HYLIAN_SHIELD_H_INCLUDED
